#include "pizzaEntry.h"

pizzaEntry::pizzaEntry() {
}

pizzaEntry::pizzaEntry(sql::SQLString ID, sql::SQLString Name, sql::SQLString Address, sql::SQLString Rating) {
    this->ID = ID;
    this->Name = Name;
    this->Address = Address;
    this->Rating = Rating;
}

string pizzaEntry::text() {
	string result = ID + ". ";
	result += Name + " ";
	result += Address + " ";
	result += Rating;
	return result;

}

string pizzaEntry::json() {
	string result = "{\"ID\":\"" + ID + "\",";
	result += "\"Name\":\"" + Name + "\",";
	result += "\"Address\":\"" + Address + "\",";
	result += "\"Rating\":\"" + Rating + "\"}";
	return result;

}
