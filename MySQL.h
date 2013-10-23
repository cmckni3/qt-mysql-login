/* 
 * File:   MySQL.h
 * Author: Chris
 *
 * Created on March 26, 2011, 9:42 PM
 */

#ifndef MYSQL_H
#define	MYSQL_H

#include <QtGui/QApplication>
#include <QtGui/QMessageBox>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <iostream>

class MySQL
{
public:
    MySQL();
    ~MySQL();
    bool query(QString username, QString password);
private:
    char dbhost[256];
    char dbuser[256];
    char dbpass[256];
    char dbname[256];
};

#endif	/* MYSQL_H */

