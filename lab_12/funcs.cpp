#include <iostream>
#include <ctype.h>

using namespace std;

void printRange(int left, int right){
  if(left > right){
    cout << "";
    return;
  }
  cout << left;
  cout << " ";
  printRange(left+1, right);
}


int sumRange(int left, int right){
  if(left == right){
    return left;
  }
  return left + sumRange(left+1, right);
}

int sumArrayInRange(int *arr, int left, int right){
  if(left == right){
    return arr[left];
  }
  return arr[left]+sumArrayInRange(arr, left+1, right);
}

int sumArray(int *arr, int size){
 return sumArrayInRange(arr, 0, size-1);
}

bool isAlphanumeric(string s){
  if(s == ""){
    return true;
  }
  return isalnum(s[0]) && isAlphanumeric(s.substr(1, s.length()-1));
}

bool nestedParens(string s){
  if(s == ""){
    return true;
  }
  if(!(s[0] == '(' && s[s.length()-1] == ')')){
    return false;
  }
  return nestedParens(s.substr(1, s.length()-2));

}
