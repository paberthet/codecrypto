#include <stdio.h>
#include <stdlib.h>

#define L 9

unsigned int Etat;
unsigned int Polynome= 0b100100110;
unsigned int EtatInitial= 0b100000000;

void Initialise(unsigned int e);
void AfficheEtat();
void Avance();
unsigned int Rebouclage();
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


void Initialise(unsigned int e)
{
	Etat = e;
}

void AfficheEtat()
{
	int i;
    for(i = L-1; i >= 0; i--)
    {
        printf("%2d",(Etat >> i) & 1);
    }
    printf("\n");
}

unsigned int Rebouclage()
{
    unsigned int x;
    x = Etat & Polynome;// Etat  * Polynome
    x^=(x >> 8); //en notant les 9 bits par leur index
    x^=( x >> 4); //on a progressivement la somme de tous les bits
    x^=(x >> 2); //ou plutot le XOR qui apparait
    return (x^(x>>1))&1; //dans le dernier bit que l on renvoie ici
}

void Avance()
{
    unsigned int tampon = Rebouclage();
    Etat = (Etat << 1);
    Etat ^= tampon;
	Etat &= 0b0111111111; //permet de ne garder que les 9 bits qui nous interessent
}

int Periode()
{
	Initialise(EtatInitial);
	int i;
	for(i =0; i < 512; i++)
	{
		Avance();
		if(i == 154)
			AfficheEtat();
		if(Etat == EtatInitial)
			return i+1;
	}
}