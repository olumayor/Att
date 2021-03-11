#include "comm.h"
#include "RF24/nRF24L01.h"
#include "RF24/RF24.h"
#include <QDebug>

#define PIN_CE 17 // (chip enable)
#define PIN_CSN 8 // (chip select not)
//QThread::requestInteruption

comm::comm(QObject *parent)
    : QThread(parent)
{
    dataOn = false;
    pipeNumber = 1;
    radio = new RF24(PIN_CE, PIN_CSN); // create a radio object
    radio->begin();
    radio->setChannel(5); // data transmission channel (from 0 to 125), 5 - at a frequency of 2.405 GHz
    radio->setPALevel(RF24_PA_MAX); // signal gain level (RF24_PA_MIN = -18dBm, RF24_PA_LOW = -12dBm, RF24_PA_HIGH = -6dBm, RF24_PA_MAX = 0dBm)
    radio->setDataRate(RF24_1MBPS); // data transfer rate (RF24_250KBPS, RF24_1MBPS, RF24_2MBPS), RF24_1MBPS - 1Mbps
    radio->openReadingPipe(1, 0x7878787879LL); // open the pipe with the address 0x7878787878LL to receive data (there can be pipes 0 - 5 in total)

    radio->enableAckPayload(); // we allow to place user data in the acknowledgment packet
    radio->setAutoAck(true); // we allow sending to the transmitter a packet of acknowledgment of its data reception on all pipes (true by default)

    radio->enableDynamicPayloads();// allow dynamically resized payload size on all pipes (max 32 bytes)

    radio->printDetails(); // module configuration output
    radio->startListening(); // turn on the receiver, start listening to open pipes
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
            QString receivedData;

            // We read the received data into the payload array specifying the size of this array in bytes
            radio->read(&payload, payloadSize);

            receivedData = QString::fromLocal8Bit(payload, payloadSize);
            emit setMessage(receivedData);
            if(!dataOn)
            {
                if(receivedData == "ST")
                {
                    store.clear();
                    store.append("Z");
                    dataOn = true;
                    emit setMessage("Receiving data");
                }

            }else{
                if(receivedData == "END")
                {
                    //Process store
                    store.remove(0, 1);

                    dataOn = false;
                    emit setMessage("Data received");
                }
                //convert payload to QByteArray
                QByteArray ba = QByteArray::fromRawData(payload, payloadSize);
                store.append(ba);
            }


            //cout << "Pipe number : " << (int) pipeNumber << " ";
            //cout << "Payload size : " << (int) payloadSize << " ";
            //cout << "Data: " << receivedData << endl;

            char ackData[] = "Data from buffer";

            // We put data in the FIFO buffer. As soon as the packet is received, the data from the buffer
            // will be sent to this transmitter along with an acknowledgment packet of its data
            radio->writeAckPayload(0, &ackData, sizeof(ackData));
        }
    }
}
