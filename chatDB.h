#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
/* uncomment for applications that use vectors */
#include <vector>

#include <mariadb/conncpp.hpp>

#include "userEntry.h"

#ifndef USERDB_H
#define USERDB_H

#define DB_URL "jdbc:mariadb://localhost:3306/chat"
#define USER "root"
#define PASS "Altri@@12345"

using namespace std;

class chatDB {
public:
    chatDB();
    vector<chatEntry> find(string search);
    pizzaEntry fetchEntry(string idnum);
    void addEntry(string user, string email, string pass);
    void editEntry(string idnum, string user,string email,string pass);
    void deleteEntry(string idnum);
private:
    const string db_url=DB_URL;
    const string user=USER;
    const string pass=PASS;
    sql::Driver* driver;
    sql::Properties properties;
    std::unique_ptr<sql::Connection> conn;

};

#endif /* CHATDB_H */
