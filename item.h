#include <iostream>
using namespace std;

class Item {
  string title;
  string text;

  public:
    Item();
    Item(string,string);
    void Print();
};
