#include "tp9-1.c"

void TestSV(int rep, unsigned long n);
/*
int main(){
	TestSV(11,121);
	TestSV(12,137);
	TestSV(45,456);
	TestSV((1<<4),(1<<5)-1);
	TestSV(13,169);
	TestSV(15,225);
	return 0;
}
*/
void TestSV(int rep, unsigned long n)
{
	printf("\n------------------------Number : %d-----------------------\n",n);
	if((n&1)==0)
	{
		perror("Parity error");
		return;
	}
	srand(0);
	for(int k =0; k < rep; k++)
	{
		int m = rand()%(n-3) + 2;
		int jac = jacobi((unsigned)m,n);
		if(jac ==0)
		{
			perror("Jacobi == 0");
			printf("\nTemoin : %d\n",m);
			return;
		}
		unsigned long pow = expmod3((unsigned)m,((n^1)>>1),n);
		if(jac<0)
			pow = pow-n;
		if((unsigned)jac != pow)
		{
			perror("Test failure");
			printf("\nTemoin : %d\n",m);
			return;
		}
	}
	printf("\n\n--------------Test successful----------------\n\n");
}
