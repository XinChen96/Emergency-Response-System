#ifndef CLIENTTHREAD_H
#define CLIENTTHREAD_H
#include <QTcpSocket>
#include <QDataStream>
#include <QByteArray>
#include <iostream>
#include "../db/db_manager.h"
#include "../db/instructions_db.h"
#include "../users/instruction.h"

class ClientThread : public QTcpSocket {
Q_OBJECT
public:
    explicit ClientThread(QTcpSocket *sock = nullptr, QObject *parent = 0);

signals:
    void group_received();

public slots:
    void receive_group();
    void connected();
    void send_msg();

private:
    int group_id = 0;
    DB_Manager *db = nullptr;
    QString db_path;
};

#endif // CLIENTTHREAD_H
