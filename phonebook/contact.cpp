#include <iostream>
#include "contact.h"

using namespace std;

Contact::Contact() {
  //Empty Constructor
}

Contact::Contact(const string &name, const string &number) {
  setName( name );
  setNumber ( number );
}

Contact::Contact(const string &fName, const string &lName, const string &number) {
  string name = lName + ", " + fName;
  setName( name );
  setNumber ( number );
}

Contact::~Contact() {
  //Empty Destructor
}

string Contact::getName() const {
  return name;
}

string Contact::getNumber() const {
  return number;
}

string Contact::getAddress() const {
  return address;
}

string Contact::getEmail() const {
  return email;
}

Contact &Contact::setName( const string &name) {
  this->name = name;
  return *this;
}

Contact &Contact::setNumber( const string &number ) {
  this->number = number;
  return *this;
}

Contact &Contact::setAddress( const string &address ) {
  this->address = address;
  return *this;
}

Contact &Contact::setEmail( const string &email ) {
  this->email = email;
  return *this;
}

string Contact::toString () const {
  return "Name \t\t: "+this->name+"\nNumber \t\t: "+this->number+\
  "\nEmail \t\t: "+this->email+"\nAddress \t: "+this->address+"\n";
}

