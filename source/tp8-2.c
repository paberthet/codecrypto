#include <stdlib.h>
#include <stdio.h>

long unsigned mulmod(long unsigned a, long unsigned m, long unsigned n);
long unsigned sqrmod1(long unsigned a, long unsigned n);
long unsigned sqrmod2(long unsigned a, long unsigned n);

long unsigned expmod1(long unsigned a, long unsigned e, long unsigned n);
long unsigned expmod2(long unsigned a, long unsigned e, long unsigned n);
long unsigned expmod3(long unsigned a, long unsigned e, long unsigned n);


int main(){
	
	return 0;
}

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
	long unsigned res = 0x0;
	for(int i = 0; i <32; i ++)
	{
		if(a&1)
		{
			res ^= (1<<(2*i));
		}
		a>>=1;
	}
	return(res%n);
}

long unsigned expmod1(long unsigned a, long unsigned e, long unsigned n)
{
	if(e==0)
		return 1;
	if((e&1)==0)
		return sqrmod2(expmod1(a,(e>>1),n),n);
	if(e&1)
		return mulmod(a,expmod1(a,e-1,n),n);
}
long unsigned expmod2(long unsigned a, long unsigned e, long unsigned n)
{
	long unsigned res = 1;
	for(int i =0; i <32 ; i++)
	{
		if(e&1)
			res = mulmod(res,a,n);
		e>>=1;
		a = sqrmod2(a,n);
	}
}

long unsigned expmod3(long unsigned a, long unsigned e, long unsigned n)
{
	long unsigned res = 1;
	while(e!=0)
	{
		if(e&1)
			res = mulmod(res,a,n);
		e>>=1;
		a = sqrmod2(a,n);
	}
}

