#include <string>

using namespace std;

#ifndef CONTACT_H
#define CONTACT_H

class Contact {
  public:
    Contact();
    Contact( const string& , const string& );
    Contact( const string& , const string& , const string& );
    ~Contact();

    string getName() const;
    string getNumber() const;
    string getAddress() const;
    string getEmail() const;

    Contact &setName( const string& );
    Contact &setNumber( const string& );
    Contact &setAddress( const string& );
    Contact &setEmail( const string& );

    string toString() const;
  private:
    string name;
    string number;
    string address;
    string email;
};

#endif