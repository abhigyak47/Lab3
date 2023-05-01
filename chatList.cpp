#include <iostream>
#include <fstream>
#include <string>
#include <map>

#include "httplib.h"
#include "pizzaDB.h"
#include "pizzaEntry.h"

int main() {
  pizzaDB pdb;
  
  vector<pizzaEntry> results;

  results = pdb.find("");

  for (int i = 0; i<results.size(); i++) {
    cout << results[i].text() << endl;
  }
}
