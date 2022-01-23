#include <iostream>


using namespace std;

int main()
{
    cout << "Enter a number: ";
    int luku;
    cin >> luku;
    int kuutio = luku * luku * luku;
    if (kuutio/(luku * luku)!=luku){
        cout << "Error! The cube of " << luku <<" is not " << kuutio << "." << endl;
    } else {
        cout << "The cube of " << luku << " is " << kuutio << "." << endl;
    }
}
