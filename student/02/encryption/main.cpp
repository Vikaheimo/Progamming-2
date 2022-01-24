#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool kaikki_pienella(string testattava){
    for (unsigned long i=0; i<testattava.length();i++ ){
        if (tolower(testattava.at(i)) != testattava.at(i)){
            return false;
        }
    }
    return true;
}

bool kaikki_kirjaimet(string testattava){
    string kirjaimet;
    for (unsigned long i=0; i<testattava.length();i++ ){
        char c = testattava.at(i);
        if (kirjaimet.find(c) == string::npos){
            kirjaimet += c;
        }
    }
    if (kirjaimet.length() != 26){
        return false;
    }
    return true;
}

string salaa(string salattava_teksti, string muutos){
    string uusi;
    string vertaus = "abcdefghijklmnopqrstuvwxyz";
    for (unsigned long i = 0;i<salattava_teksti.length();i++){
        uusi += muutos.at(vertaus.find(salattava_teksti.at(i)));
    }
    return uusi;
}

int main()
{
    cout << "Enter the encryption key: ";
    string salattava;
    cin >> salattava;

    if (salattava.length() != 26){
        cout << "Error! The encryption key must contain 26 characters." << endl;
        return 1;
    } else if (not kaikki_pienella(salattava)){
        cout << "Error! The encryption key must contain only lower case characters." << endl;
        return 1;

    } else if (not kaikki_kirjaimet(salattava)){
        cout << "Error! The encryption key must contain all alphabets a-z." << endl;
        return 1;

    } else {
        string muutettava;
        cout << "Enter the text to be encrypted: ";
        cin >> muutettava;

        string uusi = salaa(muutettava, salattava);
        cout << uusi << endl;

    }


    return 0;
}
