#include <stdlib.h>
#include <stdio.h>


unsigned ANF(unsigned x);
int poids(unsigned x);
int degbool(unsigned x);


int main(void)
{
    printf("Poids de 0 : %d \n",poids(0));
    printf("Poids de 15 : %d \n",poids(15));
    printf("Poids de 16 : %d \n",poids(16));
}

unsigned ANF(unsigned x, int len)
{
    if(len ==1)
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

int degbool(unsigned x)
{
    
}