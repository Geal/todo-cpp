#include <iostream>
using namespace std;

#include "item.h"

Item::Item() {
  title    = "";
  text     = "";
  finished = false;
}

Item::Item(string _title, string _text) {
  title    = _title;
  text     = _text;
  finished = false;
}

Item::Item(string _title, string _text, bool _finished) {
  title    = _title;
  text     = _text;
  finished = _finished;
}

void Item::Print() {
  if(title != "" || text != "") {
    string crossed = " ";
    if(finished) {
      crossed = "X";
    }

    cout << "[" << crossed << "] title: " << title << endl
         << "text: " << text << endl;
  }
}

void Item::Change(string _title, string _text, bool _finished) {
  title    = _title;
  text     = _text;
  finished = _finished;
}

string Item::Title() {
  return title;
}

string Item::Text() {
  return text;
}

bool Item::Finished() {
  return finished;
}

void Item::Toggle() {
  finished = !finished;
}
