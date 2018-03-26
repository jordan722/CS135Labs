#include <iostream>
using namespace std;
#include "indent.h"
#include "unindent.h"


int main(){
  string line;
  string ans = "";
  while(getline(cin, line)){
    ans += removeLeadingSpaces(line) + "\n";
  }
  cout << ans << endl;



  string line;
  string ans = "";
  while(getline(cin, line)){
    ans += removeLeadingSpaces(line) + "\n";
  }
  cout << ans << endl;
  return 0;
}
