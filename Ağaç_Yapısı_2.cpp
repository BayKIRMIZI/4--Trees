
/*
 Agac yapisinda siralama ve sayiyi bulma
*/


#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
typedef struct agac
{
        int d;
        agac *n,*p;
}AGAC;

void sirala1 (AGAC *a)
{
     if(a->p != NULL)
     { sirala1(a->p); }
     printf("\n\t->%d ",a->d);
     if(a->n != NULL)
     { sirala1(a->n); }
} 
    
void sirala2 (AGAC *a)
{
     printf("\n\t->%d ",a->d);
     if(a->p != NULL)
     { sirala2(a->p); }    
     if(a->n != NULL)
     { sirala2(a->n); }    
} 

void sirala3 (AGAC *a)
{   
     if(a->p != NULL)
     { sirala3(a->p); }
     if(a->n != NULL)
     { sirala3(a->n); }
     printf("\n\t->%d ",a->d);
} 
void ara(AGAC *a,int b)
{
     if(a==NULL)
     { printf("Bulunamadi...\n"); }
     else if(a->d==b)
     { printf("BULUNDU...\n"); }
     else if(b>(a->d))
     { ara(a->n,b); }
     else
     { ara(a->p,b); }
}

main()
{
      int i,n,x;
      AGAC *k=NULL,*s;
      printf("Kac Sayi Gireceksiniz? = ");
      scanf("%d",&n);
      for(i=0;i<n;i++)
      {
           printf("%d. sayiyi giriniz = ",i+1);
           scanf("%d",&x);
           if(k==NULL)
           {
                 k=new AGAC;
                 k->d=x;
                 k->n=NULL;
                 k->p=NULL;
           }
           else
           {
                 s=k;
                 while(1)
                 {
                       if(x>(s->d))
                       {
                            if(s->n==NULL)
                            {
                                 s->n=new AGAC;
                                 s=s->n;
                                 s->d=x;
                                 s->n=NULL;
                                 s->p=NULL;
                                 break;
                            } 
                            else
                            {  s=s->n;  }
                       }
                       else
                       {
                            if(s->p==NULL)
                            {
                                  s->p=new agac;
                                  s=s->p;
                                  s->d=x;
                                  s->n=NULL;
                                  s->p=NULL;
                                  break;
                            }
                            else
                            {  s=s->p;  }
                       }
                 }
           }
      }
      printf("\n SOL , KOK , SAG :");
      sirala1(k);
      printf("\n KOK , SOL , SAG :");
      sirala2(k);
      printf("\n SOL , SAG , KOK :");
      sirala3(k);
      printf("\n");
      printf("Aramak isteginiz sayiyi giriniz = ");
      scanf("%d",&i);
      ara(k,i);
      system("pause");
}





