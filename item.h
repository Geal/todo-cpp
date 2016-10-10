#ifndef ITEM_H
#define ITEM_H

#include <iostream>
using namespace std;

class Item {
  string title;
  string text;
  bool   finished;

  public:
    Item();
    Item(string,string);
    Item(string,string,bool);
    void Print();
    void Change(string title, string text, bool finished);
    string Title();
    string Text();
    bool   Finished();
    void   Toggle();
};

#endif
