#include <iostream>
using namespace std;

#include "item.h"

Item::Item() {
  title = "";
  text  = "";
}

Item::Item(string _title, string _text) {
  title = _title;
  text = _text;
}

void Item::Print() {
  cout << " title: " << title << endl << "text: " << text << endl;
}
