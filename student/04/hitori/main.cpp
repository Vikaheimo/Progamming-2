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
        std::cout << "Select start (R for random, I for input): ";
        std::cin >> tapa;

        if (tapa == "r" or tapa == "R"){
            int seed;
            std::cout << "Enter seed value: ";
            std::cin >> seed;
            default_random_engine gen(seed);
            uniform_int_distribution<int> distr(1,5);
            std::vector <int>rivi;
            for (int rivinum = 0;rivinum < 5; rivinum++){
                for (int sarakenum = 0;sarakenum < 5; sarakenum++){
                    rivi.push_back(distr(gen));

                }
                lauta.push_back(rivi);
                rivi.clear();

            }
            return lauta;
        }
        else if (tapa == "I" or tapa == "i"){
            std::cout << "Input: ";
            int luku;

            std::vector <int>rivi;
            for (int rivinum = 0;rivinum < 5; rivinum++){
                for (int sarakenum = 0;sarakenum < 5; sarakenum++){
                    std::cin >> luku;
                    rivi.push_back(luku);

                }
                lauta.push_back(rivi);
                rivi.clear();

            }
            return lauta;
        }
    }

}
// funktio jolla voidaan poistaa halutusta paikasta numero, jos kyseinen paikka ei ole pelilaudalla tai
// numero on jo poistettu tulostaa funktio virheilmoituksen pelaajalle
bool poista_laudalta(std::vector <std::vector<int>> &lauta, int x, int y){
    if (x < 1 or x > 5 or y < 1 or y > 5){
        std::cout << "Out of board" << std::endl;
        return false;
    } else if (lauta.at(y-1).at(x-1) == 0){
        std::cout << "Already removed" << std::endl;
        return false;
    } else {
        lauta[y-1][x-1] = 0;
        return true;
    }
}

int main()
{
    auto pelilauta = taytto();
    print(pelilauta);
    poista_laudalta(pelilauta, 1,1);
    print(pelilauta);
    poista_laudalta(pelilauta, 1,1);
    poista_laudalta(pelilauta, 0,1);
    return 0;
}
