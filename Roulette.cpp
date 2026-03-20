#include <iostream>
#include <fstream>
#include <random>
#include "Roulette.hpp"

static rResult rollRoulette(){
    int result = rand() % 38;
    struct rResult res;
    res.num = result;
    if (result != 0){
        if ( result % 2 == 0)
            res.color = black;
        else
            res.color = red;
    }
    else 
        res.color = green;
    return res;
}

void Roulette(User& user){
    bool roulette = true;

    while (roulette){
        //menu
        cout << "\n";
        int bet = 0;
        cout << "ROULETTE\n\n";
        cout << "Gamble (g)\n";
        cout << "Back (b) \n";
        cout << "\n\033[1;31mYou have \033[1;32m$" << user.getBal() << "\n\n\033[0m";
        char choice;
        cin >> choice;
        //game
        if (choice == 'g'){
            cout << "\nEnter bet: ";
            cin >> bet;
            cout << "\n";
            int mult = 0;
            if (bet > 0 && bet <= user.getBal()){
                cout << "Red (r) \nBlack (b)\nNumber(n)\n\n";
                char letter;
                cin >> letter;
                cout << "\n";
                if(letter == 'r' || letter == 'b' || letter == 'n'){
                    int num;
                    int reward = 0;
                    //choose number
                    if (letter == 'n'){
                        cout << "Choose from 0-37: ";
                        cin >> num;
                        cout << '\n';
                    }
                    //roll
                    user.ext(bet);
                    cout << "\n\033[1;31m";
                    struct rResult res = rollRoulette();
                    switch(res.color){
                        case red: cout << "RED "; break;
                        case black: cout << "BLACK "; break;
                        case green: cout << "GREEN "; break;

                    }
                    cout << res.num << " : ";
                    //user picked a color
                    if(letter != 'n'){
                        if (letter == 'r' && res.color == red){
                            cout << "WIN \033[1;32m+$";
                            reward = bet * 2;
                        }    
                        else if (letter == 'b' && res.color == black){
                            cout << "WIN \033[1;32m+$";
                            reward = bet * 2;
                        }
                    }
                    //user picked a number
                    else{
                        if (num == res.num){
                            cout << "WIN \033[1;32m+$";
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