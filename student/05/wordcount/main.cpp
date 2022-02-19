#include <iostream>
#include <fstream>
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
    map<string, vector<int>> luvut;
    cout << "Input file: ";
    string tiedoston_nimi;
    getline(cin, tiedoston_nimi);

    ifstream tiedosto(tiedoston_nimi);
    if (not tiedosto){
        cout << "Error! The file "<< tiedoston_nimi <<" cannot be opened." << endl;
        return EXIT_FAILURE;
    }else {
        int rivinum = 1;

        string rivi;
        vector<string> arvot;
        while (getline(tiedosto, rivi)) {
            arvot = split(rivi, ' ');
            for(string sana:arvot){
                map<string, vector<int>>::iterator itm = luvut.find(sana);
                if (itm != luvut.end()){
                    if (itm->second.back() != rivinum){
                        itm->second.push_back(rivinum);
                    }
                } else{
                    luvut.insert({sana,{rivinum}});
                }
            }
            rivinum += 1;
        }
    }
    tiedosto.close();
    for (auto tieto: luvut){
        cout << tieto.first << " " << tieto.second.size() << ": ";
        for(int osumat: tieto.second){
            cout << osumat;
            if (osumat !=tieto.second.back()){
                cout << ", ";
            }
        }
        cout << endl;
    }
    return EXIT_SUCCESS;
}
