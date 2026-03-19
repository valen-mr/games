#include <string>

using namespace std;

class User{
    private:
        string name;
        int bal;
    public:
        User();
        int getBal() const;
        void setBal(int);
        string getName() const;
        void add(int);
        void ext(int); //assumes int < balance
};

//checks if user exists, if it doesnt creates one
void userCheck(User&);
