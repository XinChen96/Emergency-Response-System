#ifndef CLIENTTHREAD_H
#define CLIENTTHREAD_H

#include <QThread>
#include <QMutex>
#include <QWaitCondition>
#include <QtNetwork>
#include <iostream>

class ClientThread : public QThread
{
    Q_OBJECT
public:
    ClientThread(QObject *parent = 0);
    ~ClientThread();
    void request_new_msg(QString, int);
    void run() override;

signals:
    void new_msg(const QString&);

private:
    QHostAddress host_name;
    int port;
    QMutex mutex;
    QWaitCondition cond;
    bool quit;

};

#endif // CLIENTTHREAD_H
