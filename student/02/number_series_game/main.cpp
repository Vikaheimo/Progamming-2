#include <iostream>


int main()
{
    std::cout << "How many numbers would you like to have? ";
    int lukumaara = 0;
    std::cin >> lukumaara;
    for (int luku = 1; luku <= lukumaara; ++luku){
        if (luku % 21 == 0) {
            std::cout << "Zip Boing" << std::endl;
        } else if (luku % 3 == 0){
            std::cout << "Zip" << std::endl;
        } else if (luku % 7 == 0){
            std::cout << "Boing" << std::endl;
        } else {
            std::cout << luku << std::endl;
        }
    }
    return 0;
}
