#include <stdlib.h>
#include <stdio.h>
#include "tp6.c"
#include "tp1.c"

unsigned long int Fibonacci1(unsigned int n);
int Fibonacci2(int n);

int main()
{
    printf("Exercice Theorique:\n");
    GaussType phi={1,1,-2};
    GaussType sqr;
    GaussType tmp;
    GaussType un= {-1,0,1};
    GaussMul(&sqr, phi,phi);
    GaussAdd(&tmp, sqr, phi);
    GaussAdd(&sqr, tmp, un);
    printf("Phi^2 - Phi -1 : \n");
    GaussAffiche(sqr, 1);
    printf("\nExo 1 \n");
    for(int i = 0; i <21; i++)
    {
        int v = Fibonacci1(i);
        printf("%d  : %d \n",i,v);
    }
    printf("\nExo 2 \n");
    for(int i = 0; i <21; i++)
    {
        int v = Fibonacci2(i);
        printf("%d  : %d \n",i,v);
    }

}

unsigned long int Fibonacci1(unsigned int n)
{
    GaussType nbor ={1,1,2};
    GaussType y;
    GaussPuiss(&y,nbor,n);
    int b = y.b;
    int d = y.d;
    int v = 2*b/d;
    return v;

}

int Fibonacci2(int n) /*courtoisie Marc RENARD*/
{
    int deg=Degree(n);
    float v[2]={0.0,1.0/2};
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    float tmp;
    for(int i=deg;i>=0;i--){
        if((n>>i)&1){
            tmp=2*(v[0]*v[0]+v[1]*v[1]);
            v[1]=2*v[1]*v[1]+4*v[0]*v[1];
            v[0]=tmp;
        }else{
            tmp=4*v[0]*v[1]-2*v[0]*v[0];
            v[1]=2*(v[0]*v[0]+v[1]*v[1]);
            v[0]=tmp;
        }
    }
    return 2*v[0];
}