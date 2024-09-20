#include <iostream>
#include <vector>
#include <array>
#include "Player.h"
#include "ATP.h"

#ifndef TOURNAMENT_H
#define TOURNAMENT_H

const int NUMBER_OF_PLAYERS = 96;

class Tournament{
    private:
        std::vector<Player*> players;
        std::string name;
        std::array<int, 8> points_sistem;
        unsigned int round;

    public:
        Tournament(std::string name, std::string category, std::vector<Player*> player_list){
            players.resize(NUMBER_OF_PLAYERS);
            for(unsigned int i = 0; i < NUMBER_OF_PLAYERS; i++){
                players[i] = player_list[i];
            }
            this->name = name;
            this->round = 0;
            if(category == "Grand Slam"){
                points_sistem = {10, 50, 100, 200, 400, 800, 1300, 2000};
            }
            if(category == "Masters 1000"){
                points_sistem = {10, 30, 50, 100, 200, 400, 650, 1000};
            }
            if(category == "ATP 500"){
                points_sistem = {0, 0, 25, 50, 100, 200, 330, 500};
            }
            if(category == "ATP 250"){
                points_sistem = {0, 0, 13, 25, 50, 100, 165, 250};
            }
        }
        void makeBraket(){

        }
        std::string toString(){
            std::string tournament_string;
            return tournament_string;
        }

};


#endif