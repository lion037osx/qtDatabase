#ifndef CLIENT_H
#define CLIENT_H
#include <QString>

class Client
{

public:
    Client();
    ~Client();
private:
    qlonglong Id;
    QString firstname;
    QString lastname;
    QString email;
    QString address;
    qlonglong numberPhone;
    qlonglong cuit;
    QString comment;
    qlonglong date;
};

#endif // CLIENT_H
