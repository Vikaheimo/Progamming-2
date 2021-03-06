#include <iostream>
#include <random>
#include <string>

using namespace std;

void produce_random_numbers(unsigned int lower, unsigned int upper, unsigned int seed){
    default_random_engine gen(seed);
    uniform_int_distribution<int> distr(lower, upper);
    string valinta;
    while (valinta !="q"){
        cout << endl << "Your drawn random number is " << distr(gen) << endl << "Press q to quit or any other key to continue: ";
        cin >> valinta;

    }
}

int main()
{
    unsigned int lower_bound, upper_bound, seed;
    cout << "Enter a lower bound: ";
    cin >> lower_bound;
    cout << "Enter an upper bound: ";
    cin >> upper_bound;

    if(lower_bound >= upper_bound)
    {
        cout << "The upper bound must be strictly greater than the lower bound"
             << endl;
        return EXIT_FAILURE;
    }
    cout << "Enter a seed value: ";
    cin >> seed;
    produce_random_numbers(lower_bound, upper_bound, seed);


    return EXIT_SUCCESS;
}
