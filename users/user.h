#ifndef USER_H
#define USER_H


class User {
public:
    User(QString, QString);
    ~User();

protected:
    QString first_name;
    QString last_name;
    int id;
};

#endif // USER_H
