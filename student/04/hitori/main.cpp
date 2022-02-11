/* Hitori
 *
 * Kuvaus:
 *   Ohjelma toteuttaa Hitori-pelin. Pelissä on peliruudukko kooltaan
 * 5 x 5. Kukin ruutu sisältää jonkin numeroista 1-5. Vaaka- ja
 * pystyriveillä voi aluksi olla useita samoja numeroita, mutta
 * tarkoituksena on poistaa numeroita niin, että kullakin vaaka- ja
 * pystyrivillä on kutakin numeroa vain yksi tai ei yhtään. Kuitenkaan
 * vierekkäisten ruutujen numeroita ei saa poistaa, eikä mikään jäljelle
 * jäävä numero (ruutu) saa jäädä irralleen muista, eli sen ympäriltä
 * (yläpuolelta, alapuolelta, vasemmalta, oikealta) ei saa poistaa
 * kaikkia numeroita.
 *   Aluksi käyttäjältä kysytään, täytetäänkö peliruudukko satunnaisesti
 * arvottavilla luvuilla 1-5 vai käyttäjän valitsemilla 25 luvulla.
 * Ensimmäisessä vaihtoehdossa käyttäjältä kysytään satunnaisluku-
 * generaattorin siemenlukua ja jälkimmäisessä häntä pyydetään syöttämään
 * 25 lukua.
 *   Joka kierroksella käyttäjältä kysytään poistettavan numeron
 * koordinaatteja eli kahta lukua. Peli päättyy pelaajan voittoon,
 * jos peliruudukon kaikilla vaaka- ja pystyriveillä esiintyy kukin
 * numero 1-5 korkeintaan kerran. Peli päättyy pelaajan häviöön,
 * jos hän poistaa jo poistetun numeron viereisen numeron tai jos
 * jokin numero jää irralleen muista.
 *   Ohjelma tarkistaa annetut koordinaatit. Koordinaattien pitää olla
 * peliruudukon sisällä, ja niiden osoittaman ruudun pitää sisältää
 * numero, eli jo poistettua numeroa ei voi poistaa toiseen kertaan.
 *   Pelin päättyessä kerrotaan, voittiko vai hävisikö pelaaja.
 *
 * Ohjelman kirjoittaja:
 * Nimi: Vili Ikäheimo
 * Opiskelijanumero: 150286761
 * Käyttäjätunnus: csviik
 * E-Mail: vili.ikaheimo@tuni.fi
 *
 * Huomioita ohjelmasta ja sen toteutuksesta:
 *
 * */
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

const unsigned int BOARD_SIDE = 5;
const unsigned char EMPTY = ' ';

// Muuttaa annetun numeerisen merkkijonon vastaavaksi kokonaisluvuksi
// (kutsumalla stoi-funktiota).
// Jos annettu merkkijono ei ole numeerinen, palauttaa nollan.
//
// Converts the given numeric string to the corresponding integer
// (by calling stoi).
// If the given string is not numeric, returns zero.
unsigned int stoi_with_check(const string& str)
{
    bool is_numeric = true;
    for(unsigned int i = 0; i < str.length(); ++i)
    {
        if(not isdigit(str.at(i)))
        {
            is_numeric = false;
            break;
        }
    }
    if(is_numeric)
    {
        return stoi(str);
    }
    else
    {
        return 0;
    }
}

// Tulostaa pelilaudan rivi- ja sarakenumeroineen.
//
// Prints the game board with row and column numbers.
void print(const std::vector <std::vector <int>> & gameboard)
{
    cout << "=================" << endl;
    cout << "|   | 1 2 3 4 5 |" << endl;
    cout << "-----------------" << endl;
    for(unsigned int i = 0; i < BOARD_SIDE; ++i)
    {
        cout << "| " << i + 1 << " | ";
        for(unsigned int j = 0; j < BOARD_SIDE; ++j)
        {
            if(gameboard.at(i).at(j) == 0)
            {
                cout << EMPTY << " ";
            }
            else
            {
                cout << gameboard.at(i).at(j) << " ";
            }
        }
        cout << "|" << endl;
    }
    cout << "=================" << endl;
}


