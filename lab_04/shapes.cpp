/*
Author: Jordan Yaqoob
Course: CSCI-136
Instructor: Zamansky
Assignment: Lab_04
*/


#include <iostream>
#include <cstdlib>

using namespace std;

// Task A
string box(int width, int height){
  string ans = "";
  for(int i = 0; i < height; i++){
    for(int j = 0; j < width; j++){
      ans += "*";
    }
    ans += "\n";
  }
  return ans;
}

// Task B
string checkerboard(int width, int height){
  string ans="";
  bool isBlack = true;
  for(int i = 0; i < height; i++){
    for(int j = 0; j < width; j++){
      if(i%2 == j%2){
        ans += "*";
      }
      else{
        ans += " ";
      }
      isBlack = !isBlack;
    }
    ans += "\n";
  }
  return ans;
}

// Task C
string cross(int size){
  string ans = "";
  for(int i = 0; i < size; i++){
    for(int j = 0; j < size; j++){
      if(j==i || j == (size-1-i)){
        ans += "*";
      }
      else{
        ans += " ";
      }
    }
    ans += "\n";
  }
  return ans;
}
