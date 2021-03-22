#include "tp8-1.c"
#include "tp8-2.c"
#define SWAP(a,b) (((a) ^= (b)), ((b) ^= (a)), ((a) ^= (b)))

int last_one(long unsigned a);
int jacobi(unsigned long  p, unsigned long q);
/*
int main(){
	printf("(14|51)=%d\n",jacobi(14,51));
	printf("(35|101)=%d\n",jacobi(35,101));
	return 0;
}
*/
int last_one(long unsigned a)
{
	int res = 0;
	while((a&1)==0)
	{
		res++;
		a >>=1;
	}
	return res;
}

int jacobi(unsigned long a, unsigned long n)
{
	if(a==1 || n ==1) return 1;
	if(a==0 || n ==0) return 0;
	if(EuclideBinaire1(a,n)!=1) return 0;
	if(a >=n ) a%=n;
	int result = 1;
	while(a)
	{
		while((a&1)==0)
		{
			a >>=1;
			if((n&7)==3 || (n&7)==5) result = -result;
		}
		SWAP(a,n);
		if((a&3)==3 && (n&3)==3) result = -result;
		a%=n;
	}
	if(n==1) return result;
	return 0;
}
