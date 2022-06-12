//
// Created by JK on 11/06/2022.
//

#ifndef PJC_NOWE_DATABASE_H
#define PJC_NOWE_DATABASE_H

#include "mysql/mysql.h"
#include "/opt/homebrew/Cellar/mysql-connector-c++/8.0.29/include/mysqlx/devapi/result.h"

#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>

class dataBase {
public:

    void *mysql_connection_setup();
    MYSQL_RES* mysql_execute_querry(const char *sql_query);
    dataBase();

    MYSQL* con;
    MYSQL_RES* res;
    MYSQL_ROW row;

};


#endif //PJC_NOWE_DATABASE_H
