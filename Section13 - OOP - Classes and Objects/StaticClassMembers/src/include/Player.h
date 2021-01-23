#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <string>

class Player {
    private:
        static int num_players;
        std::string name;
        int health;
        int xp;
    public:
        std::string get_name() {return name;}
        int get_health() {return health;}
        int get_xp() {return xp;}
        Player(std::string name = "None", int health = 0, int xp = 0);
        Player(const Player &source);
        ~Player();

        static int get_num_players();
};

#endif // _PLAYER_H_