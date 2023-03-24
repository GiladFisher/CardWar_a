#include <iostream>
#include "player.hpp"
#pragma once
namespace ariel{
class Game{
    Player p1;
    Player p2;
    public:
    Game(Player p1, Player p2){
        this->p1 = Player(p1.name);
        this->p2 =  Player(p2.name);
    }
    void playTurn();
    void playAll();
    void printLog();
    void printWiner();
    void printStats();
    void printLastTurn();
};
}
