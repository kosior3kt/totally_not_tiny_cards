//
// Created by JK on 11/06/2022.
//

#include "dataBase.h"


 void *dataBase::mysql_connection_setup() {
    MYSQL *connection = mysql_init(nullptr);
    if(!mysql_real_connect(connection, "localhost", "jk", "@1488#", "mysql_tuts", 0, nullptr, 0)){
        std::cout<<"connection setup failed";
        exit(1);
    }
    dataBase::con = connection;
}

MYSQL_RES *dataBase::mysql_execute_querry(const char *sql_query) const {
    if(mysql_query( con, sql_query)){
        std::cout<<"executing querry failed, for some unknown reason… \n";
        exit(420);
    }
    return mysql_use_result(con);
}


dataBase::dataBase() {
    mysql_connection_setup();
}

