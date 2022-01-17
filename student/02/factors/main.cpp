#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    cout << "Enter a positive number: ";
    int numero = 0;
    cin >> numero;
    if (numero < 1){
        cout << "Only positive numbers accepted" << endl;
    } else {
        int num1 = numero;
        int num2 = 1;
        for (int luku1 = 1; luku1 <= numero; ++luku1){
            for (int luku2 = 1; luku2 <= numero; ++luku2){
                if (luku1 * luku2 == numero){
                    if (abs(num1 - num2) > abs(luku1 - luku2)){
                        if (luku1 > luku2){
                            num1 = luku1;
                            num2 = luku2;
                        } else{
                            num1 = luku2;
                            num2 = luku1;
                        }

                    }

                }
            }
        }
        cout << numero << " = " << num2 << " * " << num1 << endl;
    }
    return 0;
}
