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
  if(title != "" || text != "") {
    cout << " title: " << title << endl
         << "text: " << text << endl;
  }
}

void Item::Change(string _title, string _text) {
  title = _title;
  text = _text;
}

string Item::Title() {
  return title;
}

string Item::Text() {
  return text;
}
