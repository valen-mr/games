#include <iostream>
#include <fstream>
#include <random>
#include "Roulette.hpp"

static rResult rollRoulette(){
    int result = rand() % 38;
    struct rResult res;
    res.num = result;
    if (result != 0){
        if ( result % 2 == 0 && (result < 10 || result > 18))
            res.color = black;
        else if ( result % 2 != 0 && (result < 10 || result > 18))
            res.color = red;
        else if (result % 2 == 0)
            res.color = red;
        else
            res.color = black;
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
        cout << "ROULETTE\n\n";
        cout << "Gamble (g)\n";
        cout << "Back (b) \n";
        cout << "\n\033[1;31mYou have \033[1;32m$" << user.getBal() << "\n\n\033[0m";
        char choice;
        cin >> choice;
        //game
        if (choice == 'g'){
            cout << "Red (r) \nBlack (b)\nNumber(n)\n\n";
            char letter;
            cin >> letter;
            cout << "\n";
            if(letter == 'r' || letter == 'b' || letter == 'n'){
                int bet = 0;
                struct choice num[37];
                int cant = 0;
                int reward = 0;

                //number choice
                if (letter == 'n'){
                    bool done = false;
                    cout << "Choose from 0-37 : ";
                    for (int i = 0; i < 37; i++){
                        if (!done){
                                cin >> num[i].num;
                            if (cin.peek() == '\n'){
                                cant = i + 1;
                                done = true;
                            }
                        }
                        else
                            num[i].num = -1;
                        num[i].bid = 0;
                    }
                    int i = 0;
                    while (i < cant){
                        int bid = 0;
                        cout << "\nBet on " << num[i].num << " : ";
                        cin >> bid;
                        if (bet + bid > user.getBal())
                            cout << "insuficient funds\n";
                        else if (bid < 0)
                            cout << "funny\n";
                        else{
                            num[i].bid += bid; 
                            i++;
                            bet += bid;
                        }
                    }
                    cout << '\n';

                }
               
                //color choice
                if(letter != 'n'){
                    cout << "Enter bet: ";
                    cin >> bet;
                    cout << "\n";
                }
                if (bet <= 0){
                    cout << "funny";
                }
                else if ( bet > user.getBal()) {
                    cout << "insufficient funds";
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

                //user picked color
                if (letter == 'r' && res.color == red){
                    cout << "WIN \033[1;32m+$";
                    reward = bet * 2;
                }    
                else if (letter == 'b' && res.color == black){
                    cout << "WIN \033[1;32m+$";
                    reward = bet * 2;
                }
                //user picked numbers
                else{
                    for (int i = 0; i < cant; i++){
                        if (num[i].num == res.num){
                            cout << "WIN \033[1;32m+$";
                            reward += num[i].bid * 37;
                        }
                    }
                }
                if (reward != 0){
                    cout << reward << "\n";
                    user.add(reward);
                }
                else
                    cout << "LOSE\n" ;
                cout << "\033[0m";
            }
        }
        else if (choice == 'b'){
            roulette = false;
        }
    }
}