#include "chatEntry.h"

chatEntry::chatEntry() {
}

pizzaEntry::pizzaEntry(sql::SQLString ID, sql::SQLString user, sql::SQLString email, sql::SQLString pass) {
    this->ID = ID;
    this->user = user;
    this->email = email;
    this->pass = pass;
}

string pizzaEntry::text() {
	string result = ID + ". ";
	result += user + " ";
	result += email + " ";
	result += pass;
	return result;

}

string pizzaEntry::json() {
	string result = "{\"ID\":\"" + ID + "\",";
	result += "\"user\":\"" + user + "\",";
	result += "\"email\":\"" + email + "\",";
	result += "\"pass\":\"" + pass + "\"}";
	return result;

}
