#include <iostream>
#include <stdio.h>
#include <ctype.h>
using namespace std;

class Profile {
private:
    string username;
    string displayname;
public:
    // Profile constructor for a user (initializing
    // private variables username=usrn, displayname=dspn)
    Profile(string usrn, string dspn){
      username = usrn;
      displayname = dspn;
    }
    // Default Profile constructor (username="", displayname="")
    Profile(){
      username = "";
      displayname = "";
    }
    // Return username
    string getUsername(){
      return username;
    }
    // Return name in the format: "displayname (@username)"
    string getFullName(){
      return (displayname + " " + "(@" + username + ")");
    }
    // Change display name
    void setDisplayName(string dspn){
      displayname = dspn;
    }
};

class Network {
private:
  static const int MAX_USERS = 20; // max number of user profiles
  int numUsers;                    // number of registered users
  Profile profiles[MAX_USERS];     // user profiles array:
                                   // mapping integer ID -> Profile
  int findID (string usrn){

    for (int i = 0 ; i < numUsers ; i ++){
      if (profiles[i].getUsername() == usrn){
        return i;
      }
    }
    return -1;
  }
public:
  Network(){
    numUsers = 0;
  }
  // Attempts to sign up a new user with specified username and displayname
  // return true if the operation was successful, otherwise return false

  bool checkalnum(string x){
    for(int i = 0; i < x.length(); i++){
      if(!isalnum(x[i])){
        return false;
      }
    }
    return true;
  }

  bool addUser(string usrn, string dspn){
    if (findID(usrn) == -1 && numUsers < 20 && checkalnum(usrn)){
      Profile p1(usrn, dspn);
      profiles[numUsers] = p1;
      numUsers += 1;
      return true;
    }
    else{
      return false;
    }
  }
};


int main() {
  Network nw;
  cout << nw.addUser("mario", "Mario") << endl;     // true (1)
  cout << nw.addUser("luigi", "Luigi") << endl;     // true (1)

  cout << nw.addUser("mario", "Mario2") << endl;    // false (0)
  cout << nw.addUser("mario 2", "Mario2") << endl;  // false (0)
  cout << nw.addUser("mario-2", "Mario2") << endl;  // false (0)

  for(int i = 2; i < 20; i++)
        cout << nw.addUser("mario" + to_string(i),
                   "Mario" + to_string(i)) << endl;   // true (1)

  cout << nw.addUser("yoshi", "Yoshi") << endl;     // false (0)
}
