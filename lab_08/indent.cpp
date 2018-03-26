/*
Author: Jordan Yaqoob
Course: CSCI-133
Instructor: Zamansky
Assignment: Lab 8 Task A

The program takes in a line of code and removes all leading white space
*/


#include <iostream>
using namespace std;

int countChar(string line, char c){
  int count = 0;
  for(int i = 0; i < line.length(); i++){
    if(line[i]==c){
      count++;
    }
  }
  return count;
}

string addspace(string line,int block){
  string ans = "";
  for(int i = 0; i < block; i++){
    ans += "\t";
  }
  return ans + line;
}


int main(){
  string line;
  string ans = "";
  int blocks = 0;
  while(getline(cin, line)){
    blocks -= countChar(line, '}');
    //cout << blocks << endl;
    ans +=  addspace(line, blocks);
    blocks += countChar(line, '{');
    ans += "\n";
  }
  cout << ans << endl;
  return 0;
}
