#ifndef SERVER_H
#define SERVER_H
#include <QtNetwork>
#include <QObject>

class Server : public QObject {
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);

public slots:
    void print_something();

private:
    QTcpServer *server = nullptr;

};

#endif // SERVER_H
