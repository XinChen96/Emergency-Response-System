#ifndef SERVER_H
#define SERVER_H
#include <QtNetwork>
#include <QObject>
#include <iostream>

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);

public slots:
    // void session_opened();
    void send_msg();

private:
    QTcpServer *server = nullptr;
};

#endif // SERVER_H
