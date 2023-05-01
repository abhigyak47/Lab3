#include <vector>
#include <iostream>
#include <mariadb/conncpp.hpp>
#include "pizzaDB.h"
#include "pizzaEntry.h"



pizzaDB::pizzaDB() {
  	// Instantiate Driver
  	driver = sql::mariadb::get_driver_instance();
  	
 	// Configure Connection
  	// The URL or TCP connection string format is
  	// ``jdbc:mariadb://host:port/database``.
  	sql::SQLString url(db_url);

    // Use a properties map for the other connection options
  	sql::Properties my_properties({{"user", user}, {"password",pass}});
  	// Save properties in object
  	properties = my_properties;

    // Establish Connection
  	std::unique_ptr<sql::Connection> my_conn(driver->connect(db_url, properties));
    
    // Check success
    if (!my_conn) {
   		cerr << "Invalid database connection" << endl;
   		exit (EXIT_FAILURE);
   	}	
   	
   	// Save connection in object
   	conn = std::move(my_conn);
   	
}

vector<pizzaEntry> pizzaDB::find(string search) {

	vector<pizzaEntry> list;
    
    // Make sure the connection is still valid
    if (!conn) {
   		cerr << "Invalid database connection" << endl;
   		exit (EXIT_FAILURE);
   	}	
    // Create a new Statement
	std::unique_ptr<sql::Statement> stmnt(conn->createStatement());
    
    // Execute query
    sql::ResultSet *res = stmnt->executeQuery(
			"SELECT * FROM pizza WHERE Name like '%"+search+"%' OR "+
    		 + "Address like '%"+search+"%'");
    
    // Loop through and print results
    while (res->next()) {
    	pizzaEntry entry(res->getString("ID"),res->getString("Name"),
			res->getString("Address"),res->getString("Rating"));
	    list.push_back(entry);

    }
    return list;

}

void pizzaDB::addEntry(string name,string address,string rating){

	if (!conn) {
   		cerr << "Invalid database connection" << endl;
   		exit (EXIT_FAILURE);
  	}

  	std::auto_ptr<sql::Statement> stmnt(conn->createStatement());

  	stmnt->executeQuery("INSERT INTO pizza(Name,Address,Rating) VALUES ('"+name+"','"+address+"','"+rating+"')");
}
/*
pizzaEntry pizzaDB::fetchEntry(string id){

	pizzaEntry entry;	
	
	if (!conn) {
   		cerr << "Invalid database connection" << endl;
   		exit (EXIT_FAILURE);
  	}

  	std::auto_ptr<sql::Statement> stmnt(conn->createStatement());

  	
    sql::ResultSet *res = stmnt->executeQuery("SELECT * FROM contacts WHERE ID = '"+id+"'");
    
    // Get first entry
    if (res->next()) {
    	entry = pizzaEntry(res->getString("First"),res->getString("Last"),
			res->getString("Phone"),res->getString("Type"),
	    	res->getString("ID"));
    }
    return entry;
}

void pizzaDB::editEntry(string idnum,string first,string last,string phone, string type){
	if (!conn) {
   		cerr << "Invalid database connection" << endl;
   		exit (EXIT_FAILURE);
  	}

  	std::auto_ptr<sql::Statement> stmnt(conn->createStatement());

  	if (type != "Friend" && type != "Family" && type!="Business"){
     	 type="Other";
  	}
  	
  	stmnt->executeQuery("UPDATE contacts SET First = '"+first+"', Last ='"+last+"', Phone ='"+phone+"', Type ='"+type+"' WHERE ID='"+idnum+"'");
  	
}


void pizzaDB::deleteEntry(string idnum){
  // Establish Connection
  std::unique_ptr<sql::Connection>  conn(driver->connect(db_url, properties));
    
  if (!conn) {
   	cerr << "Invalid database connection" << endl;
   	exit (EXIT_FAILURE);
  }

  std::auto_ptr<sql::Statement> stmt(conn->createStatement());

  stmt->execute("DELETE FROM contacts WHERE ID='"+idnum+"'");
}
*/
