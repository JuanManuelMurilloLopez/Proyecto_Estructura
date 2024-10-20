#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <tuple>
#include <stdlib.h>
#include "Player.h"
#include "ATP.h"

#ifndef TOURNAMENT_H
#define TOURNAMENT_H

const int NUMBER_OF_PLAYERS = 128;

class Tournament{
    private:
        std::queue<std::tuple<Player*,Player*>> matches;
        unsigned int numOfPlayers;
        //std::queue<Player*> players;
        std::string name;
        std::array<int, 8> points_sistem;
        unsigned int round;
        unsigned int number_of_rounds;
        Player* winner;
        bool finished;

        Player* playMatch(Player* player1, Player* player2, int matchNum){
            std::cout<<"\nPartido numero: "<<matchNum <<" -> "<< player1->getName() << " vs " << player2->getName();
            //Que gane un jugador random
            if(rand() < RAND_MAX / 2){
                ///Gana jugador 1///
                //Actualizamos los datos del jugador que perdió
                if(round != 0){ //Solo si no es la primer ronda se le añaden los puntos
                    player2->addPoints(points_sistem[round - 1]);
                }
                std::cout<<"\n Ganador: "<< player1->getName();
                return player1;
            }
            else{
                //Gana jugador 2
                if(round != 0){
                    player1->addPoints(points_sistem[round - 1]);
                }
                std::cout<<"\n Ganador: "<< player2->getName();
                return player2;
            }
        }

    public:
        Tournament(std::string name, std::string category, std::vector<Player*> player_list){
            for(unsigned int i = 0; i < NUMBER_OF_PLAYERS / 2; i++){
                matches.push(std::make_tuple(player_list[i], player_list[player_list.size() - i - 1]));
            }
            this->numOfPlayers = matches.size() * 2;
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
            number_of_rounds = points_sistem.size() - 1;
            finished = false;
            winner = NULL;
        }

        void simulateRound(){
            //Si el juego es la final del torneo
            int matchNum = 1;
            if(round == number_of_rounds){
                //Lógica para el juego de la final
                std::cout<<"\n ***FINAL***";
                winner = playMatch(std::get<0>(matches.front()), std::get<1>(matches.front()), matchNum);
                winner->addPoints(points_sistem[round]);
                finished = true;
                std::cout<<"\n Campeon del Torneo: "<< winner->getName();
                std::cout<<"\n \n Consulta el nuevo Ranking";
                return;
            }
            unsigned int numOfMatches = numOfPlayers / 2;

            for(unsigned int i = 0; i < numOfMatches / 2; i++){
                Player* winner1 = playMatch(std::get<0>(matches.front()), std::get<1>(matches.front()), matchNum);
                matches.pop();
                matchNum++;
                Player* winner2 = playMatch(std::get<0>(matches.front()), std::get<1>(matches.front()), matchNum);
                matches.pop();
                matchNum++;
                matches.push({winner1, winner2});
            }
            numOfPlayers = numOfPlayers / 2;
            round = round + 1;
        }
        bool hasnt_finished(){return !finished;};
        unsigned int getRound(){return round;};
        std::string toString(){
            std::string tournament_string;
            return tournament_string;
        }

};


#endif /*TOURNAMENT_H*/