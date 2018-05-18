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
  bool following[MAX_USERS][MAX_USERS];  // friendship matrix:
  // following[id1][id2] == true when id1 is following id2

public:
  Network(){
    numUsers = 0;
    for(int i = 0; i < MAX_USERS; i ++){
      for(int j = 0; j < MAX_USERS; j++){
        following[i][j] = false;
      }
    }
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

  // Make 'usrn1' follow 'usrn2' (if both usernames are in the network).
   // return true if success (if both usernames exist), otherwise return false
   bool follow(string usrn1, string usrn2){
     int i = findID(usrn1);
     int i2 = findID(usrn2);
     if(i == -1 || i2 == -1){
       return false;
     }
     following[i][i2] = true;
     return true;
   }

   // Print Dot file (graphical representation of the network)
   void printDot(){
     for(int i = 0; i < numUsers; i++){
       cout << "@" + profiles[i].getUsername() <<endl;
     }
     for(int i = 0; i < numUsers; i++){
       for(int j = 0; j < numUsers; j++){
         if(following[i][j]){
           cout << "@" + profiles[i].getUsername() + " -> " + "@" + profiles[j].getUsername() << endl;
         }
       }
     }
   }
};

int main() {
    Network nw;
    // add three users
    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");

    // make them follow each other
    nw.follow("mario", "luigi");
    nw.follow("mario", "yoshi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
    nw.follow("yoshi", "luigi");

    // add a user who does not follow others
    nw.addUser("wario", "Wario");

    // add clone users who follow @mario
    for(int i = 2; i < 6; i++) {
        string usrn = "mario" + to_string(i);
        string dspn = "Mario " + to_string(i);
        nw.addUser(usrn, dspn);
        nw.follow(usrn, "mario");
    }
    // additionally, make @mario2 follow @luigi
    nw.follow("mario2", "luigi");

    nw.printDot();
}
