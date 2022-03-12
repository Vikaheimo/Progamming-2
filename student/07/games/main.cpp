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
#include <set>
#include <algorithm>

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


/* Funtio joka lajittelee mapin sen valueiden mukaan, 
 * ja palauttaa sen mappina
 * */
map<int, string> sort_map_by_values(map<string, int> map_to_sort){
    string monta_arvoa = ", ";

    // luodaan map, jotta voidaan tallentaa saman pisteen omaavat pelaajat
    map<int, string> sorted_map;
    for(auto& pair_data : map_to_sort){
        int pistetilanne = pair_data.second;
        string pelaajan_nimi = pair_data.first;

        // tarkistetaan onko mapin avaimena jo haluttua arvoa
        if (sorted_map.count(pistetilanne)){
            sorted_map.at(pistetilanne) += monta_arvoa + pelaajan_nimi;
        } else {
            // lisätään mappiin uusi arvo
            sorted_map.insert(std::make_pair(pistetilanne, pelaajan_nimi));
        }
    }
    return sorted_map;
}

/* Funtio joka käy mapin läpi ja palauttaa sen avainten arvot vektorissa.
 * */
vector<string> return_all_games(const map<string, Peli*> pelit){
    vector<string> return_vector;

    // luodoaan iteraattori ja iteroidaan pelien nimien läpi
    map<string, Peli*>::const_iterator nimien_lapi;
    
    for (nimien_lapi = pelit.begin();
     nimien_lapi != pelit.end(); nimien_lapi++){
        
        // lisätään vektoriin uusi arvo
        return_vector.push_back(nimien_lapi ->first);
    }

    return return_vector;
}

/* Funtio joka käy mapin läpi ja palauttaa löytyykö siitä tiettyä peliä
 * */
bool is_game_existing(const map<string, Peli*> pelit, string pelin_nimi){
    // ludoaan iteraattori joka käy peli mapin läpi ja etsi pelin nimen siitä
    map<string, Peli*>::const_iterator nimen_etsija = pelit.find(pelin_nimi);
    return nimen_etsija != pelit.end();
}
/* Funtio joka tulostaa pelaajat pistetilanteen mukaisessa järjestyksessä
 * */
void print_game_status(map<string, Peli*> pelit, string pelin_nimi){

    // tallennetaan halutun pelin pistetilanne ja lajitelaan se arvojen mukaan
    map<string, int> pistetilanne = pelit.at(pelin_nimi) ->get_player_points();
    map<int, string> pistetilanne_sorted= sort_map_by_values(pistetilanne);

    // käydään mapin läpi ja tulostetaan sen tiedot
    for (auto& pelaajan_tiedot : pistetilanne_sorted){
        cout << pelaajan_tiedot.first << " : " <<
                pelaajan_tiedot.second << endl;
    }

}

/* Funtio jolla saadaan mapin avaimista set
 * */
std::set<string> map_keys_to_set(map<string, int> input_map){
    std::set<string> return_set;
    for(auto& map_data : input_map){
        return_set.insert(map_data.first);
    }
    return return_set;
}
/* Funtio joka tulostaa pelaajat pistetilanteen mukaisessa järjestyksessä
 * */
std::set<string> return_all_player_names(map<string, Peli*> pelit){
    std::set<string> nimet;
    for (auto& peli : pelit){
        map<string, int> pelin_kaikki_tieto = peli.second ->get_player_points();
        nimet.merge(map_keys_to_set(pelin_kaikki_tieto));
    }
    return nimet;
}

/* Funtio jolla saadaan tietyn pelaajan kaikki pelit takaisin vektorina
 * */
vector<string> get_player_games(map<string, Peli*> all_games, string player_name){
    vector<string> player_games;
    for (auto& game : all_games){
        if(game.second ->check_if_player_exists(player_name)){
            player_games.push_back(game.first);
        }
    }
    return player_games;
}

/* Funtio jossa ohjelman komento-osuus pyörii. Kysyy joka kerta komentoa
 * ja sen parametrejä, tulostaa "Invalid input" jos syötteessä on jotkin
 * pielessä. Muuten suorittaa annetun komennon.
 * */
