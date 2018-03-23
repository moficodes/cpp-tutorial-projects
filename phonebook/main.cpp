#include <iostream>
#include "contact.h"

using namespace std;

int main() {
  contact c = contact("Mofizur", "Rahman", "9292782183");
  c.setAddress("1870 baldwin rd").setEmail("thisismofi@gmail.com");
  cout << c.toString()<<endl;
}