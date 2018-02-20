/*
Author: Jordan Yaqoob
Course: CSCI-136
Instructor: Zamansky
Assignment: Lab_03 Prelab
*/


#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

double east_storage(string inp_date){
  string date;
  double eastSt, eastEl, westSt, westEl;
  double ans = 0.0;
  ifstream fin("Current_Reservoir_Levels.tsv");
  if(fin.fail()){
    cerr << "File cannot be opened for reading." << endl;
    exit(1); // exit if failed to open the file
  }
  string junk;
  getline(fin,junk);
  while(fin >> date >> eastSt >> eastEl >> westSt >> westEl){
    if(date == inp_date){
      ans = eastSt;
    }
  }
  fin.close();
  return ans;
}

int main(){
  cout << east_storage("07/22/2016") << endl;
  return 0;
}
