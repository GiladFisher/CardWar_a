#include <iostream>
#pragma once
using namespace std;
class Player{
    private:
    int cardsTaken;
    int stackSize;
    public:
    Player(string name){
        this->name = name;
        this->cardsTaken = 0;
        this->stackSize = 0;
    }
    Player(){
        this->name = "NoName";
        this->cardsTaken = 0;
        this->stackSize = 0;
    }
    string name;
    int cardesTaken();
    int stacksize();
};