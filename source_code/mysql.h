#ifndef MYSQL_H
#define MYSQL_H
#include <QString>

class mysql
{
public:
    mysql();
private:
    qlonglong db_Id;
    QString db_firstname;
    QString db_lastname;
    QString db_email;
    QString db_address;
    qlonglong db_numberPhone;
    qlonglong db_cuit;
    QString db_comment;
    qlonglong db_date;
};

#endif // MYSQL_H
