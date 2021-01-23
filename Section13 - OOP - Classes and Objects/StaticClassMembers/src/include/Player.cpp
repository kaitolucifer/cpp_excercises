#include "Player.h"

int Player::num_players {0}; // initialize static variable

Player::Player(std::string name, int health, int xp)
    : name {name}, health {health}, xp {xp} {
        ++num_players;
    }

Player::Player(const Player &source)
    : Player {source.name, source.health, source.xp} { }

Player::~Player() {
    --num_players;
}

int Player::get_num_players() {
    return num_players;
}