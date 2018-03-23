#include <string>

using namespace std;

#ifndef CONTACT_H
#define CONTACT_H

class contact {
  public:
    contact();
    contact( const string& , const string& );
    contact( const string& , const string& , const string& );
    ~contact();

    string getName() const;
    string getNumber() const;
    string getAddress() const;
    string getEmail() const;

    contact &setName( const string& );
    contact &setNumber( const string& );
    contact &setAddress( const string& );
    contact &setEmail( const string& );

    string toString() const;
  private:
    string name;
    string number;
    string address;
    string email;
};

#endif