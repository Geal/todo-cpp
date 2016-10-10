#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

#include "item.h"
#include "file.h"

void write_items(vector<Item> items) {
  ofstream wfile;
  wfile.open ("data.db");
  if (wfile.is_open()) {
    for(Item it: items) {
      wfile << it.Title() << '\x1F' << it.Text() << '\x1E';
    }
    wfile.close();
  } else {
    cout << "could not save items" << endl;
  }
}

string read_file();


void read_items(vector<Item>& items) {
  string content = read_file();
  string::size_type prev_pos = 0, pos = 0;
  char unit_separator   = '\x1F';
  char record_separator = '\x1E';

  while((pos = content.find(unit_separator, pos)) != string::npos) {
    string title( content.substr(prev_pos, pos-prev_pos) );

    prev_pos = ++pos;
    if((pos = content.find(record_separator, pos)) != string::npos) {
      string text( content.substr(prev_pos, pos-prev_pos) );

      items.push_back(Item(title, text));
      prev_pos = ++pos;
    } else {
      break;
    }
  }
}


string read_file() {
  ifstream rfile ("data.db");
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

