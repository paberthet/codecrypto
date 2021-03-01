#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    long int a,b,d;
}GaussType;

void GaussAffiche( GaussType x, int cr);
long int pgcd(long int a, long int b);
void Reduire(GaussType *x);
void GaussAdd(GaussType *s, GaussType x, GaussType y);
void GaussMul(GaussType *p, GaussType x, GaussType y);
void GaussOpp(GaussType*o, GaussType x);
void GaussInv(GaussType *i, GaussType x);
void GaussSoustrait(GaussType *d, GaussType x, GaussType y);
void GaussDivise(GaussType *d, GaussType x, GaussType y);
void GaussPuiss(GaussType *r, GaussType x, unsigned int n);

int main()
{
    printf("Exo1 \n");
    GaussType x={9, -72,-45};
    GaussAffiche(x,1);
    Reduire(&x);
    GaussAffiche(x,1);

    printf("\nExo2 \n");
    GaussType x1 = {-1,4,45};
    GaussType y = {-6, 7, 100};
    GaussType s,p;
    GaussAdd(&s, x1, y);
    GaussMul(&p, x1, y);
    printf("Somme = ");
    GaussAffiche(s,1);
    printf("Produit = ");
    GaussAffiche(p,1);

    printf("\nExo3 \n");
    GaussType x2 = {-1,4,45};
    GaussType o,i,r;
    GaussOpp(&o,x2);
    printf("Oppose = ");
    GaussAffiche(o,1);
    printf("Verif : ");
    GaussAffiche(x2,0);
    printf(" + ");
    GaussAffiche(o, 0);
    printf(" = ");
    GaussAdd(&r, x2, o);
    GaussAffiche(r,1);
    GaussInv(&i,x2);
    printf("Inverse = ");
    GaussAffiche(i,1);
    printf("Verif : ");
    GaussAffiche(x2,0);
    printf(" * ");
    GaussAffiche(i,0);
    printf(" = ");
    GaussMul(&r,x2,i);
    GaussAffiche(r,1);

    printf("\nExo4 \n");
    GaussSoustrait(&r,x2,x2);
    printf("Verif soustrait : ");
    GaussAffiche(r,1);
    GaussDivise(&r,x2,x2);
    printf("Verif divise : ");
    GaussAffiche(r,1);
    GaussType x3 = {2,0,1};
    int n = 10;
    printf("Verif puiss : ");
    GaussAffiche(x3,0);
    printf(" pow %d = ",n);
    GaussPuiss(&r, x3, n);
    GaussAffiche(r,1);
    return 0;
}

void GaussAffiche(GaussType x, int cr)
{
    printf("(%d %s %d V5 ) / %d%s", x.a, x.b <0?"-":"+",x.b<0?-x.b:x.b,x.d,cr?"\n":" ");
}

long int pgcd(long int a, long int b)
{
    if(a<0) a=-a;
    if(b<0) b=-b;
    if(b==0) return a;
    while(a)
    {
        b%=a;
        if(b==0) return a;
        a%=b;
    }
    return b;
}

void Reduire(GaussType *x)
{
    long int divcom = pgcd(pgcd(x->a,x->b), x->d);
    x->a /= divcom;
    x->b /= divcom;
    x->d /= divcom;
}

void GaussAdd(GaussType* s, GaussType x, GaussType y)
{
    s->a = x.a * y.d + y.a * x.d;
    s->b = x.b * y.d + y.b * x.d;
    s->d = x.d * y.d;
    Reduire(s);
}

void GaussMul(GaussType* p, GaussType x, GaussType y)
{
    p->a = x.a * y.a + 5*(x.b * y.b);
    p->b = x.a * y.b + x.b * y.a;
    p->d = x.d * y.d;
    Reduire(p);
}

void GaussOpp(GaussType *o, GaussType x)
{
    o->a = x.a;
    o->b = x.b;
    o->d = -1*x.d;
}

void GaussInv(GaussType *i, GaussType x)
{
    i->d = x.a * x.a - 5 * x.b * x.b;
    i->a = x.d * x.a;
    i->b = x.d * -1 * x.b;
    Reduire(i);
}

void GaussSoustrait(GaussType *d, GaussType x, GaussType y)
{
    GaussType tmp;
    GaussOpp(&tmp, y);
    GaussAdd(d, x, tmp);
}

void GaussDivise(GaussType *d, GaussType x, GaussType y)
{
    GaussType tmp;
    GaussInv(&tmp, y);
    GaussMul(d, x, tmp);
}

void GaussPuiss(GaussType *r, GaussType x, unsigned int n)
{
    GaussType tmp = x;
    GaussType tmp2 = {1,0,1};
    GaussType tmp3;
    while(n !=0)
    {
        if((n>>0)&1 == 1)
        {
            GaussMul(&tmp3,tmp2,tmp);
            tmp2 = tmp3;
        }
        GaussMul(&tmp3, tmp, tmp);
        tmp = tmp3;
        n>>=1;
    }
    r->a = tmp2.a;
    r->b = tmp2.b;
    r->d = tmp2.d;
}