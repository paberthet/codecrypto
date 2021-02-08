#include <stdio.h>
#include <stdlib.h>

#define L 32

/** PROTOTYPES **/

void PrintBinary(long unsigned x);
void PrintPol(long unsigned x);
int Degree(long unsigned a);

/**Feuille II **/

long unsigned PolMul(long unsigned a, long unsigned b);
long unsigned PolSqr(long unsigned a);
long unsigned PolModDiv(long unsigned *r, long unsigned a, long unsigned b);
long unsigned PowerSerial(long unsigned a, long unsigned b);
long unsigned PolPowerMod(long unsigned a, long unsigned n, long unsigned p);


/** CODE **//**
int main(void)
{
    /* Exo 1*//*
    int test = 121;
    printf("binary print of %d :\n",test);
    PrintBinary(test);

    printf("\n");

    /*Exo2*//*
    test = 0x123;
    printf("polynomial print of %d : \n",test);
    PrintPol(test);

    printf("\n");

    /*Exo3*//*
    test = 0x203;
    printf("polynomial degree of %d : \n",test);
    printf("%d\n",Degree(test));

    /**Feuille II**//*
    printf("\n\n Feuille II \n \n");
    
    /*Exo1*//*
    test=0xa2;
    unsigned long test2=0x225;
    PrintPol(test);
    PrintPol(test2);
    printf("et leur produit : ");
    PrintPol(PolMul(test2,test));
    printf("inversion des termes :");
    PrintPol(PolMul(test,test2));
    printf("\n");

    /*Exo2*//*
    test = 0x1a;
    PrintPol(test);
    printf(" et son carré :");
    PrintPol(PolSqr(test));
    printf("\n");

    /*Ex03*//*
    long unsigned reste = 0;
    long unsigned quotient = 0;
    quotient = PolModDiv(&reste,0b1100111010,0b1011);
    printf("quotient : \n");
    PrintPol(quotient);
    printf("reste : \n");
    PrintPol(reste);

    /*Exo4*//*
    printf("quotient serial:\n");
    PrintPol(PowerSerial(0b1001001010010,0b11001));
    printf("\n");

    /*Exo5*//*
    printf("valeur pow 255 :\n");
    PrintPol(PolPowerMod(0x2,4,0x11b));

}**/

void PrintBinary(long unsigned x)
{
    int i;
    printf("0b");
    for( i = L-1; i >= 0 ; i--)
    {
        printf("%d",(x >> i) & 1);
    }
    printf("\n");
}

void PrintPol(long unsigned x)
{
    int i = 0;
    while(((x>>i) & 1)==0 && x!=0)
        i++;
    if( i == 0)
        printf("%d" , (x) & 1);
    else
        printf("X^%d",i);
    int j;
    for( j = i+1; j < L ; j++)
    {
        if(((x >> j)&1) == 1)
            printf("+X^%d", j);
    }
    printf("\n");
}

int Degree(long unsigned a)
{
    for(int i = L-1; i >=0; i--)
    {
        if(((a >> i) & 1) == 1)
            return i;
    }
    return 0;
}

/** Feuille II **/
long unsigned PolMul(long unsigned a, long unsigned b)
{
    long unsigned c = 0;
    int i;
    for(i = 0; i < L; i++)
    {
        if((b>>i) & 1)
        {
            c^=(a<<i);
        }
    }  
    return c;
}

long unsigned PolSqr(long unsigned a)
{
    long unsigned c = 0;
    int i;
    for(i = 0; 2*i +1 < L ; i++)
    {
        if((a>>i) & 1)
        {
            c^= 1 << (2*i);
        }
    }
    return c;
}

long unsigned PolModDiv(long unsigned* r, long unsigned a, long unsigned b)
{
    int degA = Degree(a);
    int degB = Degree(b);

    if(degA < degB)
    {
        *r =a;
        return 0;
    }
    long unsigned q = 0;
    int diff = degA -degB;
    b = (b << diff);
    int i = diff;
    int j = 0;
    while(i >=0)
    {
        if((a >> (degA - j)) == 1)
        {
            a^=b;
            q^=(1<<i);
        }
        b = (b >> 1);
        i --;
        j++;
    }
    *r = a;
    return q;
}

long unsigned PowerSerial(long unsigned a, long unsigned b)
{
    if(((b) & 1) == 0)
    {
        printf("%d is even", b);
        return 0;
    }

    long unsigned q = 0;
    int i = 0;
    int degB = Degree(b);
    while(degB<L-1)
    {
        if(((a>>i)&1) == 1)
        {
            a^=b;
            q^=(1<<i);
        }
        b = (b << 1);
        degB++;
        i++;
    }
    return q;
}

long unsigned PolPowerMod(long unsigned a, long unsigned n,long unsigned p)
/*this algorithm is a modified Sqr&Mul which is more resistant to single power analisys attacks. It remains weak against differential power analysis attacks */
{
     unsigned long r = 1;
    int degN = Degree(n);
    unsigned long temp;
    int i;
    for(i = degN; i >=0; i--)
    {
        r = PolModDiv(&temp,PolSqr(r),p);
        temp = PolModDiv(&r,(PolMul(((n>>i)&1),PolMul(temp,a))^PolMul((1^((n>>i)&1)),temp)),p);
    }
    return r;
}