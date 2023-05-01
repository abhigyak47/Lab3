#include <mariadb/conncpp.hpp>
#include <string>
using namespace std;

#ifndef PIZZAENTRY_H
#define PIZZAENTRY_H

class pizzaEntry {
public:
     pizzaEntry();
     pizzaEntry(sql::SQLString ID, sql::SQLString Name, sql::SQLString Address, sql::SQLString Rating);
     string text();
     string json();
     
  string ID;
  string Name;
  string Address;
  string Rating;;

private:

};

#endif /* PIZZAENTRY_H */
