#ifndef COMM_H
#define COMM_H
#include <QThread>
#include <QFile>

class QSerialPort;
class QTimer;
#include <QSqlDatabase>
#include <QSqlQueryModel>

class RF24;
class comm
        : public QThread
{
    Q_OBJECT

private:
    RF24 *radio;
    uint8_t pipeNumber;
    uint8_t payloadSize;
    QByteArray store;
    int dataSize{0}, recvd{0};
    bool dataOn{false};

    QFile dbFile;
    QSqlDatabase db;
    QByteArray cardData;
    QString currentTable;
    bool dbConnected;
    bool dbInUse;
    bool classStarted;
    QTimer *timer;
    QTimer *dbTimer;

    QSerialPort *cardPort;
    bool openPort(const QString&);
    void closePort();

public:
    comm(QObject *parent = 0);
    void run();

signals:
    void setMessage(QString);
    void newCard(QString);
    void message(QString);
    void setCurSess(QString);
    void setCurClass(QString);
    void startNewClass(QString instructor, QString course, QString dateTime, int dur);
    void clockStudent(QString name, QString id, QByteArray pasp, QString status);

private slots:
    void readCard();
    void updateDb();

};

#endif // COMM_H
