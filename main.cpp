#include <iostream>
using namespace std;

void usage(string name) {
  cout << "Usage:" << endl
       << "\t" << name << " add \"do stuff\"" << endl
       << "\t" << name << " remove 0" << endl
       << "\t" << name << " list" << endl;
}

int main(int argc, char*argv[]) {
  string name = argv[0];
  if(argc < 2) {
    usage(name);
    return 1;
  }
  cout << "nb d'arguments: " << argc << endl;
  cout << "nom du programme: " << argv[0] << endl;
  return 0;
}
