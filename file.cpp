#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

#include "item.h"

void write_items(Item items[10]) {
  ofstream wfile;
  wfile.open ("data.txt");
  if (wfile.is_open()) {
    for(int i = 0; i < 10; i++) {
      wfile << items[i].Title() << '\x1F' << items[i].Text() << '\x1E';
    }
    wfile.close();
  } else {
    cout << "could not save items" << endl;
  }
}

string read_file();

/*
void read_items(Item items[10] ) {
  string content = read_file();
}
*/

string read_file() {
  ifstream rfile ("data.txt");
  if (rfile.is_open()) {
    stringstream buffer;
    buffer << rfile.rdbuf();
    string content = buffer.str();

    rfile.close();
    return content;
  } else {
    cout << "could not read data" << endl;
    return "";
  }
}

