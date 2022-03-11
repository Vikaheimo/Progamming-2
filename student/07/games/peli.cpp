/*  COMP.CS.100 Project 2: GAME STATISTICS
 *  Kuvaus:
 *      Luokka pelien tietojen käsittelyyn.
 *  
 *  Metodit:
 *      get_game_name = palauttaa pelin / olion nimen
 *      remove_player = poistaa pelaajan mapista
 *      add_player = lisää pelaajan tai muokaa pelaajaa mapissa
 *      get_player_points = palauttaa pelaajien nimet ja pisteet
 *      check_if_player_exists = palauttaa löytyykö pelaajaa pelistä
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

/*
* Luokan konstruktori, joka ottaa argumenttinä pelin nimen, ja tallentaa sen
**/
Peli::Peli()
    {

}


/*
* Metodi jolla voidaan poistaa pelaaja pelistä, jolloin palautetaan true. Jos pelaajaa
* ei löydy, niin palautetaan vain false.
*
**/
bool Peli::remove_player(string pelaajan_nimi){
    // tutkitaan ensin jos pelaajaa löytyy mapista
    if (check_if_player_exists(pelaajan_nimi)){
        // jos on niin poistetaan se
        pelaajat_.erase(pelaajan_nimi);
        return true;


    } else {
        // jos pelaajaa ei ole palautetaan false
        return false;
    }
}

/*
* Metodi jolla voidaan lisätä pelaaja peliin tai muokata pelaajan pisteitä.
* Jos pelaajaa ei ole olemassa, niin lisätään se mappiin, ja jos taas se löytyy
* niin muokataan sen pistemäärää.
**/
void Peli::add_player(std::string pelaajan_nimi, int pisteet){

    // tutkitaan jos pelaaja on jo mapissa
    if(check_if_player_exists(pelaajan_nimi)){
        // jos pelaaja on jo määrielty niin muokataan sen pistemäärä
        pelaajat_.at(pelaajan_nimi) = pisteet;

    } else{
        // jos pelaajaa ei vielä ole niin lisätään pelaaja mappiin
        pelaajat_.insert({pelaajan_nimi, pisteet});
    }


}

/*
* Metodi joka palauttaa pelaajien nimet ja pistetilanteet mappina
**/
map <string, int> Peli::get_player_points(){
    return pelaajat_;
}

/*
* Metodi joka palauttaa löytyykö pelaajaa mapista. Jos löytyy niin palauttaa true,
* jos ei niin palauttaa false.
**/
bool Peli::check_if_player_exists(string pelaajan_nimi){
    // ludoaan iteraattori joka käy läpi mapin arvot ja tarkistaa löytyyköö pelaajaa
    map<string, int>::iterator nimien_lapikaynti = pelaajat_.find(pelaajan_nimi);

   // jos pelaaja on olemassa
    if(nimien_lapikaynti != pelaajat_.end()){
        return true;

    } else{
        // jos pelaajaa ei vielä ole
        return false;
        
    }
}

