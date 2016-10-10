#include <iostream>
using namespace std;

#include "file.h"
#include "item.h"

void usage(string name) {
  cout << "Usage:" << endl
       << "\t" << name << " add 0 \"do stuff\" \"text\"" << endl
       << "\t" << name << " remove 0" << endl
       << "\t" << name << " list" << endl;
}

int main(int argc, char*argv[]) {

  Item list[10];
  list[0].Change("item 0", "hello");
  list[1].Change("item 1", "hello world");
  list[0].Print();

  write_items(list);


  string name = argv[0];
  if(argc < 2) {
    usage(name);
    return 1;
  }

  string command = argv[1];
  if(command == "list") {
    cout << "Todo list:" << endl;

    for(int i = 0; i< 10; i++) {
      list[i].Print();
    }
  }else if(command == "add") {
    if(argc != 5) {
      usage(name);
      return 1;
    }

    uint index = atoi(argv[2]);
    string title = argv[3];
    string text  = argv[4];
    cout << "adding " << title << " at " << index << endl;
    list[index].Change(title, text);
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
