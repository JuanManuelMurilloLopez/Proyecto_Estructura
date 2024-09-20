#include <iostream>
#include <sstream>

#ifndef PLAYER_H
#define PLAYER_H

class Player{
    private:
        std::string name;
        int age;
        float UTR_ranking;
        int ATP_points;
    public:
        Player(std::string name, float UTR_ranking, int ATP_points, int age){
            this-> name = name;
            this-> UTR_ranking = UTR_ranking;
            this-> ATP_points = ATP_points;
            this-> age = age;
        };
        std::string getName(){
            return name;
        }
        int getAge(){
            return age;
        }
        float getUTR_ranking(){
            return UTR_ranking;
        }
        void updateUTR_ranking(float new_ranking){
            this-> UTR_ranking =  new_ranking;
        }
        int getATP_points(){
            return ATP_points;
        }
        void addPoints(int new_points){
            this->ATP_points += new_points;
        }
        std::string toString(){
            std::ostringstream oss;
            oss << "Nombre: " << name << "\n"
            << "Edad: " << age << "\n"
            << "Ranking UTR: " << UTR_ranking << "\n"
            << "Puntos ATP: " << ATP_points << "\n";
            return oss.str();
        }
        bool operator<(const Player& other_player) const{
            return this->ATP_points < other_player.ATP_points;
        }
        bool operator>(const Player& other_player) const{
            return this->ATP_points > other_player.ATP_points;
        }
        bool operator==(const Player& other_player) const{
            return ATP_points == other_player.ATP_points;
        }
        
};

#endif