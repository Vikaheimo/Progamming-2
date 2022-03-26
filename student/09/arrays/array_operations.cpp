#include "array_operations.hh"

int greatest_v1(int *itemptr, int size)
{
    int isoin_luku = 0;
    int* taulukko_osoitin = itemptr;
    int kierrokset = 0;
    while(kierrokset != size){
        if (*taulukko_osoitin > isoin_luku){

            isoin_luku = *taulukko_osoitin;
        }
        taulukko_osoitin++;
        kierrokset++;
    }
    return isoin_luku;
}

int greatest_v2(int *itemptr, int *endptr)
{
    int isoin_luku = 0;
    int* taulukko_osoitin = itemptr;

    while(taulukko_osoitin != endptr){
        if (*taulukko_osoitin > isoin_luku){

            isoin_luku = *taulukko_osoitin;
        }
        taulukko_osoitin++;
    }
    return isoin_luku;
}

void copy(int *itemptr, int *endptr, int *targetptr)
{

}

void reverse(int *leftptr, int *rightptr)
{

}
