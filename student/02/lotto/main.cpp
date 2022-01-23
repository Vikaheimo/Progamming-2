#include <iostream>

using namespace std;

unsigned long int kertoma(int luku)
{
    unsigned long int tulo = 1;
    for (int i = 1; i<=luku; i++){
        tulo = tulo*i;
    }
    return tulo;
}

int main()
{
    cout << "Enter the total number of lottery balls: ";
    int pallojen_maara;
    cin >> pallojen_maara;

    cout << "Enter the number of drawn balls: ";
    int nostettavat;
    cin >> nostettavat;

    if (nostettavat <= 0 or pallojen_maara <= 0){
        cout << "The number of balls must be a positive number." << endl;
    } else if (nostettavat > pallojen_maara){
        cout << "The maximum number of drawn balls is the total amount of balls." << endl;
    } else{
        unsigned long int todennakoisyys;
        todennakoisyys = kertoma(pallojen_maara)/(kertoma(pallojen_maara - nostettavat)*kertoma(nostettavat));
        cout << "The probability of guessing all " << nostettavat << " balls correctly is 1/" << todennakoisyys << endl;
    }
    return 0;
}

