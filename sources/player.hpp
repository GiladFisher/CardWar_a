#include <iostream>
class Player{
    private:
    int cardsTaken;
    int stackSize;
    public:
    Player(string name);
    string name;
    int cardesTaken();
    int stacksize();
};