#include <iostream>
#include <string>

using namespace std;

#ifndef ROT13_H
#define ROT13_H

class Rot13 {
  friend ostream &operator<<( ostream &, const Rot13 & );
  friend istream &operator>>( istream &, Rot13 & );
  public:
    Rot13();
    Rot13( const string& );
    ~Rot13();
    string getMessage() const;
    string getEncoded();
    void setMessage( string );
    void encode( string );
  private:
    string message;
    string cipher;
};

#endif
