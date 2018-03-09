#include <iostream>
#include <ctype.h>
#include "Rot13.h"

using namespace std;

ostream &operator<<( ostream &output, const Rot13 &rot13) {
  // cout<<"Printing something"<<endl;
  // cout<<rot13.cipher<<endl;
  output << rot13.cipher;
  return output;
}

istream &operator>>( istream &input, Rot13 &rot13) {
  input >> rot13.message;
  rot13.encode(rot13.message);
  return input;
}

Rot13::Rot13() {
  //Empty Constructor
}

Rot13::Rot13(const string &message) {
  setMessage(message);
  encode(message);
}

Rot13::~Rot13() {
  //Empty Destructor
}

string Rot13::getMessage() const {
  return message;
}

void Rot13::encode(string m) {
  // cout<<m<<endl;
  for(int i = 0; i<m.size(); i++){
    if(isalpha(m[i])){
      if(isupper(m[i])) {
        m[i]=(((m[i]-'A')+13)%26)+'A';
      } else {
        m[i]=(((m[i]-'a')+13)%26)+'a';
      }
    }
  }
  cipher = m;
}

void Rot13::setMessage(string m) {
  message = m;
}
