#include "comm.h"
#include "RF24/nRF24L01.h"
#include "RF24/RF24.h"
#include <QDebug>
#include <QSerialPort>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QTimer>
#include <QDateTime>

#define PIN_CE 17 // (chip enable)
#define PIN_CSN 8 // (chip select not)
//QThread::requestInteruption

comm::comm(QObject *parent)
    : QThread(parent)
{
    dataOn = false;
    cardPort = new QSerialPort();
    cardPort->setReadBufferSize(0);
    connect(cardPort, SIGNAL(readyRead()), this, SLOT(readCard()));

    dbFile.setFileName("db.db");
    dbConnected = false;
    dbInUse = false;
    classStarted = false;

    const QString DRIVER("QSQLITE");
    if(QSqlDatabase::isDriverAvailable(DRIVER))
    {
        db = QSqlDatabase::addDatabase(DRIVER);
        db.setDatabaseName("db.db");
    }

    if(openPort("/dev/serial0"))
        emit setMessage("Port connected");
    else
        emit setMessage("Port Error");

    dbTimer = new QTimer();
    connect(dbTimer, SIGNAL(timeout()), this, SLOT(updateDb()));

    pipeNumber = 1;
    radio = new RF24(PIN_CE, PIN_CSN); // create a radio object
    radio->begin();
    radio->setChannel(5); // data transmission channel (from 0 to 125), 5 - at a frequency of 2.405 GHz
    radio->setPALevel(RF24_PA_MAX); // signal gain level (RF24_PA_MIN = -18dBm, RF24_PA_LOW = -12dBm, RF24_PA_HIGH = -6dBm, RF24_PA_MAX = 0dBm)
    radio->setDataRate(RF24_1MBPS); // data transfer rate (RF24_250KBPS, RF24_1MBPS, RF24_2MBPS), RF24_1MBPS - 1Mbps
    radio->openWritingPipe(0x7878787878LL);
    radio->openReadingPipe(1, 0x7878787879LL); // open the pipe with the address 0x7878787878LL to receive data (there can be pipes 0 - 5 in total)

    radio->enableAckPayload(); // we allow to place user data in the acknowledgment packet
    radio->setAutoAck(true); // we allow sending to the transmitter a packet of acknowledgment of its data reception on all pipes (true by default)

    radio->enableDynamicPayloads();// allow dynamically resized payload size on all pipes (max 32 bytes)

    radio->printDetails(); // module configuration output
    radio->startListening(); // turn on the receiver, start listening to open pipes


    dbTimer->start(1700);
}

void comm :: run()
{
    while(!isInterruptionRequested())
    {
        // If there are received data in the buffer, then we transfer the address of the variable (must be of the uint8_t type)
        // in which you want to place the pipe number for which the data was received
        if (radio->available(&pipeNumber)) {
        
            payloadSize = radio->getDynamicPayloadSize(); // get the size of the received payload
            char payload[payloadSize];
            // We read the received data into the payload array specifying the size of this array in bytes
            radio->read(&payload, payloadSize);

            if(!dataOn)
            {
                QString strData;
                strData = QString::fromLocal8Bit(payload, payloadSize);
                if(strData.contains("ST%") && strData.contains("%ED"))
                {
                    QStringList x = strData.split("%");
                    if(x.length() == 4)
                    {
                        QString act = QString(x.at(1));
                        int ln = QString(x.at(2)).toInt();

                        if(act == "SET" && ln > 0)
                        {
                            //New data in
                            dataSize = ln;
                            dataOn = true;
                            recvd = 0;

                            db.close();
                            dbInUse = true;
                            dbFile.open(QFile::WriteOnly | QFile::Truncate);
                            dbFile.close();
                            dbFile.open(QFile::WriteOnly | QFile::Append);

                            emit setMessage("Receiving data: " + QString::number(dataSize));
                            continue;
                        }

                        if(act == "GET")
                        {
                            //Send database back ...

                        }
                    }
                }
            }

            if(dataOn && recvd < dataSize)
            {
                //convert payload to QByteArray
                recvd += payloadSize;
                QByteArray ba = QByteArray::fromRawData(payload, payloadSize);
                dbFile.write(ba);
                //store.append(ba);
                emit setMessage("Received: " + QString::number(recvd));
                continue;
            }

            if(dataOn && recvd == dataSize)
            {
                QString strData;
                strData = QString::fromLocal8Bit(payload, payloadSize);
                if(strData.contains("ST%") && strData.contains("%ED"))
                {
                    QStringList x = strData.split("%");
                    if(x.length() == 3)
                    {
                        int ln = QString(x.at(1)).toInt();
                        if(ln == recvd)
                        {
                            //New data in
                            dbFile.close();
                            dbInUse = false;

                            dataSize = 0;
                            dataOn = false;
                            recvd = 0;
                            emit setMessage("Done");
                            continue;
                        }
                    }
                }
            }

            char ackData[] = "DR";
            // We put data in the FIFO buffer. As soon as the packet is received, the data from the buffer
            // will be sent to this transmitter along with an acknowledgment packet of its data
            radio->writeAckPayload(0, &ackData, sizeof(ackData));
        }
    }
}

