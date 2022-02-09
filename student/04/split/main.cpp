#include <iostream>
#include <string>
#include <vector>


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
    return arvot;
}


int main()
{
    std::string line = "";
    std::cout << "Enter a string: ";
    getline(std::cin, line);
    std::cout << "Enter the separator character: ";
    char separator = getchar();

    std::vector< std::string > parts  = split(line, separator);
    std::cout << "Splitted string including empty parts: " << std::endl;
    for( auto part : parts ) {
        std::cout << part << std::endl;
    }

    std::vector< std::string > parts_no_empty  = split(line, separator, true);
    std::cout << "Splitted string ignoring empty parts: " << std::endl;
    for( auto part : parts_no_empty ) {
        std::cout << part << std::endl;
    }
}
