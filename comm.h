#ifndef COMM_H
#define COMM_H
#include <QThread>

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

public:
    comm(QObject *parent = 0);
    void run();

signals:
    void setMessage(QString);
};

#endif // COMM_H
