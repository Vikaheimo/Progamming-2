/*  COMP.CS.100 Project 2: GAME STATISTICS
 *  Kuvaus:
 *      Luokka pelien tietojen käsittelyyn.
 *
 *  Tekijä:
 *      Nimi: Vili Ikäheimo
 *      Opiskelijanumero: 150286761
 *      Käyttäjätunnus: csviik
 *      E-Mail: vili.ikaheimo@tuni.fi
 * */
#include "peli.hh"
#include <string>
#include <map>

using std::string, std::map, std::iterator;

Peli::Peli(string pelin_nimi):
    pelin_nimi_(pelin_nimi){

}

string Peli::get_game_name(){
    return pelin_nimi_;
}

bool Peli::remove_player(string pelaajan_nimi){

}

void Peli::add_player(std::string pelaajan_nimi, int pisteet){
    pelaajat_.at(pelaajan_nimi) = pisteet;

}

std::map<string, int> Peli::get_pelaajien_pisteet(){

}

bool Peli::check_if_player_exists(string pelaajan_nimi)
{

}


