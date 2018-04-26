#ifndef CLIENT_H
#define CLIENT_H
#include "clientthread.h"
#include <QObject>
#include <iostream>

class Client : public QObject
{
    Q_OBJECT
public:
    Client(QObject *parent = 0);
    ~Client() { }

public slots:
    void request_new_msg();
    void change_msg(const QString&);

private:
    ClientThread ct;
    QString msg;
};

#endif // CLIENT_H