bool comm :: openPort(const QString& cport)
{
    if(cardPort->isOpen())
        cardPort->close();

    cardPort->setDataBits(QSerialPort::Data8);
    cardPort->setParity(QSerialPort::NoParity);
    cardPort->setBaudRate(9600);
    cardPort->setPortName(cport);

    if(cardPort->open(QIODevice::ReadOnly))
        return true;
    return false;
}

void comm :: readCard()
{
    cardData += cardPort->readAll();

    if(cardData.endsWith("\n"));
    {
        QString card = QString(cardData);
        card = card.remove("\r\n");
        cardData.clear();
        if(classStarted && !dbInUse && db.isOpen())
        {
            QSqlQuery query;
       // qDebug() << card;
            query.exec(QString("SELECT sName, sID, sPassport FROM '%1' WHERE sCardID='%2' ").arg(currentTable).arg(card));

        if(query.next())
            {
                if(query.record().count() == 3)
                {
                    QString name = query.record().value(0).toString();
                    QString id = query.record().value(1).toString();
                    QByteArray pasp = query.record().value(2).toByteArray();
                    emit clockStudent(name, id, pasp, "Success");
                }else{
                    emit clockStudent("", card, QByteArray(), "Error");
                }
            }else{
                emit clockStudent("", card, QByteArray(), "Not registered");
            }
        }else{
            emit clockStudent("", card, QByteArray(), "No Class");
        }
    }
}

void comm :: closePort()
{
    cardPort->close();
}

void comm :: updateDb()
{
    if(dbInUse)
        return;

    if(!db.isOpen())
    {
        db.open();
        if(!db.isOpen());
        else{
            QSqlQuery query; //Start new SQL query to be executed
            query.exec("SELECT name FROM sqlite_master WHERE type='table';");
            if( query.next() )
            {
                QSqlRecord record = query.record();
                currentTable = record.value(0).toString();
                QStringList l = record.value(0).toString().split("%");
                if(l.length() == 2)
                {
                    emit setCurClass(l.at(0));
                    emit setCurSess(l.at(1));
                    dbConnected = true;
                }else
                    db.close();
            }else
                db.close();
        }
    }else{
        QSqlQuery query;
        if(query.exec(QString("SELECT sDT, cDuration, cInstructor FROM '%1'").arg(currentTable)))
       ;// emit message("Select success");
        else
        ;//emit message("Select failed");
        if(query.next())
        {
            QString cTime = query.record().value(0).toString();
        //emit message(cTime);
            int duration = query.record().value(1).toInt();
            QString cInstr = query.record().value(2).toString();
            if(QDateTime::fromString(cTime, "MM/dd/yyyy h:mm AP") <= QDateTime::currentDateTime() && QDateTime::fromString(cTime, "MM/dd/yyyy h:mm AP").addSecs(60 * 60 * duration) > QDateTime::currentDateTime())
            {
                if(!classStarted)
                {
                    QString cCourse = currentTable.split("%").at(0);
                    emit startNewClass(cInstr, cCourse, cTime, duration);
                    classStarted = true;
                }

            }else{
                if(classStarted)
                {
                    emit startNewClass("", "", "", 0);
                }
                classStarted = false;
            }
        }
    }
}
