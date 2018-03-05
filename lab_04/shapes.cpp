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


// Task D
string lowerTri(int length){
  string ans ="";
  for(int i = 0; i < length; i++){
    int j = 0;
    while(j <= i){
        ans += "*";
        j++;
    }
    ans += "\n";
  }
  return ans;
}


// Task E
string upperTri(int length){
  string ans ="";
  for(int i = 0; i < length; i++){
    for(int j = 0; j < length; j++){
      if(j >= i){
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


// Task F
string trapezoid(int width, int height){
  string ans ="";
  if(width/2 < height){
    return "Impossible shape!\n";
  }
  for(int i = 0; i < height; i++){
    for(int j = 0; j < width; j++){
      if(j >= i && j <= (width-1-i)){
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


// Task G
string checkerboard3(int width, int height){
  string ans = "";
  for(int i = 0; i < height; i++){
    for(int j = 0; j < width; j++){
      if((i/3)%2 == (j/3)%2){
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
