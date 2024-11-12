#include <iostream>
#include <vector>
#include "Player.h"

#ifndef ATP_H
#define ATP_H

class ATP{
    private:
        std::vector<Player*> players;
        
        /*
        ** COMPLEJIDAD **
        * Mejor caso: O(1)
        * Caso promedio: O(1)
        * Peor caso: O(1)
        */
        void swap(int i, int j){
            Player* aux = players[i];
            players[i] = players[j];
            players[j] = aux;
        }

    public:
        ATP(){}

        /*
        ** COMPLEJIDAD **
        * Mejor caso: O(n)
        * Caso promedio: O(n)
        * Peor caso: O(n)
        */
        ATP(std::vector<Player*> player_list){
            players.resize(player_list.size());
            for(unsigned int i = 0; i < player_list.size(); i++){
                players[i] = player_list[i];
            }
        };

        /*
        ** COMPLEJIDAD **
        * Mejor caso: O(n)
        * Caso promedio: O(n)
        * Peor caso: O(n)
        */
        void addPlayerList(std::vector<Player*> player_list){
            players.resize(player_list.size());
            for(unsigned int i = 0; i < player_list.size(); i++){
                players[i] = player_list[i];
            }
        }

        /*
        ** COMPLEJIDAD **
        * Mejor caso: O(1)
        * Caso promedio: O(1)
        * Peor caso: O(1)
        */
        void addPlayer(Player* player){
            this-> players.push_back(player);
        }

        /*
        ** COMPLEJIDAD **
        * Mejor caso: O(n)
        * Caso promedio: O(n^2)
        * Peor caso: O(n^2)
        */
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

        /*
        ** COMPLEJIDAD **
        * Mejor caso: O(n)
        * Caso promedio: O(n)
        * Peor caso: O(n)
        */
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

        /*
        ** COMPLEJIDAD **
        * Mejor caso: O(1)
        * Caso promedio: O(n)
        * Peor caso: O(n)
        */
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