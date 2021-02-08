#include <stdio.h>
#include <stdlib.h>

#define L 9

int Etat[L];
int Polynome[L]= {1,0,0,1,0,0,1,1,0};
int EtatInitial[L] = {1,0,0,0,0,0,0,0,0};

void Initialise(int* e);
void AfficheEtat();
void Avance();
int SontEgaux(int* a, int* b);
int Periode();

int main(void)
{
	Initialise(EtatInitial);
	int i;
	for(i = 0; i <20; i++)
	{
		Avance();
		AfficheEtat();
	}
	printf("Etat apres 20 tours:\n");
	AfficheEtat();
	printf("\n \n Calcul de la periode : \n %d\n", Periode());
}


void Initialise(int* e)
{
	int i;
	for(i =0; i <L; i++)
		Etat[i] = e[i];
}

void AfficheEtat()
{
	int i;
	for(i = 0 ; i < L ; i++)
		printf("%2d",Etat[i]);
	printf("\n");
}

void Avance()
{
	int tamp = Etat[L-1];
	Etat[L-1] = Etat[L-1]*Polynome[L-1];
	int i;
	for(i = L-2; i>=0; i--)
	{
		Etat[L-1] ^= Etat[i]*Polynome[i];
	}
	for(i = 0; i < L - 2; i++)
	{
		Etat[i] = Etat[i+1];
	}
	Etat[L-2] = tamp;
}

int SontEgaux(int* a, int* b)
{
	int i;
	for(i = L-1; i>=0; i--)
	{
		if(a[i] != b[i])
			return 0;
	}
	return 1;
}

int Periode()
{
	Initialise(EtatInitial);
	int i;
	for(i =0; i < 512; i++)
	{
		Avance();
		if(SontEgaux(Etat,EtatInitial))
			return i+1;
	}
}