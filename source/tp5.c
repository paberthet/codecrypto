#include <stdlib.h>
#include <stdio.h>
#include "tp1.c"


int* Fourier(int* f, int n);
int* Walsh(int* f, int n);
void PrintTab(int* tab, int size);
int poids(unsigned x);
int degbool(unsigned x);


int main(void)
{
    printf("Poids de 0 : %d \n",poids(0));
    printf("Poids de 15 : %d \n",poids(15));
    printf("Poids de 16 : %d \n",poids(16));
    int x[8] = {1,1,0,1,0,1,1,0};
    int y[8] = {1,1,0,1,0,1,1,0};
    printf("Value : ");
    PrintTab(x,8);
    printf("Fourier : ");
    PrintTab(Fourier(x,8),8);
    printf("Walsh : ");
    PrintTab(Walsh(y,8),8);
}

void PrintTab(int* tab, int size)
{
    printf("[");
    printf("%d", tab[0]);
    for(int i = 1; i < size; i++)
    {
        printf(",%d", tab[i]);
    }
    printf("]\n");
}

int* Fourier(int* f, int n)
{
    if(n == 1)
    {
        return f;
    }
    int mid = (n>>1);
    int up[mid];
    int down[mid];
    for(int i = 0; i <mid; i++)
    {
        up[i] = f[i] + f[mid + i];
        down[i] = f[i] - f[mid+i];
    }
    int *a =Fourier(up,mid);
    int *b =Fourier(down,mid);
    for(int i = 0; i < mid; i++)
    {
        f[i] = a[i];
        f[mid+i] = b[i];
    }
    return f;
}

int* Walsh(int* f, int n)
{
    for(int i = 0; i < n ; i++)
    {
        if(f[i] == 1)
            f[i] = -1;
        else
            f[i] = 1;
    }
    return Fourier(f,n);
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
    int i = 0;
    int max = 0;
    while(x>0)
    {
        i++;
        x = (x >> 1);
        if((x & 1) ==1)
        {
            if(max < poids(i))
                max = poids(i);
        }
    }
    return max;
}

int ProdScal1(long unsigned x, long unsigned y)
{
    return poids((x&y))%2;
}

int Parite(unsigned x)
{
    return poids(x)%2;
}

 

