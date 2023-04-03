#pragma once
#include <iostream>
#include "card.hpp"
#include "player.hpp"
using namespace std;


namespace ariel{
    class Game{
        Player p1;
        Player p2;
        public:
        Game(Player p1, Player p2){}
        

        void playTurn(){}
        void printLastTurn(){}

        void playAll(){}
        void printWiner(){}
        void printLog(){}
        void printStats(){}

    };
    
    
}