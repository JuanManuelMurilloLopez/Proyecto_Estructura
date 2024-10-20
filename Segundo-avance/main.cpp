#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "Player.h"
#include "Tournament.h"
#include "ATP.h"


std::vector<Player*> jugadores;
ATP ranking_ATP;

void cargarJugadores(){
    std::ifstream archivo("jugadores.csv");
    std::string linea, nombre, utr_str, atp_str, edad_str;
    jugadores.resize(NUMBER_OF_PLAYERS);
    if(!archivo.is_open()){
    std::cerr << "Error al abrir el archivo" << "\n";
    }
    std::getline(archivo, linea);
    int i = 0;
    while(std::getline(archivo, linea)){
    std::stringstream ss(linea);

    std::getline(ss, nombre, ',');
    std::getline(ss, utr_str, ',');
    std::getline(ss, atp_str, ',');
    std::getline(ss, edad_str, ',');

    float utr = std::stof(utr_str);
    int atp = std::stoi(atp_str);
    int edad = std::stoi(edad_str);
    jugadores[i] = new Player(nombre, utr, atp, edad);
    i++;
    }
};


int main() {
    cargarJugadores();
    ranking_ATP.addPlayerList(jugadores);
    unsigned int opcion = 1;;
    std::cout<< "Menu\n";
    while(opcion > 0){
        std::cout << "\n1- Aniadir Jugador\n";
        std::cout << "2- Consultar Ranking ATP\n";
        std::cout << "3- Consultar Rating UTR\n";
        std::cout << "4- Consultar informacion de jugador\n";
        std::cout << "5- Torneo\n";
        std::cout << "0- Salir\n";
        std::cout << "Opcion: ";
        std::cin >> opcion;
        if(opcion == 1){
            std::string nom;
            int edad;
            int ATP;
            float UTR;
            std::cout << "Nombre: ";
            std::cin.ignore();
            std::getline(std::cin, nom);
            std::cout << "Edad: ";
            std::cin >> edad;
            std::cout << "Puntos ATP: ";
            std::cin >> ATP;
            std::cout << "Rating UTR: ";
            std::cin >> UTR;
            ranking_ATP.addPlayer(new Player(nom, UTR, ATP, edad));
        }
        if(opcion == 2){
            ranking_ATP.showRanking("ATP");
        }
        if(opcion == 3){
            ranking_ATP.showRanking("UTR");
        }
        if(opcion == 4){
            std::string nombre;
            std::cout << "Nombre del jugador: ";
            std::cin.ignore();
            std::getline(std::cin, nombre);
            std::cout << ranking_ATP.getPlayer_byName(nombre)->toString();
        }
        if(opcion == 5){
            Tournament ausGS("Australia", "Grand Slam", jugadores);
            std::cout<<"\n Torneo Demo: Australia Grand Slam";
            bool continuar = true;
            while(continuar && ausGS.hasnt_finished()){
                ausGS.simulateRound();
                std::cout<<"\n Desea continuar de ronda? \n 1- SI \n 0- NO \n";
                std::cin>>continuar;
            }
        }
    }
  return 0;
}
