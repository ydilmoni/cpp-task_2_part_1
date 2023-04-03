#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
#include <stdexcept>

using namespace ariel;

TEST_CASE("try to create a Player")
{
    CHECK_NOTHROW(Player p1("Alice"));
    CHECK_NOTHROW(Player p2("Bob"));
    CHECK_NOTHROW(Player p3(""));
    CHECK_NOTHROW(Player p4());
}

TEST_CASE("after I create a Player")
{
    Player p1("Alice");
    Player p2("Bob");
    CHECK(p1.stacksize() == 0);
    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.stacksize() == 0);
    CHECK(p2.cardesTaken() == 0);
}

TEST_CASE("Try to create a Game")
{
    Player p1("Alice");
    Player p2("Bob");
    CHECK_THROWS(Game game1(p1, p1));
    CHECK_NOTHROW(Game game2(p1,p2));
    CHECK_THROWS(Game game3(p1));
    CHECK_THROWS(Game game4("Alice","Bob"));
}

TEST_CASE("player play two games at the same time")
{
    Player p1("Alice");
    Player p2("Bob");
    Player p3("Ivgeni");
    Game game1(p1, p2);
    CHECK_THROWS(Game game(p1, p3));
}
TEST_CASE("Create a Game with two Player and chack their stack size and cards taken")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game1(p1, p2);
    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);
    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 0);
}

TEST_CASE("Create a Game with two Player and chack their stack size and crads taken after one turn")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game1(p1, p2);
    game1.playTurn();

    CHECK(p1.stacksize() + p1.cardesTaken() + p2.stacksize() + p2.cardesTaken() == 52);
    int max = (p1.cardesTaken()>p2.cardesTaken())? p1.cardesTaken():p2.cardesTaken();
    CHECK(p1.stacksize() == 26 - (max / 2));//after one turn (draw or not) each player has [(26 cards)-(the number of cards the winner took\2)]
    CHECK(p2.stacksize() == 26 - (max / 2));
}

TEST_CASE("Create a Game with two Player and chack their stack size and crads taken after one game")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game1(p1, p2);
    game1.playAll();
    CHECK(p1.stacksize() == 0);
    CHECK(p2.stacksize() == 0);
    CHECK(p1.cardesTaken() + p2.cardesTaken() == 52);
}

TEST_CASE("Create a Game with two Player and chack that the print function before starting the game throw eror")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game1(p1, p2);
    CHECK_THROWS(game1.printLastTurn());
    CHECK_THROWS(game1.printWiner());
    CHECK_THROWS(game1.printLog());
}

TEST_CASE("Create a Game with two Player and chack that the print function after starting the game not throw eror")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game1(p1, p2);
    game1.playAll();
    CHECK_NOTHROW(game1.printLastTurn());
    CHECK_NOTHROW(game1.printWiner());
    CHECK_NOTHROW(game1.printLog());
}
