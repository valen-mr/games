#include <iostream>
#include <fstream>
#include <random>
#include <set>
#include "User.hpp"
const int SALARY = 200;
using namespace std;

//works
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
    bool roulette = true;

    while (roulette){
        cout << "\n";
        int bet = 0;
        cout << "ROULETTE\n\n";
        cout << "Gamble (g)\n";
        cout << "Back (b) \n";
        cout << "\n\033[1;31mYou have \033[1;32m$" << user.getBal() << "\n\n\033[0m";
        char choice;
        cin >> choice;
        if (choice == 'g'){
            cout << "\nEnter bet: ";
            cin >> bet;
            cout << "\n";
            int mult = 0;
            if (bet > 0 && bet <= user.getBal()){
                cout << "Red (r) \nBlack (b)\nNumber(n)\n";
                char letter;
                cin >> letter;
                cout << "\n";
                if(letter == 'r' || letter == 'b' || letter == 'n'){
                    int num;
                    if (letter == 'n'){
                        cout << "Choose from 0-37: ";
                        cin >> num;
                        cout << '\n';
                    }
                    user.ext(bet);
                    int result = rand() % 37;
                    int reward = 0;
                    char reslet;
                    cout << "\033[1;31m";
                    if(result % 2 == 0 && result != 0){
                        cout << "BLACK ";
                        reslet = 'b';
                    }
                    else if(result % 2 != 0 && result != 0){
                        cout << "RED ";
                        reslet = 'r';
                    }
                    else{
                        cout << "GREEN ";
                        reslet = 'g';
                    }
                    cout << result << " : ";
                    if (letter == 'r' || letter == 'b'){
                        //red
                        if (letter == reslet){
                            cout << "WIN : \033[1;32m+$";
                            reward = bet * 2;
                        }
                    }
                    else{
                        if (num == result){
                            cout << "WIN : \033[1;32m+$";
                            reward = bet * 37;
                        }
                    }
                    if (reward != 0){
                        cout << reward << "\n";
                        user.add(reward);
                    }
                    else
                        cout << "LOSE\n" ;
                    bet = 0;
                    cout << "\033[0m";
                }
            }
            else if (bet < 0) {
                cout << "\nfunny";
            }
            else 
                cout << "insuficient funds";
        }
        else if (choice == 'b'){
            roulette = false;
        }
    }
}

int main(){
    try{
        User user;
        cout << "\n";
        userCheck(user); //user.txt generated
        bool menu = true;
        while(menu){
            cout << "MAIN MENU\n\n";
            cout << "Work (w) \n";
            cout << "Roulette (r) \n";
            cout << "Exit (e) \n";
            cout << "\n\033[1;31mYou have \033[1;32m$" << user.getBal() << "\n\n\033[0m";
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