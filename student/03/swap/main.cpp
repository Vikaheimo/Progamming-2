#include <cstdlib>
#include <iostream>

void swap(int & luku1, int & luku2){
    int a = luku1;
    luku1 = luku2;
    luku2 = a;

}


#ifndef UNIT_TESTING
int main()
{
    std::cout << "Enter an integer: ";
    int i = 0;
    std::cin >> i;

    std::cout << "Enter another integer: ";
    int j = 0;
    std::cin >> j;

    swap(i, j);
    std::cout << "The integers are " << i << " and " << j << std::endl;

    return EXIT_SUCCESS;
}
#endif
