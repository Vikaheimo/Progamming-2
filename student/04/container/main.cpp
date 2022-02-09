#include <cstdlib>
#include <iostream>
#include <vector>


void read_integers(std::vector< int >& ints, int count)
{
    int new_integer = 0;
    for(int i = 0; i < count; ++i)
    {
        std::cin >> new_integer;
        ints.push_back(new_integer);
    }
}

bool same_values(std::vector< int > integers){
    int luku = integers.front();
    for (int alkio: integers){
        if (alkio != luku)
            return false;
    }
    return true;

}
bool is_ordered_non_strict_ascending(std::vector< int > integers){
    int edellinen = integers.front();
    for (int alkio: integers){
        if (edellinen > alkio)
            return false;
    }
    return true;
}

bool is_geometric_series(std::vector< int > integers){
    if (integers.size() > 1 and integers.front() != 0){
        int kerroin = integers.at(1) / integers.at(0);
        for (unsigned long i = 1; i < integers.size(); i++){
            if (integers.at(i) / integers.at(i-1) != kerroin){
                return false;
            }
        }
        return true;
    } else if (integers.front() == 0){
        return false;
    } else{
        return true;
    }


}
bool is_arithmetic_series(std::vector< int > integers){
    if (integers.size() > 1){
        int erotus = integers.at(1)-integers.at(0);
        for (unsigned long i = 1;i < integers.size(); i++){
            if (integers.at(i)-integers.at(i-1) != erotus){
                return false;
            }
        }
        return true;
    } else {
        return true;
    }


}
int main()
{
    std::cout << "How many integers are there? ";
    int how_many = 0;
    std::cin >> how_many;

    std::cout << "Enter the integers: ";
    std::vector<int> integers;
    read_integers(integers, how_many);

    if(same_values(integers))
        std::cout << "All the integers are the same" << std::endl;
    else
        std::cout << "All the integers are not the same" << std::endl;

    if(is_ordered_non_strict_ascending(integers))
        std::cout << "The integers are in a non-strict ascending order" << std::endl;
    else
        std::cout << "The integers are not in a non-strict ascending order" << std::endl;

    if(is_arithmetic_series(integers))
        std::cout << "The integers form an arithmetic series" << std::endl;
    else
        std::cout << "The integers do not form an arithmetic series" << std::endl;

    if(is_geometric_series(integers))
        std::cout << "The integers form a geometric series" << std::endl;
    else
        std::cout << "The integers do not form a geometric series" << std::endl;

    return EXIT_SUCCESS;
}
