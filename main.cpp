#include <iostream>
#include <vector>
using namespace std;

#include "file.h"
#include "item.h"

void usage(string name) {
  cout << "Usage:" << endl
       << "\t" << name << " add \"do stuff\" \"text\"" << endl
       << "\t" << name << " remove 0" << endl
       << "\t" << name << " list" << endl;
}

int main(int argc, char*argv[]) {
  vector<Item> list;
  read_items(list);

  string name = argv[0];
  if(argc < 2) {
    usage(name);
    return 1;
  }

  string command = argv[1];
  if(command == "list") {
    cout << "Todo list:" << endl;

    for(Item it: list) {
      it.Print();
    }
  }else if(command == "add") {
    if(argc != 4) {
      usage(name);
      return 1;
    }

    //uint index = atoi(argv[2]);
    string title = argv[2];
    string text  = argv[3];
    cout << "adding " << title << endl;
    list.push_back(Item(title, text));
    write_items(list);
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
