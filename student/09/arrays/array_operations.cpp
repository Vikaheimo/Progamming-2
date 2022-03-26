#include "array_operations.hh"

int greatest_v1(int *itemptr, int size)
{
    int isoin_luku = *itemptr;
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
    int isoin_luku = *itemptr;
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
    int* taulukko_osoitin = itemptr;

    while(taulukko_osoitin != endptr){
        *targetptr = *taulukko_osoitin;
        targetptr++;
        taulukko_osoitin++;

    }
}

void reverse(int *leftptr, int *rightptr)
{
    rightptr --;
    int temp;
    while (leftptr < rightptr){
        temp = *leftptr;
        *leftptr = *rightptr;
        *rightptr = temp;

        leftptr++;
        rightptr--;
    }
}
