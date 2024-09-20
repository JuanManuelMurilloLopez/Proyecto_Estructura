#include <iostream>
#include <vector>
#include "Player.h"

#ifndef ATP_H
#define ATP_H

class ATP{
    private:
        std::vector<Player*> players;
        void swap(int i, int j){
            Player* aux = players[i];
            players[i] = players[j];
            players[j] = aux;
        }

    public:
        ATP(){}
        ATP(std::vector<Player*> player_list){
            players.resize(player_list.size());
            for(unsigned int i = 0; i < player_list.size(); i++){
                players[i] = player_list[i];
            }
        };
        void addPlayerList(std::vector<Player*> player_list){
            players.resize(player_list.size());
            for(unsigned int i = 0; i < player_list.size(); i++){
                players[i] = player_list[i];
            }
        }
        void addPlayer(Player* player){
            this-> players.push_back(player);
        }
        //opcion -> UTR/ATP
        void sortPlayers(std::string opcion){
            //Insertion sort
            if(opcion == "ATP"){
                for(unsigned int i = 1; i < players.size(); i++){
                    for(unsigned int j = i; j > 0 && players[j]->getATP_points() > players[j - 1]->getATP_points(); j--){
                        swap(j, j - 1);
                    }
                }
            }
            if(opcion == "UTR"){
                for(unsigned int i = 1; i < players.size(); i++){
                    for(unsigned int j = i; j > 0 && players[j]->getUTR_ranking() > players[j - 1]->getUTR_ranking(); j--){
                        swap(j, j - 1);
                    }
                }
            }
        }
        //opcion -> UTR/ATP
        void showRanking(std::string opcion){
            sortPlayers(opcion);
            if(opcion == "ATP"){
                for(unsigned int i = 0; i < players.size(); i++){
                    std::cout << (i+1) << "- " << players[i]->getName() << ": "<< players[i]->getATP_points() << "\n";
                }
            }
            if(opcion == "UTR"){
                for(unsigned int i = 0; i < players.size(); i++){
                std::cout << (i+1) << "- " << players[i]->getName() << ": "<< players[i]->getUTR_ranking() << "\n";
                }
            }
            
        }
        Player* getPlayer_byName(std::string nam){
            for(unsigned int i = 0; i < players.size(); i++){
                if(players[i]->getName() == nam){
                    return players[i];
                }
            }
            return NULL;
        }
};

#endif