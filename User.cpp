#include "User.hpp"
#include <fstream>

User::User(){
    string n;
    this->name = n;
    this->bal = 0;
}

int User::getBal() const{
    return this->bal;
}

string User::getName() const{
    return this->name;
}

void userCheck(User& user){
    ifstream fin("user.txt");
    if (!fin){
        ofstream userFile("user.txt");
        user.add(200);
        userFile << 200;
    }
    else{
        int cash;
        fin >> cash;
        user.add(cash);
    }
}

void User::add(int sum){
    this->bal += sum;
    int balance;
    ifstream userFile("user.txt");
    ofstream temp("temp.txt");
    userFile >> balance;
    balance += sum;
    temp << balance;
    remove("user.txt");
    rename("temp.txt", "user.txt");
}

void User::ext(int sum){
    this->bal += sum;
    int balance;
    ifstream userFile("user.txt");
    ofstream temp("temp.txt");
    userFile >> balance;
    balance -= sum;
    temp << balance;
    remove("user.txt");
    rename("temp.txt", "user.txt");
}