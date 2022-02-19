#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

std::vector <std::string> split(std::string text, char separator, bool skip=false){
    std::string jono;
    std::vector <std::string> arvot;
    for (auto character : text ){
        if (character != separator){
            jono += character;
        } else if (jono.size() != 0 or not skip){
           arvot.push_back(jono);
           jono = "";
        }
    }
    arvot.push_back(jono);
    return arvot;
}

int main()
{
    string input_tiedosto_nimi;
    cout << "Input file: ";
    getline(cin, input_tiedosto_nimi);
    ifstream input_tiedosto(input_tiedosto_nimi);

    if (not input_tiedosto){
        cout << "Error! The file " << input_tiedosto_nimi << " cannot be opened." << endl;
        return EXIT_FAILURE;
    } else{
        string rivi;
        map<string, int> pisteet;
        vector<string> arvot;
        while (getline(input_tiedosto,  rivi)){
            arvot = split(rivi,':');
            map<string, int>::iterator it = pisteet.find(arvot.at(0));
            if (it != pisteet.end()){
                it ->second += stoi(arvot.at(1));
            } else{
                pisteet.insert({arvot.at(0), stoi(arvot.at(1))});
            }

        }
        input_tiedosto.close();
        cout << "Final scores:" << endl;
        for (auto tieto: pisteet){
            cout << tieto.first << ": " << tieto.second << endl;
        }
        return EXIT_SUCCESS;
    }
}
