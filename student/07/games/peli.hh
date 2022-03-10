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
#ifndef PELI_HH
#define PELI_HH
#include <map>
#include <string>

using std::string;
class Peli
{
public:
    Peli(string pelin_nimi);

    string get_game_name();

    bool remove_player(string pelaajan_nimi);

    void add_player(string pelaajan_nimi, int pisteet);

    std::map<string, int> get_pelaajien_pisteet();

    bool check_if_player_exists(string pelaajan_nimi);

private:
    std::map<string, int> pelaajat_;

    string pelin_nimi_;




};

#endif // PELI_HH
