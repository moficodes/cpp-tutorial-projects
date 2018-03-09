#include <iostream>
#include "Rot13.h"

using namespace std;

int main(){
  Rot13 rot13;

  cout<<"Enter text to convert : "<<endl;
  string line = "garbage";
  string text = "";
  while(true){
    getline(cin, line);
    if(line.length() != 0){
      text += line+'\n';
    } else {
      text += '\b';
      break;
    }

  }

  rot13.encode(text);

  cout<<"Converter text : "<<endl;
  cout << rot13 <<endl;
}
