#include <iostream>
using namespace std;

class Item {
  string title;
  string text;

  public:
    Item();
    Item(string,string);
    void Print();
    void Change(string title, string text);
};
