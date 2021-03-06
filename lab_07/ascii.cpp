#include <iostream>
using namespace std;

void testascii(std::string s){
  for(int i = 0; i < s.length(); i++){
    cout << s[i] << " " << (int) s[i] << endl;
  }
}

char shiftChar(char c, int rshift){

  if(c >= 65 && c <= 90){
    int shift = (int) c - 65 + rshift;
    while(shift < 0){
      shift += 26;
    }
    return 65 + shift % 26;
  }
  if(c >= 97 && c <= 122){
    int shift = (int) c - 97 + rshift;
    while(shift < 0){
      shift += 26;
    }
    return 97 + shift % 26;
  }
  return c;
}

string encryptCaesar(string plaintext, int rshift){
  string ans = "";
  for(int i = 0; i < plaintext.length(); i++){
    ans += shiftChar(plaintext[i], rshift);
  }
  return ans;
}

string encryptVigenere(string plaintext, string keyword){
  string ans = "";
  int loc = 0;
  for(int i = 0; i < plaintext.length(); i++){
    char c = plaintext[i];
    if(isalpha(c)){
      int rshift = (int)keyword[loc];
      if(rshift < 90){
        rshift = rshift - 65;
      }
      else{
        rshift = rshift - 97;
      }
      loc = (loc + 1) % keyword.length();
      ans += shiftChar(c, rshift);
    }
    else{
      ans += c;
    }
  }
  return ans;
}

string decryptCaesar(string ciphertext, int rshift){
  string ans = "";
  for(int i = 0; i < ciphertext.length(); i++){
    ans += shiftChar(ciphertext[i], -rshift);
  }
  return ans;
}

string decryptVigenere(string ciphertext, string keyword){
  string ans = "";
  int loc = 0;
  for(int i = 0; i < ciphertext.length(); i++){
    char c = ciphertext[i];
    if(isalpha(c)){
      int rshift = (int)keyword[loc];
      if(rshift < 90){
        rshift = rshift - 65;
      }
      else{
        rshift = rshift - 97;
      }
      loc = (loc + 1) % keyword.length();
      ans += shiftChar(c, -rshift);
    }
    else{
      ans += c;
    }
  }
  return ans;
}
