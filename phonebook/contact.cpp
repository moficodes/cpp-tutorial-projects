#include <iostream>
#include "contact.h"

using namespace std;

contact::contact() {
  //Empty Constructor
}

contact::contact(const string &name, const string &number) {
  setName( name );
  setNumber ( number );
}

contact::contact(const string &fName, const string &lName, const string &number) {
  string name = lName + ", " + fName;
  setName( name );
  setNumber ( number );
}

contact::~contact() {
  //Empty Destructor
}

string contact::getName() const {
  return name;
}

string contact::getNumber() const {
  return number;
}

string contact::getAddress() const {
  return address;
}

string contact::getEmail() const {
  return email;
}

contact &contact::setName( const string &name) {
  this->name = name;
  return *this;
}

contact &contact::setNumber( const string &number ) {
  this->number = number;
  return *this;
}

contact &contact::setAddress( const string &address ) {
  this->address = address;
  return *this;
}

contact &contact::setEmail( const string &email ) {
  this->email = email;
  return *this;
}

string contact::toString () const {
  return "Name \t\t: "+this->name+"\nNumber \t\t: "+this->number+\
  "\nEmail \t\t: "+this->email+"\nAddress \t: "+this->address+"\n";
}

