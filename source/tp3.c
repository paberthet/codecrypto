#include <stdlib.h>
#include <stdio.h>
#include "tp1.c"


long unsigned PolGCD(long unsigned a, long unsigned b);
long unsigned PolInverseMod(long unsigned a, long unsigned b);
int PolIsIrreducible(long unsigned a);

int main(void)
{
    /**Exo1**/
    long unsigned a = 0x151;
    long unsigned b = 0x2c1;
    PrintPol(a);
    PrintPol(b);
    printf("et leur gcd : \n");
    PrintPol(PolGCD(a,b));
    printf("\n");

    /**Exo2**/
    long unsigned p = 0x2;
    long unsigned mod = 0x805;
    printf("Mod ");
    PrintPol(mod);
    printf("le polynome ");
    PrintPol(p);
    printf("est d inverse :\n");
    long unsigned inv = PolInverseMod(p,mod);
    PolModDiv(&inv,inv,mod);
    PrintPol(inv);
    printf("controle : \n");
    unsigned long r;
    PolModDiv(&r,PolMul(p,inv),mod);
    PrintPol(r);
    printf("controle Fermat:\n");
    r= PolPowerMod(p,2046,mod);
    PrintPol(r);
    printf("\n");

    /**Exo3**/



}

long unsigned PolGCD(long unsigned a, long unsigned b)
{
    /*Extended Euclidis Algorithm*/
    long unsigned prevA = a;
    long unsigned nextA = b;
    //on n a pas besoin de u et v ici
    long unsigned q;
    long unsigned r;

    while(nextA != 0)
    {
        q = PolModDiv(&r,nextA, prevA);
        nextA = prevA;
        prevA = r;
    }
    return prevA;
}

long unsigned PolInverseMod(long unsigned a, long unsigned b)
{
    /*Extended Euclidis Algorithm*/
    long unsigned prevA = a;
    long unsigned nextA = b;
    //on n a pas besoin de v ici
    long unsigned prevU = 0x1;
    long unsigned nextU = 0x0;
    long unsigned q;
    long unsigned r;

    while(nextA != 0)
    {
        q = PolModDiv(&r,nextA, prevA);
        nextA = prevA;
        prevA = r;
        long unsigned tamp = nextU^(PolMul(q,prevU));
        nextU = prevU;
        prevU = tamp;
    }
    if(prevA == 0x1)
        return prevU;
    else
    {
        printf("\n Non inversible\n");
        return 0x0;
    }
}