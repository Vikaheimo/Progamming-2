#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    cout << "Input file: ";
    string input_file_name;
    getline(cin, input_file_name);

    cout << "Output file: ";
    string output_file_name;
    getline(cin, output_file_name);

    ifstream input_tiedosto(input_file_name);


    if(not input_tiedosto){
        cout << "Error! The file " << input_file_name << " cannot be opened." << endl;
        return EXIT_FAILURE;
    } else {
        ofstream output_tiedosto(output_file_name);
        int rivinumero = 1;
        string rivi;

        while (getline(input_tiedosto, rivi)) {
            output_tiedosto << rivinumero << " " << rivi << endl;
            rivinumero += 1;
        }
    }
    return EXIT_SUCCESS;
}
