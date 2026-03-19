#include <iostream>
#include <fstream>
#include "User.hpp"
const int SALARY = 200;
using namespace std;


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


void Work(User& user){
    cout << "How many hours will you work?\n";
    bool out = false;
    int hours;
    while (!out){
        cin >> hours;
        if (hours < 0){
            throw invalid_argument("invalid amount");
        }
        else
            out = true;
    }
    int money = hours * SALARY;
    user.add(money);

    cout << "\n\033[1;31mYou worked for " << hours << "hour/s and recieved \033[1;32m$" << money << "\033[1;31m, you have: \033[1;32m$" << user.getBal() << "\n\n\033[0m";
}

void Roulette(User& user){
    cout << "ROULETTE\n\n";
    cout << "";
    cout << "\n\033[1;31mYou have \033[1;32m$" << user.getBal() << "\n\n033[0m";
    char choice;
    cin >> choice;
    cout << "\n";
}

int main(){
    try{
        bool menu = true;
        while(menu){
            User user;
            userCheck(user); //user.txt generated
            cout << "MAIN MENU\n\n";
            cout << "Work (w) \n";
            cout << "Roulette (r) \n";
            cout << "Exit (e) \n\n";
            cout << "\n\033[1;31mYou have \033[1;32m$" << user.getBal() << "\n\n033[0m";
            char choice;
            cin >> choice;
            switch (choice){
                case 'w':
                    Work(user);
                    break;
                case 'r': 
                    Roulette(user);
                    break;
                case 'e':
                    menu = false;
                    break;
            }
            cout << "\n";
        }
    }
    catch(invalid_argument){
        cout << "invalid amount";
    }
    return 0;
}