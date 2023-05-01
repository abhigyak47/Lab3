#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
/* uncomment for applications that use vectors */
#include <vector>

#include <mariadb/conncpp.hpp>

#include "pizzaEntry.h"

#ifndef PIZZADB_H
#define PIZZADB_H

#define DB_URL "jdbc:mariadb://localhost:3306/kenyon"
#define USER "kenyon"
#define PASS "GambierOwls"

using namespace std;

class pizzaDB {
public:
    pizzaDB();
    vector<pizzaEntry> find(string search);
    pizzaEntry fetchEntry(string idnum);
    void addEntry(string name, string address, string rating);
    void editEntry(string idnum, string name,string nddress,string rating);
    void deleteEntry(string idnum);
private:
    const string db_url=DB_URL;
    const string user=USER;
    const string pass=PASS;
    sql::Driver* driver;
    sql::Properties properties;
    std::unique_ptr<sql::Connection> conn;

};

#endif /* PIZZADB_H */
