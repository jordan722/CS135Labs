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

int main(){
  
  printRange(-1,5);
  cout << "" << endl;
  cout << sumRange(3,5) << endl;

  int size = 10;
  int *arr = new int[size]; // allocate array dynamically
  arr[0] = 12;
  arr[1] = 17;
  arr[2] = -5;
  arr[3] = 3;
  arr[4] = 7;
  arr[5] = -15;
  arr[6] = 27;
  arr[7] = 5;
  arr[8] = 13;
  arr[9] = -21;

  int sum1 = sumArray(arr, size); // Add all elements
  cout << "Sum is " << sum1 << endl;  // Sum is 43

  int sum2 = sumArray(arr, 5); // Add up first five elements
  cout << "Sum is " << sum2 << endl;  // Sum is 34

  delete[] arr;         // deallocate it

  cout << isAlphanumeric("ABCD") << endl;        // true (1)
  cout << isAlphanumeric("Abcd1234xyz") << endl; // true (1)
  cout << isAlphanumeric("KLMN 8-7-6") << endl;  // false (0)

  cout << nestedParens("((()))") << endl;      // true (1)
  cout << nestedParens("()") << endl;          // true (1)
  cout << nestedParens("") << endl;            // true (1)

  cout << nestedParens("(((") << endl;         // false (0)
  cout << nestedParens("(()") << endl;         // false (0)
  cout << nestedParens(")(") << endl;          // false (0)
  cout << nestedParens("a(b)c") << endl;       // false (0)
}
