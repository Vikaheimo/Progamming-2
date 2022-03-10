/*  COMP.CS.100 Project 2: GAME STATISTICS
 *  Kuvaus:
 *
 *  Ohjelema on tarkoitettu pelien pelaajien ja pisteiden tallentamiseen.
 *  Ohjlema lukee annetusta tiedostosta pelaajien nimet, pisteet ja pelin nimen
 *  muodossa:
 *      Pelin nimi;Pelaajan nimi;pistemäärä
 *  Jos tiedostoa ei voida lukea ohjelma antaa varoituksen, jos taas tiedosto on
 *  väärässä muodosssa niin ojelma varoittaa siitäkin. Jos taas tiedosto on kunnossa,
 *  niin päästään komento-osioon, jossa komentoja ovat:
 *
 *      Quit = Poistuu ohjelmasta
 *      ALL_GAMES = Tulostaa pelien nimet aakkosjärjestykesssä
 *      GAME <pelin nimi>= Tulostaa annetun pelin tuokset
 *      ALL_PLAYERS = Tulostaa kaikkien pelaajien nimet aakkosjärjestykesssä
 *      PLAYER <pelaajan nimi> = Tulostaa kaikki pelit jossa pelaaja on
 *      ADD_GAME <pelin nimi> = Lisää uuden pelin ilman pelaajia tai pisteitä
 *      ADD_PLAYER <pelin nimi> <pelaajan nimi> <pisteet> = lisää pelaajan haluttuun
 *              peliin tietyillä pisteillä
 *      REMOVE <pelaajan nimi> = Poistaa halutun pelaajan kaikista peleistä
 *
 *      HUOM! jos halutaan komento-osiossa käsitellään nimiä (pelin tai pelaajan)
 *      jotka ovat kaksiosasia esim. Eeli Esimerkki, niin pitää se antaa muodossa
 *      "Eeli Esimerkki", eli esim. ADD_PLAYER "Afrikan Tähti" "Eeli Esimerkki" 200
 *
 *  Tekijä:
 *      Nimi: Vili Ikäheimo
 *      Opiskelijanumero: 150286761
 *      Käyttäjätunnus: csviik
 *      E-Mail: vili.ikaheimo@tuni.fi
 *
 *  Huomioita ohjelmasta ja sen toteuksesta:
 *      Sisältää luokan peli, joka sisältää yhden pelin tiedot
 *      (pelaajat, pisteet, pelin nimi), ja metodeja sen tietojen käsittelyyn
 * */
#include <iostream>
#include <string>
#include <vector>
#include "peli.hh"
#include <fstream>

using std::cout, std::vector, std::cin;

// Casual split func, if delim char is between "'s, ignores it.
std::vector<std::string> split( const std::string& str, char delim = ';' )
{
    std::vector<std::string> result = {""};
    bool inside_quatation = false;
    for ( auto current_char : str )
    {
        if ( current_char == '"' )
        {
            inside_quatation = not inside_quatation;
        }
        else if ( current_char == delim and not inside_quatation )
        {
            result.push_back("");
        }
        else
        {
            result.back().push_back(current_char);
        }
    }
    if ( result.back() == "" )
    {
        result.pop_back();
    }
    return result;
}



int main()
{



    return EXIT_SUCCESS;
}
