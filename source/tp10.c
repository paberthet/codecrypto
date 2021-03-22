#include "tp9-2.c"

int TestMillerRabin(unsigned long a, unsigned long n);

int main()
{
	printf("Test : %d",TestMillerRabin(12,53));
	return 0;
}

int TestMillerRabin(unsigned long a,unsigned long n)
{
	printf("\n----------------------Number : %d----------------------\n");
	if((n&1)==0)
	{
		perror("Parity Check");
		return 0;
	}
	unsigned long phi = n^1;
	int cmpt = last_one(phi);
	phi >>=cmpt;
	unsigned long b = expmod3(a,phi,n);
	if(b==1) return 1;
	for(int j = 0; j < cmpt; j++)
	{
		if(b == n-1) return 1;
		if(b == 1) return 0;
		b = sqrmod1(b,n);
	}
	return 0;
}
