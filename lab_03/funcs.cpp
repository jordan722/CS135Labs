/*
Author: Jordan Yaqoob
Course: CSCI-136
Instructor: Zamansky
Assignment: Lab_03
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


double mineast(){
  string date;
  double eastSt, eastEl, westSt, westEl;
  ifstream fin("Current_Reservoir_Levels.tsv");
  if(fin.fail()){
    cerr << "File cannot be opened for reading." << endl;
    exit(1); // exit if failed to open the file
  }
  string junk;
  getline(fin,junk);
  double min = 100;
  while(fin >> date >> eastSt >> eastEl >> westSt >> westEl){
    if(eastSt < min){
      min = eastSt;
    }
  }
  fin.close();
  return min;
}

double maxeast(){
  string date;
  double eastSt, eastEl, westSt, westEl;
  ifstream fin("Current_Reservoir_Levels.tsv");
  if(fin.fail()){
    cerr << "File cannot be opened for reading." << endl;
    exit(1); // exit if failed to open the file
  }
  string junk;
  getline(fin,junk);
  double max = 0.0;
  while(fin >> date >> eastSt >> eastEl >> westSt >> westEl){
    if(eastSt > max){
      max = eastSt;
    }
  }
  fin.close();
  return max;
}

string compare(string beg,string end){
  string date;
  double eastSt, eastEl, westSt, westEl;
  ifstream fin("Current_Reservoir_Levels.tsv");
  if(fin.fail()){
    cerr << "File cannot be opened for reading." << endl;
    exit(1); // exit if failed to open the file
  }
  string junk;
  getline(fin,junk);
  string ans;
  while(fin >> date >> eastSt >> eastEl >> westSt >> westEl){
    if(date >= beg && date <= end){
      ans += date + " ";
      if(eastEl > westEl){
        ans += "East";
      }
      else{
        if(eastEl < westEl){
          ans += "West";
        }
        else{
          ans += "Equal";
        }
      }
      ans += "\n";
    }
  }
  fin.close();
  return ans;
}

string reverse_order(string beg, string end){
  string date;
  double eastSt, eastEl, westSt, westEl;
  ifstream fin("Current_Reservoir_Levels.tsv");
  if(fin.fail()){
    cerr << "File cannot be opened for reading." << endl;
    exit(1); // exit if failed to open the file
  }
  string junk;
  getline(fin,junk);
  string ans;
  while(fin >> date >> eastSt >> eastEl >> westSt >> westEl){
    if(date >= beg && date <= end){
      ans = date + " " + to_string(westEl) + " ft" + "\n" + ans;
    }
  }
  fin.close();
  return ans;
}
