#include "User.hpp"

enum color {red, black, green};

struct rResult {
    enum color color;
    int num;
};

struct choice{
    int num;
    int bid;
};

//Enter Roulette menu
void Roulette(User&);