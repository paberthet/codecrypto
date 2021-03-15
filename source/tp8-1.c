#include <stdlib.h>
#include <stdio.h>

unsigned EuclideBinaire1(unsigned a, unsigned b);
unsigned EuclideBinaire2(unsigned a, unsigned b);
int BezoutBinaire(int* pu,int* pv, int a, int b);
int main()
{
    printf("Exo1:\n");
    printf("16100 par 10000 : %d\n",EuclideBinaire1(16100,10000));
    printf("Exo2:\n");
    printf("16100 par 10000 : %d\n", EuclideBinaire2(16100,10000));
    printf("Exo3:\n");
    int u;
    int v;
    int p = BezoutBinaire(&u,&v,16100,10000);
    printf("Bezout de 16100 et 10000 : u = %d, v = %d, p = %d\n",u,v,p);
    return 0;
}

unsigned EuclideBinaire1(unsigned a, unsigned b)
{
    unsigned d = 1;
    while(a != b)
    {
        if((a&1) == 0 && (b&1) == 0)
        {
            d <<=1;
            a >>=1;
            b >>=1;
        }
        else if((a&1) ==0 && b&1)
        {
            a>>=1;
        }
        else if(a&1 && (b&1)==0)
        {
            b>>=1;
        }
        else
        {
            if (a < b)
            {
                unsigned tmp = b-a;
                b=a;
                a = tmp;
            }
            else
            {
                a = a-b;
            }
            
        }
    }
    return d*a;
}

unsigned EuclideBinaire2(unsigned a, unsigned b)
{
    unsigned d = 1;
    unsigned p,q;
    p=a;
    q=b;
    while((p&1)==0 && (q&1)==0)
    {
        d<<=1;
        p>>=1;
        q>>=1;
    }

    if(p == q)
    {
        return d*p;
    }
    else if((p&1)==0 && q&1)
    {
        return d*EuclideBinaire2((p>>1),q);
    }
    else if((q&1)==0 && p&1)
    {
        return d*EuclideBinaire2(p,(q>>1));
    }
    else
    {
        if(p<q)
        {
            return d*EuclideBinaire2(q-p,p);
        }
        else
        {
            return d*EuclideBinaire2(p-q,p);
        }
    }
}

int BezoutBinaire(int* pu, int* pv, int a, int b)
{
    int u =1;
    int v = 0;
    int r = 0;
    int s = 1;

    unsigned d = 1;
    while ((a&1)==0 && (b&1)==0)
    {
        a>>=1;
        b>>=1;
        d<<=1;
    }
    int p = a;
    int q = b;
    while(q!=0)
    {
        while((p&1)==0)
        {
            p>>=1;
            if((u&1)==0 && (v&1)==0)
            {
                u>>=1;
                v>>=1;
            }
            else
            {
                u = (u-b)>>1;
                v = (v+a)>>1;
            }
        }
        while((q&1)==0)
        {
            q>>=1;
            if((r&1)==0 && (s&1)==0)
            {
                r>>=1;
                s>>=1;
            }
            else
            {
                r = (r-b) >>1;
                s = (s+a) >>1;
            }
        }
        if(p>q)
        {
            p -=q;
            v-=s;
            u-=r;
        }
        else
        {
            q-=p;
            s-=v;
            r-=u;
        }
    }
    *pu = u;
    *pv = v;
    return d*p;
}