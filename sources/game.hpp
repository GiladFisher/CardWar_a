#include <iostream>

class Game{
    Player p1;
    Player p2;
    public:
    Game(Player p1, Player p2);
    void playTurn();
    void playAll();
    void printLog();
    void printWiner();
    void printStats();
    void printLastTurn();
};

