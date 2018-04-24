#ifndef CLIENT_H
#define CLIENT_H
#include <QtNetwork>
#include <QObject>

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = nullptr);
    ~Client() {}

public slots:
    void read_message();
    void request_new_message();
    void display_error(QAbstractSocket::SocketError);

private:
    QTcpSocket *socket = nullptr;
    QDataStream in;
    QString current_message;
};

#endif // CLIENT_H