// funktio jolla kysytään haluttu laudan täyttötapa, jonka jälkeen funktio myös palauttaa täytetyn laudan
std::vector <std::vector <int>> taytto(){
    std::string tapa;
    std::vector <std::vector <int>> lauta;
    while(true){
        // kysytään arvoa niin kauan kunnes käyttäjä antaa oikean arvon
        std::cout << "Select start (R for random, I for input): ";
        std::cin >> tapa;
        // jos käyttäjä valitsee satunnaisen täyttövaihtoehdon
        if (tapa == "r" or tapa == "R"){
            // kysytään käyttäjältä simeneluvun arvoa ja alusetaan satunnislukugeneraattori
            int seed;
            std::cout << "Enter seed value: ";
            std::cin >> seed;
            default_random_engine gen(seed);
            uniform_int_distribution<int> distr(1,5);
            std::vector <int>rivi;
            // käydään läpi kaikki pelinlaudan paikat ja luodaan arvoilla pelilauta
            for (int rivinum = 0;rivinum < 5; rivinum++){
                for (int sarakenum = 0;sarakenum < 5; sarakenum++){
                    rivi.push_back(distr(gen));

                }
                // lisätään rivi numeroita pelilaudalle ja tyhjennetään rivi vektori
                lauta.push_back(rivi);
                rivi.clear();

            }
            return lauta;
        }
        // käyttäjän arvoilla täyttämisen vaihtoehto
        else if (tapa == "I" or tapa == "i"){
            std::cout << "Input: ";
            int luku;

            std::vector <int>rivi;
            // käydään läpi kaikki pelilaudan paikat ja kysytään jokaiselle paikalle käyttäjältä arvoa
            for (int rivinum = 0;rivinum < 5; rivinum++){
                for (int sarakenum = 0;sarakenum < 5; sarakenum++){
                    std::cin >> luku;
                    rivi.push_back(luku);

                }
                // lisätään rivi numeroita pelilaudalle ja tyhjennetään rivi vektori
                lauta.push_back(rivi);
                rivi.clear();

            }
            return lauta;
        }
    }

}
// funktio jolla voidaan poistaa halutusta paikasta numero, jos kyseinen paikka ei ole pelilaudalla tai
// numero on jo poistettu tulostaa funktio virheilmoituksen pelaajalle
// paluttaa totuusarvon riippuen siitä onnistuiko laudalta numeron poistaminen
bool poista_laudalta(std::vector <std::vector<int>> &lauta, int x, int y){
    // jos x tai y ei ole pelilaudalla
    if (x < 1 or x > 5 or y < 1 or y > 5){
        std::cout << "Out of board" << std::endl;
        return false;
    // jos koorinaateista (x, y) oleva luku on jo poistetttu
    } else if (lauta.at(y-1).at(x-1) == 0){
        std::cout << "Already removed" << std::endl;
        return false;
    // poisetaan luku pelilaudalta eli siis korvataan numerolla 0
    } else {
        lauta[y-1][x-1] = 0;
        return true;
    }
}
// funktio tarkistamaan sisältääkö vektori annetun luvun
// palauttaa tottuusarvon riippuen siitä löytyykö luku vektorista
bool numero_vektorissa(std::vector <int> vektori, int numero){
    for(int x:vektori){
        if (numero == x){
            return true;
        }
    }
    return false;
}
// funktio tarkistamaan löytyykö riveiltä ja sarakkeilta eri numerot
// palauttaa arvon false jos riviltä tai sarakkeelta löytyy samat arvot
// jos kaikkien rivien ja sarakkeiden arvot ovat erialisia palautetaan true
bool pelin_voiton_tarkistus(std::vector <std::vector<int>> lauta){
    // käydään koko pelilauta läpi kahdella sisäkäisellä for loopilla
    for(int i = 0; i<5; i++){
        // alustetaan muuttujat edelliset johon tallennetaan rivin edelliset luvut.
        std::vector <int> edelliset_rivi, edelliset_sarake;
        for(int j = 0; j < 5; j++){
            // luodaan sarakkeen ja rivin arvolle muuttujat
            int rivin_arvo = lauta.at(i).at(j);
            int sarakkeen_arvo = lauta.at(j).at(i);
            //tarkistetaan jos sarakken tai rivin arvo löytyy jo niitä vastaavista vektoreista
            // jos luku on nollla eli siis poisettu hypätään sen yli
            if (numero_vektorissa(edelliset_rivi, rivin_arvo)
                and rivin_arvo != 0){
                    return false;
            } else if (numero_vektorissa(edelliset_sarake, sarakkeen_arvo) and sarakkeen_arvo != 0) {
                return false;
            }
            // jos lukuja ei ole vektoreissa niin lisätään se vataavaan vektoriin
            edelliset_rivi.push_back(rivin_arvo);
            edelliset_sarake.push_back(sarakkeen_arvo);
        }
    }
    // jos millään rivillä tai sarakkeela ei ole samaa lukua kuin kerran palautetaan true
    return true;
}
// tarkistaa onko anntetulla vektorilla peräkkäisiä nollia
// jos on palauttaa true, muutoin false
bool tarkista_perakkaiset_nollat(std::vector <std::vector<int>> lauta){
    for(std::vector<int> lista:lauta){
        for(int i=1;i<5;i++){
            // tarkistaa peräkkäiset nuerot yksi kerrallaan ovatko ne nollia
            if (lista.at(i)==lista.at(i-1) and lista.at(i-1) == 0){
                return true;
            }
        }
    }
    return false;
}
// tarkistaa numeron ympäryksen, jottei se ole irrallaan muista
// palauttaa true jos on irrallaan muuten false
bool tarkista_palan_ymparys(std::vector <std::vector<int>> lauta,int x, int y){
    // luodaan muuttujat joita käytetään ympärysten tarkastamiseen
    bool p,e,i,l;
    // jos numero on ensimmäisellä tai viimeisellä rivillä niin täytyy tarkistaa vain yksi
    // numero ympäriltä
    if (x==0){
        p = true;
        e = (lauta.at(y).at(x+1)==0);
    } else if (x==4){
        e = true;
        p = (lauta.at(y).at(x-1)==0);
    } else{
        p = (lauta.at(y).at(x+1)==0);
        e = (lauta.at(y).at(x-1)==0);
    }
    // jos numero on ensimmäisellä tai viimeisellä sarakkeella niin täytyy tarkistaa vain yksi
    // numero ympäriltä
    if (y==0){
        l = true;
        i = (lauta.at(y+1).at(x)==0);
    } else if (y==4){
        i = true;
        l = (lauta.at(y-1).at(x)==0);
    } else{
        i = (lauta.at(y+1).at(x)==0);
        l = (lauta.at(y-1).at(x)==0);
    }
    // jos kaikki arvot ovat tosi, eli siis kun kaikki ympärillä olevat arvot ovat 0
    // palauttaa true
    return (p and e and i and l);
}

