#include "User.hpp"
#include <fstream>
#include <iostream>

User::User(){
    string n;
    this->name = n;
    this->bal = 0;
}

int User::getBal() const{
    return this->bal;
}

void User::setBal(int n){
    this->bal = n;
    ofstream temp("temp.txt");
    temp << n;
    remove("user.txt");
    rename("temp.txt", "user.txt");
}

string User::getName() const{
    return this->name;
}

void userCheck(User& user){
    ifstream fin("user.txt");
    if (!fin){
        user.setBal(200);
    }
    else{
        int cash;
        fin >> cash;
        user.setBal(cash);
    }
}

void User::add(int sum){
    this->bal += sum;
    ofstream temp("temp.txt");
    temp << this->bal;
    remove("user.txt");
    rename("temp.txt", "user.txt");
}

void User::ext(int sum){
   this->bal -= sum;
    ofstream temp("temp.txt");
    temp << this->bal;
    remove("user.txt");
    rename("temp.txt", "user.txt");
}