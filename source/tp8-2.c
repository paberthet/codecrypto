#include <stdlib.h>
#include <stdio.h>

long unsigned mulmod(long unsigned a, long unsigned m, long unsigned n);
long unsigned sqrmod1(long unsigned a, long unsigned n);
long unsigned sqrmod2(long unsigned a, long unsigned n);

long unsigned expmod1(long unsigned a, long unsigned e, long unsigned n);
long unsigned expmod2(long unsigned a, long unsigned e, long unsigned n);
long unsigned expmod3(long unsigned a, long unsigned e, long unsigned n);
/*
int main(){
	printf("%d",mulmod(2,9,5));
	printf("\n %d",sqrmod1(5,10));
	printf("\n %d", sqrmod2(5,10));
	
	printf("\n%d",expmod1(2,3,10));
	printf("\n%d",expmod2(2,3,10));
	printf("\n%d",expmod3(2,3,10));

	printf("\n\nApplication a la crypto\n");
	printf("exposant public : %d\n",3);
	printf("message : %d\n",0x5555);
	printf("module : %d\n",64507);
	long unsigned c = expmod3(0x5555,3,64507);
	printf("chiffre : %d\n",c);
	printf("dechiffre : %d\n",expmod3(c,42667,64507));
	return 0;
}
*/

long unsigned mulmod(long unsigned a, long unsigned m, long unsigned n)
{
	long unsigned res = 0;
	for(int i = 0; i <32; i++)
	{
		if(m&1)
		{
			res += a%n;
		}
		a<<=1;
		m>>=1;
	}
	return res%n;
}

long unsigned sqrmod1(long unsigned a, long unsigned n)
{
	return(mulmod(a,a,n));
}

long unsigned sqrmod2(long unsigned a, long unsigned n)
{
	return((a*a)%n);
}

long unsigned expmod1(long unsigned a, long unsigned e, long unsigned n)
{
	if(e==1)
		return a%n;
	unsigned long b = sqrmod1(a,n);
	if((e&1)==0)
		return expmod1(b,(e>>1),n);
	if(e&1)
		return mulmod(a,expmod1(b,((e-1)>>1),n),n);
}
long unsigned expmod2(long unsigned a, long unsigned e, long unsigned n)
{
	long unsigned res = 1;
	for(int i =0; i <32 ; i++)
	{
		if(e&1)
		{
			res = mulmod(res,a,n);
			e =((e^1)>>1);
		}
		else
			e>>=1;
		a = sqrmod1(a,n);
	}
	return res;
}

long unsigned expmod3(long unsigned a, long unsigned e, long unsigned n)
{
	long unsigned res = 1;
	while(e!=0)
	{
		if(e&1)
		{
			res = mulmod(res,a,n);
			e = ((e^1)>>1);
		}
		else
			e>>=1;
		a = sqrmod1(a,n);
	}
	return res;
}

