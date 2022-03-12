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

using std::string, std::map;
class Peli
{
public:
    /*
    * Luodaan tyhjä konstruktori
    **/
    Peli();

    /*
    * Metodi jolla voidaan poistaa pelaaja pelistä, jolloin palautetaan true. Jos pelaajaa
    * ei löydy, niin palautetaan vain false.
    *
    **/
    bool remove_player(string pelaajan_nimi);

    /*
    * Metodi jolla voidaan lisätä pelaaja peliin tai muokata pelaajan pisteitä.
    * Jos pelaajaa ei ole olemassa, niin lisätään se mappiin, ja jos taas se löytyy
    * niin muokataan sen pistemäärää.
    **/
    void add_player(string pelaajan_nimi, int pisteet);

    /*
    * Metodi joka palauttaa pelaajien nimet ja pistetilanteet mappina
    **/
    map<string, int> get_player_points();

    /*
    * Metodi joka palauttaa löytyykö pelaajaa mapista. Jos löytyy niin palauttaa true,
    * jos ei niin palauttaa false.
    **/
    bool check_if_player_exists(string pelaajan_nimi);

private:
    // map johon tallennetaan pelaajan nimet ja pisteet
    map<string, int> pelaajat_;

};

#endif // PELI_HH
