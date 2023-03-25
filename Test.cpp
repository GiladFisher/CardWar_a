#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;
#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
using namespace ariel;

TEST_CASE("Test Setup"){
    ///// ***** Checks player constructor ***** /////
    Player p1("p1");
    CHECK(p1.name == "p1");
    CHECK(p1.cardesTaken() == 0);
    CHECK(p1.stacksize() == 0);
    Player p2("p2");
    CHECK(p2.name == "p2");
    CHECK(p2.cardesTaken() == 0);
    CHECK(p2.stacksize() == 0);

    ///// ***** Checks game constructor ***** /////
    Game g(p1, p2);

    CHECK(g.p1.name == "p1");
    CHECK(g.p2.name == "p2");

    CHECK(g.p1.cardesTaken() == 0);// none were won
    CHECK(g.p2.cardesTaken() == 0);

    CHECK(g.p1.stacksize() == 26);// none were lost
    CHECK(g.p2.stacksize() == 26);
}
TEST_CASE("Test Game End"){ // checks if the game ends when one of the players has no cards left
    Player p1("p1");
    Player p2("p2");
    Game g(p1, p2);

    g.playAll();
    if(g.p1.stacksize() == 52){
        CHECK(g.p2.stacksize() == 0);
        CHECK(g.p1.cardesTaken() == 26);
    }

    else{
        CHECK(g.p2.stacksize() == 52);
        CHECK(g.p2.cardesTaken() == 26);
    }
    CHECK_THROWS(g.playTurn());// shold throw an error if the game is over
}

TEST_CASE("Test Game Turn"){ // if a turn is played correctly
    Player p1("p1");
    Player p2("p2");
    Game g(p1, p2);

    g.playTurn();

    if(g.p1.stacksize() < 26){
        CHECK(g.p2.stacksize() > 26);
        CHECK(g.p1.stacksize() < 26);
    }

    else{
        CHECK(g.p1.stacksize() > 26);
        CHECK(g.p2.stacksize() < 26);
    }
    
}

