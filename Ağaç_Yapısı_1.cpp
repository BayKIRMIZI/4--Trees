#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct lst {
    int d;
    struct lst *sol;
    struct lst *sag;
}agac;

void Preorder(agac *h)
{
     if(h!=NULL)
     {
           printf("%d ",h->d);
           Preorder(h->sol);
           Preorder(h->sag);
     }
}

void Inorder(agac *h)
{
    if(h!=NULL)
    {
        Inorder(h->sol);
        printf("%d ",h->d);           
        Inorder(h->sag);
    }
}

void Postorder(agac *h)
{
	if(h!=NULL)
    {
    	Postorder(h->sol);                     
        Postorder(h->sag);
        printf("%d ",h->d); 
    }
}
void bul(agac *h, int s)
{
    if(h == NULL)
        printf("\nBulunmadi!");
    else
    if(h->d == s)
        printf("\nBulundu!");
    else
    if(s > h->d)
        bul(h->sag,s);
    else
        bul(h->sol,s);
}

int main()
{
    agac *kok ,*c1,*c2,*c11,*c12;
    kok=new agac; kok->d = 200;
    c1=new agac; c1->d=100; kok->sol=c1; c1->sag=NULL; c1->sol=NULL; 
    c2=new agac; c2->d=300; kok->sag=c2; c2->sag=NULL; c2->sol=NULL; 
    c11=new agac; c11->d=50; c1->sol=c11; c11->sag=NULL; c11->sol=NULL; 
    c12=new agac; c12->d=150; c1->sag=c12; c12->sag=NULL; c12->sol=NULL; 
    Preorder(kok); printf("  Pre-order\n");
    Inorder(kok); printf("  In-order\n");
    Postorder(kok); printf("  Post-order\n");
    bul(kok,300); 
    getch();
}
