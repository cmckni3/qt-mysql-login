#ifndef MYSQL_CPP
#define	MYSQL_CPP

#include "MySQL.h"

MySQL::MySQL()
{
}

MySQL::~MySQL()
{
    //this->close();
}

bool MySQL::query(QString username, QString password)
{
    bool ret = false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setPort(8889);
    db.setDatabaseName("test");
    db.setUserName("root");
    db.setPassword("root");

    if (!db.open())
    {
        QMessageBox::critical(0, QObject::tr("Database Error"),
                              db.lastError().text());
    }
    else
    {
        QSqlQuery query;
        QString q = "SELECT username, password FROM users WHERE username='" + username + "';";
        query.exec(q);

        while (query.next())
        {
            QString user = query.value(0).toString();
            QString pass = query.value(1).toString();
            std::cerr << qPrintable(user) << ": " << qPrintable(pass) << std::endl;
            if (user == username && pass == password)
                ret = true;
        }
        db.close();
    }

    return ret;
}

#endif