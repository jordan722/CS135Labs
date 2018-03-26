/*
Author: Jordan Yaqoob
Course: CSCI-133
Instructor: Zamansky
Assignment: Lab 8 Task A

The program takes in a line of code and removes all leading white space
*/


#include <iostream>
using namespace std;

string removeLeadingSpaces(string line){
  string ans = "";
  int i = 0;
  while(isspace(line[i]) && i < line.length()){
    i++;
  }
  while(i < line.length()){
    ans += line[i];
    i++;
  }
  return ans;
}


int main(){
  string line;
  string ans = "";
  while(getline(cin, line)){
    ans += removeLeadingSpaces(line) + "\n";
  }
  cout << ans << endl;
  return 0;
}
