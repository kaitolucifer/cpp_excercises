#include <iostream>

using namespace std;

class Player {
    private:
        std::string name;
        int health;
        int xp;
    public:
        Player();
        Player(std::string name_val);
        Player(std::string name_val, int health_val, int xp_val);
};

Player::Player(std::string name_val, int health_val, int xp_val)
    : name {name_val}, health {health_val}, xp {xp_val} {
        cout << "Three-args constructor" << endl;
    }

Player::Player() : Player {"None", 0, 0} { }

Player::Player(std::string name_val) : Player {name_val, 0, 0} { }

int main()
{
    Player empty;
    Player frank {"Frank"};
    Player villian {"Villain", 100, 55};
    return 0;
}