#include <stdlib.h>
#include <stdio.h>

unsigned EuclideBinaire1(unsigned a, unsigned b);
unsigned EuclideBinaire2(unsigned a, unsigned b);
int main()
{
    printf("Exo1:\n");
    printf("16100 par 10000 : %d\n",EuclideBinaire1(16100,10000));
    printf("Exo2:\n");
    printf("16100 par 10000 : %d\n", EuclideBinaire2(16100,10000));
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