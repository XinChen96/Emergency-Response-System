#ifndef CLIENT_H
#define CLIENT_H
#include <QObject>
#include <QtNetwork>
#include <iostream>

class Client : public QTcpSocket
{
    Q_OBJECT
public:
    Client(QObject *parent = 0);
    ~Client() {}

public slots:
    void request_new_msg(int);
    QString get_msg();

private:
    QString new_message;
};

#endif // CLIENT_H
