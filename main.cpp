#include <iostream>
using namespace std;

void usage() {
  cout << "Usage:" << endl
       << "\t./todo add \"do stuff\"" << endl
       << "\t./todo remove 0" << endl
       << "\t./todo list" << endl;
}

int main(int argc, char*argv[]) {
  if(argc < 2) {
    usage();
    return 1;
  }
  cout << "nb d'arguments: " << argc << endl;
  cout << "nom du programme: " << argv[0] << endl;
  return 0;
}