void commands_loop(map<string, Peli*>& pelit){
    // alustetaan muuttujat
    string komento_ja_parametrit;
    const int MIN_PARAMETRIEN_MAARA = 0;
    const int TYHJA_VEKTORI = 0;

    while (true){
        cout << "games> ";

        // tallennetetaan komento ja sen sen parametrit
        std::getline(cin, komento_ja_parametrit);
        vector<string> komento_osissa = split(komento_ja_parametrit, ' ');

        // argumenttien määrä on yhden pienempää kuin
        // koko komento jaettuna osiin
        int parametrien_maara = komento_osissa.size() - 1;

        if (parametrien_maara < MIN_PARAMETRIEN_MAARA){
            cout << "Error: Invalid input." << endl;
            continue;
        } else if (parametrien_maara){}

        // komento löytyy ensimmäisenä
        string komento = komento_osissa.at(0);

        // muokataan komento isoille kirjaimille
        std::transform(komento.begin(), 
        komento.end(), komento.begin(), ::toupper);

        // pitkä if - else if osio komennon käsittelyyn
        if (komento == "QUIT"){
            return;

        } else if(komento == "ALL_GAMES"){
            cout << "All games in alphabetical order:" << endl;

            // tallenetaan pelit vektoriin
            vector<string> kaikki_pelit = return_all_games(pelit);

            for(const string &pelin_nimi : kaikki_pelit){
                cout << pelin_nimi << endl;
            }
            // ohitetaan viimeinen print, koska tarpeeksi parametreja
            continue;
            
        } else if(komento == "GAME"){
            if (parametrien_maara >= 1){

                // hankitaan komennon ainoa parametri
                string pelin_nimi = komento_osissa.at(1);

                // tarkistetaan löytyykö peliä, jos ei niin tulostetaan
                // virheilmoitus
                if (is_game_existing(pelit, pelin_nimi)){

                    cout << "Game " << pelin_nimi
                    << " has these scores and players, 
                    listed in ascending order:" << endl;

                    print_game_status(pelit, pelin_nimi);

                } else{
                    cout << "Error: Game could not be found." << endl;
                }
                // ohitetaan viimeinen print, koska tarpeeksi parametreja
                continue;
            }
            
        } else if(komento == "ALL_PLAYERS"){
            cout << "All players in alphabetical order:" << endl;

            std::set kaikki_nimet  = return_all_player_names(pelit);

            // käydään kaikki pelaajat läpi, ja tulostetaan ne yksi kerrallaan
            for (auto& nimi : kaikki_nimet){
                cout << nimi << endl;
            }
            // ohitetaan viimeinen print, koska tarpeeksi parametreja
            continue;

        } else if(komento == "PLAYER"){
            if (parametrien_maara >= 1){

                // hankitaan komennon ainoa parametri
                string pelaajan_nimi = komento_osissa.at(1);

                vector<string> games = get_player_games(pelit, pelaajan_nimi);
                
                if (games.size() == TYHJA_VEKTORI){
                    cout << "Error: Player could not be found." << endl;
                } else {
                    cout << "Player " << pelaajan_nimi 
                    << " playes the following games:" << endl;

                    // käydään vektori läpi ja tulostetaan pelit kerrallaan
                    for (string& game : games){
                        cout << game << endl;
                    }
                }
                // ohitetaan viimeinen print, koska tarpeeksi parametreja
                continue;
            }
            
            
        } else if(komento == "ADD_GAME"){
            if (parametrien_maara >= 1){

                // hankitaan komennon ainoa parametri
                string pelin_nimi = komento_osissa.at(1);

                // kokeillaan onko peliä jo olemassa 
                if (is_game_existing(pelit, pelin_nimi)){
                    cout << "Error: Already exists." << endl;

                } else{
                    // luodaan uusi peli anneutlla nimellä
                    pelit.insert(std::make_pair(pelin_nimi, new Peli));
                    cout << "Game was added." << endl;
                }
                // ohitetaan viimeinen print, koska tarpeeksi parametreja
                continue;
            }
            
        } else if(komento == "ADD_PLAYER"){
            if (parametrien_maara >= 3){

                // tallenetaan parametrit muuttujiin
                string pelin_nimi = komento_osissa.at(1);
                string pelaajan_nimi = komento_osissa.at(2);
                int pisteet = stoi(komento_osissa.at(3));
                
                // tutkitaan löytyykö peliä listasta
                if (is_game_existing(pelit, pelin_nimi)){

                    // tallennetaan uusi pelaaja luokkaan
                    pelit.at(pelin_nimi) -> add_player(pelaajan_nimi, pisteet);

                    cout << "Player was added." << endl;

                } else{
                    // jos peliä ei löydy, niin tulostetaan virheilmoitus
                    cout << "Error: Game could not be found." << endl;
                }

                // ohitetaan viimeinen print, koska tarpeeksi parametreja
                continue;
            }
            
        } else if(komento == "REMOVE"){
            if (parametrien_maara >= 1){
                
                //tallennetaan parametri muuttujaan
                string pelaajan_nimi = komento_osissa.at(1);
                
                // tallennetaan kaikki pelaajat set:iin
                std::set<string> kaikki_pelaajat = return_all_player_names(pelit);

                // kokeillaan onko pelaaja olemassa
                if (kaikki_pelaajat.count(pelaajan_nimi)){
                    // käydään kaikki pelit läpi ja poisteaan kaista haluttu pelaaja
                    for (auto& peli : pelit){
                        peli.second -> remove_player(pelaajan_nimi);
                    }
                    // koska poistaminen onnistui tulostetaan ilmoitus käyttäjälle
                    cout << "Player was removed from all games." << endl;

                } else {
                    // koska pelaajaa ei löytynyt, niin tulostetaan virheilmoitus
                    cout << "Error: Player could not be found." << endl;
                }
                // ohitetaan viimeinen print, koska tarpeeksi parametreja
                continue;
            }
        }
        // jos komenolla on liian vähän parametrejä
        cout << "Error: Invalid input." << endl;

    }
}


