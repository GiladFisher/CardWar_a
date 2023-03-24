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

TEST_CASE("Test player class"){
    Player p1("p1");
    CHECK(p1.name == "p1");
    CHECK(p1.cardesTaken() == 0);
    CHECK(p1.stacksize() == 0);
    Player p2("p2");
    CHECK(p2.name == "p2");
    CHECK(p2.cardesTaken() == 0);
    CHECK(p2.stacksize() == 0);
    Game g(p1, p2);
    CHECK(g.p1.name == "p1");
    CHECK(g.p2.name == "p2");
    CHECK(g.p1.cardesTaken() == 0);
    CHECK(g.p2.cardesTaken() == 0);
    CHECK(g.p1.stacksize() == 0);
    CHECK(g.p2.stacksize() == 0);
}
TEST_CASE("Test Game"){
    Player p1("p1");
    Player p2("p2");
    Game g(p1, p2);
    CHECK(g.p1.name == "p1");
    CHECK(g.p2.name == "p2");
    CHECK(g.p1.cardesTaken() == 0);
    CHECK(g.p2.cardesTaken() == 0);
    CHECK(g.p1.stacksize() == 0);
    CHECK(g.p2.stacksize() == 0);
    g.playAll();
    CHECK(g.p1.cardesTaken() == 26);
    CHECK(g.p2.cardesTaken() == 26);
    CHECK(g.p1.stacksize() == 0);
    CHECK(g.p2.stacksize() == 0);
}

