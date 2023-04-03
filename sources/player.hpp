#pragma once
#include <iostream>
#include <string>
#include "card.hpp"
using namespace std;

namespace ariel{
    class Player{
        public:
            string name;
            Card deck[52];
            int numOfCard;

        
        Player (string name){}
        Player(){}
        int stacksize(){return 0;}
        int cardesTaken(){return 0;}
    };
}