int main(){
    const unsigned long int DATA_ALKIOT_RIVILLA = 3;

    // Kysytään tiedoston nimeä
    string tiedoston_nimi;
    cout << "Give a name for input file: ";
    std::getline(cin, tiedoston_nimi);

    // Avataan tiedosto
    std::ifstream tiedosto(tiedoston_nimi);

    // Kokeillaan jos tiedostoa ei löydy
    if (not tiedosto){
        cout << "Error: File could not be read." << endl;
        return EXIT_FAILURE;
    }
    // Luodaan map johon tallennetaan pelien tiedot
    map<string, Peli*> pelit;

    vector<string> splitattu_rivi;
    string rivi;
    while (std::getline(tiedosto, rivi)){
        splitattu_rivi = split(rivi);

        // tutkitaan onko tiedoston sislätämä data oikeanlaista
        if (splitattu_rivi.size() != DATA_ALKIOT_RIVILLA){
            // suljetaan tiedosto ja tulostetaan virheilmoitus
            tiedosto.close();
            cout << "Error: Invalid format in file." << endl;
            return EXIT_FAILURE;
        }
        // Jos tidot ovat oikeat tallennetaan ne muuttujiin
        string pelin_nimi = splitattu_rivi.at(0);
        string pelaajan_nimi = splitattu_rivi.at(1);
        int pisteet = stoi(splitattu_rivi.at(2));

        // Käydään läpi map ja etsitään pelin nimi pelit mapista
        map<string, Peli*>::iterator pelin_nimien_lapikaynti = pelit.find(pelin_nimi);

        // jos peliä ei vilä löydy, niin tallennetaan se pelit mappiin
        if (pelin_nimien_lapikaynti == pelit.end()){
            pelit.insert({pelin_nimi, new Peli()});

        }
        // lisätään pelaaja pelit mappiin oikean pelin alle
            pelit.at(pelin_nimi) -> add_player(pelaajan_nimi, pisteet);
    }

    // suljetaan tiedosto ja avataan ohjelman command loop
    tiedosto.close();
    commands_loop(pelit);
    return EXIT_SUCCESS;
}
