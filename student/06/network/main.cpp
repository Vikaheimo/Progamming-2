#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using std::string, std::vector, std::map, std::cout;
const std::string HELP_TEXT = "S = store id1 i2\nP = print id\n"
                              "C = count id\nD = depth id\n";


std::vector<std::string> split(const std::string& s,
                               const char delimiter,
                               bool ignore_empty = false)
{
    std::vector<std::string> result;
    std::string tmp = s;

    while(tmp.find(delimiter) != std::string::npos)
    {
        std::string new_part = tmp.substr(0, tmp.find(delimiter));
        tmp = tmp.substr(tmp.find(delimiter) + 1, tmp.size());
        if(not (ignore_empty and new_part.empty()))
        {
            result.push_back(new_part);
        }
    }
    if(not (ignore_empty and tmp.empty()))
    {
        result.push_back(tmp);
    }
    return result;
}
void print_verkosto (map<string, vector<string>> data, string name, int depth){
    cout << string(depth*2, '.') << name << std::endl;
    map<string, vector<string>>::iterator itt = data.find(name);
    if (itt != data.end()){
        for (string under: itt->second){
            print_verkosto(data, under, depth+1);
        }
    }
}

int laske_verkosto (map<string, vector<string>> data, string name){
    map<string, vector<string>>::iterator itt = data.find(name);
    if (itt != data.end()){
        int summa = 1;
        for (string under: itt->second){
            summa += laske_verkosto(data, under);
        }
        return summa;
    } else {
        return 1;
    }
}
int laske_verkoston_syvyys(map<string, vector<string>> data, string name){
    map<string, vector<string>>::iterator itt = data.find(name);
    int maks_syvyys = 0;
    if (itt != data.end()){
        for (string under: itt->second){
            int s = laske_verkoston_syvyys(data, under);
            if (s > maks_syvyys){
                maks_syvyys = s;
            }
        }
        return maks_syvyys + 1;
    } else {
        return 1;
    }
}
int main()
{
    map<string, vector<string>> data;


    while(true)
    {
        std::string line;
        std::cout << "> ";
        getline(std::cin, line);
        std::vector<std::string> parts = split(line, ' ', true);

        // Allowing empty inputs
        if(parts.size() == 0)
        {
            continue;
        }

        std::string command = parts.at(0);

        if(command == "S" or command == "s")
        {
            if(parts.size() != 3)
            {
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
                continue;
            }
            std::string id1 = parts.at(1);
            std::string id2 = parts.at(2);

            map<string, vector<string>>::iterator it = data.find(id1);
            if (it !=data.end()){
                if (it->second.back() != id2){
                    it -> second.push_back(id2);
                }
            } else{
                data.insert({id1, {id2}});
            }

        }
        else if(command == "P" or command == "p")
        {
            if(parts.size() != 2)
            {
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
                continue;
            }
            std::string id = parts.at(1);

            print_verkosto(data, id, 0);

        }
        else if(command == "C" or command == "c")
        {
            if(parts.size() != 2)
            {
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
                continue;
            }
            std::string id = parts.at(1);

            cout << laske_verkosto(data, id) - 1 << std::endl;

            

        }
        else if(command == "D" or command == "d")
        {
            if(parts.size() != 2)
            {
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
                continue;
            }
            std::string id = parts.at(1);

            cout << laske_verkoston_syvyys(data, id)  << std::endl;

        }
        else if(command == "Q" or command == "q")
        {
           return EXIT_SUCCESS;
        }
        else
        {
            std::cout << "Erroneous command!" << std::endl << HELP_TEXT;
        }
    }
}
