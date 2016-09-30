#include <iostream>
using namespace std;

#include "item.h"

void usage(string name) {
  cout << "Usage:" << endl
       << "\t" << name << " add \"do stuff\"" << endl
       << "\t" << name << " remove 0" << endl
       << "\t" << name << " list" << endl;
}

int main(int argc, char*argv[]) {
  Item it = Item();



  string name = argv[0];
  if(argc < 2) {
    usage(name);
    return 1;
  }

  string command = argv[1];
  if(command == "list") {
    cout << "Todo list:" << endl;
  }else if(command == "add") {
    if(argc != 3) {
      usage(name);
      return 1;
    }

    string title = argv[2];
    cout << "adding " << title << endl;
  } else if(command == "remove") {
    if(argc != 3) {
      usage(name);
      return 1;
    }
    uint index = atoi(argv[2]);
    cout << "removing item at index = " << index << endl;
  } else {
    usage(name);
    return 1;
  }
  return 0;
}
