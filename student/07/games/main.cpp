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

using std::cout, std::map, std::cin, std::endl, std::vector;

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
    unsigned long int DATA_ALKIOT_RIVILLA = 3;

    // Kysytään tiedoston nimeä
    string tiedoston_nimi;
    cout << "Give a name for input file: ";
    cin >> tiedoston_nimi;

    // Avataan tiedosto
    std::ifstream tiedosto(tiedoston_nimi);

    // Kokeillaan jos tiedostoa ei löydy
    if (not tiedosto){
        cout << "Error: File could not be read." << endl;
        return EXIT_FAILURE;
    }
    // Luodaan map johon tallennetaan pelien tiedot
    map<string, Peli> pelit;

    vector<string> splitattu_rivi;
    string rivi;
    while (std::getline(tiedosto, rivi)){
        splitattu_rivi = split(rivi);

        if (splitattu_rivi.size() != DATA_ALKIOT_RIVILLA){

            cout << "Error: Invalid format in file." << endl;
            return EXIT_FAILURE;
        }
        // Jos tidot ovat oikeat tallennetaan ne muuttujiin
        string pelin_nimi = splitattu_rivi.at(0);
        string pelaajan_nimi = splitattu_rivi.at(1);
        int pisteet = stoi(splitattu_rivi.at(2));

        // Käydään läpi map ja etsitään pelin nimi pelit mapista
        map<string, Peli>::iterator nimien_lapikaynti = pelit.find(pelin_nimi);
        // jos löytyy niin lisätään pelaaja peli objektiin
        if (nimien_lapikaynti != pelit.end()){
            pelit.at(pelin_nimi).add_player(pelaajan_nimi, pisteet);

        } else {
            // jos peliä ei ole vielä luotu, niin luodaan se mappiin
            pelit.insert({pelin_nimi, Peli(pelaajan_nimi)});

            // lisätään pelaaja uuteen peliin
            pelit.at(pelin_nimi).add_player(pelaajan_nimi, pisteet);
        }

    }
    for (const auto a : pelit){
        cout << a.first << endl;
    }


    return EXIT_SUCCESS;
}