// fuktio joka tarkistaa onko pelaaja hävinnyt pelin
// jos pelaaja häviää pelin, niin palttaa true, muutoin false
bool pelin_havion_tarkistus(std::vector <std::vector<int>> lauta){

    std::vector <std::vector<int>> sarakkeet;
    // käydään läpi pelilauta ja tallenettaan jokaisen sarakkeen arvo samanlaiseen vektoriiin
    // kuin pelilaudassa, tarkistetaan samalla onko palasen ympärillä vain tyhjä palasia, ja
    // jos näin on tiedämme että pelaaja on hävinnyt pelin
    for(int i=0;i<5;i++){
        std::vector<int> sarake_rivi;
        for(int j=0;j<5;j++){
            sarake_rivi.push_back(lauta.at(j).at(i));
            if (tarkista_palan_ymparys(lauta, i, j)){
                return true;
            }

        }
        sarakkeet.push_back(sarake_rivi);
    }
    // tarkistaa onko peräkkäisiä tyhjiä ruutuja riveillä tai sarakkeilla
    if (tarkista_perakkaiset_nollat(sarakkeet) or
            tarkista_perakkaiset_nollat(lauta)) {
        return true;
    } else
    return false;
}

int main()
{
    std::vector <std::vector<int>> pelilauta = taytto();
    // ulompi while loop tehdään pelin voittamiseen ja sisempi laudalta arvojen poistamiseen
    while(true) {
        std::string x;
        std::string y;
        print(pelilauta);

        // pelin voiton ja hävin tarkastus
        if (pelin_havion_tarkistus(pelilauta)){
            std::cout << "You lost" << std::endl;
            return 0;
        } else if (pelin_voiton_tarkistus(pelilauta)){
            std::cout << "You won" << std::endl;
            return 0;
        }
        while (true) {
            std::cout << "Enter removable element (x, y): ";
            std::cin >> x >> y;

            if (x=="q" or x == "Q"){
                std::cout << "Quitting" << std::endl;
                return 0;
            }
            // jos poisto onnistuu niin hypätään pois sisemmästä while-loopista
            if (poista_laudalta(pelilauta, stoi_with_check(x), stoi_with_check(y))){
                break;
            }

        }


    }
}
