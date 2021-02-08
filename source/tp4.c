#include <stdlib.h>
#include <stdio.h>
#include "tp1.c"

unsigned ANF(unsigned x);
int poids(unsigned x);
int degbool(unsigned x);


int main(void)
{
    printf("Poids de 0 : %d \n",poids(0));
    printf("Poids de 15 : %d \n",poids(15));
    printf("Poids de 16 : %d \n",poids(16));
    unsigned x = 0b01100101;
    PrintBinary(ANF(x));
}

unsigned ANF(unsigned x) //ici on pourrait ameliorer en mettant une boucle for prenant la longueur totale et construisant le filtre a chaque etape
{
    x ^=((x>>16)&0x0000ffff);
    x ^=((x>>8)&0x00ff00ff);
    x ^=((x>>4)&0x0f0f0f0f);
    x ^=((x>>2)&0x33333333);
    x ^=((x>>1)&0x55555555);
    return x;
}

int poids(unsigned x)
{
    int poids = 0;
    while(x > 0)
    {
        poids += ((x >>0) & 1);
        x = (x>>1);
    }
    return poids;
}

int degbool(unsigned x,int nbclauses)
{
    
}