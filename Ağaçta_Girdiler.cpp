#include<stdio.h>

#include<string.h>

#include<stdlib.h>

#include<conio.h>

typedef struct agac
{
    int bilgi;
    char mesaj[100];
    struct agac *sag,*sol;
}AGAC;

AGAC *kok=NULL;

AGAC *ara(AGAC *,int),*sil(AGAC *,int),*oku();

void yaz(AGAC *),ekle(AGAC *,AGAC *),listele(AGAC *);

int sayDugum(AGAC *,int);

main()
{
      
      AGAC *yeni,*adres;
      int bilgi,miktar;
      char sec;
      while(1)
      {
            system("cls");
            secim:
            printf("\t\t\t(E)kleme\n\t\t\t(L)istele\n\t\t\t(A)rama\n\t\t\t(S)ilme\n\t\t\t(M)iktar\n\t\t\t(C)çkçs\n\t\t\tSeciminiz?\n");
            sec=getch();
            switch(sec)
            {
                case 'E': case 'e': 
				 			yeni=oku(); 
							ekle(kok,yeni);
							getch();
							break;
                case 'L': case 'l':
                 		if(kok!=NULL)
                      		listele(kok);
                 		else
                      		printf("liste bos\n");
						getch();
						break;
                case 'A': case 'a':
                 		printf("aranan bilgi:=>");
                 		scanf("%d",&bilgi);
                 		adres=ara(kok,bilgi);
                 		if(adres==NULL)
                      		printf("aranan bilgi bulunamadi");
                 		else
                     		yaz(adres);
						getch();
						break;
                case 'M': case 'm':
                 		miktar=sayDugum(kok,0);
                 		printf("agactaki toplam kayçt sayçsç:%d\n",miktar); 
						getch();
						break;
                case 'S': case 's':
                 		printf("silinecek bilgi:=>");
                 		scanf("%d",&bilgi);
                 		adres=sil(kok,bilgi);
                 		if(adres!=NULL)
                      		puts("\nyukarçdaki kayçt silindi");
                 		else
                      		puts("silmek istediginiz kayçt bulunamadç"); 
						getch();
						break;
                case 'C': case 'c':
						puts("programdan cçkçsç sectiniz."); 
						exit(0);
                default :
						puts("yanlçs secim.seciminizi kontrol edin.");
                goto secim;

            }//switch
      }//while
      getch();

}//main

/********dugum ekleme******/

void ekle(AGAC *agacKok,AGAC *yeni)
//AGAC *agacKok,*yeni;
{
       if(agacKok==NULL)
            kok=yeni;
       else
       {
           if(yeni->bilgi <=agacKok->bilgi)
           {
                if(agacKok->sol==NULL)
                     agacKok->sol=yeni;
                else
                     ekle(agacKok->sol,yeni);
           }
           else
           {
                if(agacKok->sag==NULL)
                     agacKok->sag=yeni;
                else
                     ekle(agacKok->sag,yeni);
           }
       }
}

/*******listeleme********/

void listele(AGAC *agacKok)
{
     if(agacKok!=NULL)
     {
          listele(agacKok->sol);
          yaz(agacKok);
          listele(agacKok->sag);
     }
}

/******bilgi arama********/

AGAC *ara(AGAC *agacKok,int aranan)
//AGAC *agacKok;
//int aranan;
{
      while(agacKok!=NULL &&agacKok->bilgi!=aranan)
      {
           if(aranan<agacKok->bilgi)
                agacKok=agacKok->sol;
           else
                agacKok=agacKok->sag;
      }
      return agacKok ;
}

/*******dugum silme*******/

AGAC *sil(AGAC *agacKok, int silinecek)
{
     AGAC *qa,*q,*qc,*sa,*s;
     if(agacKok==NULL)
         return NULL;
     else
     {
         q=agacKok;
         qa=NULL;
     }
/*silinenin adresi ve ailesi bulunuyor*/
     while(q!=NULL && q->bilgi!=silinecek)
     {
         qa=q ;
         if(silinecek<q->bilgi)
             q=q->sol;
         else
             q=q->sag;
     }
/* aranan kayçt bulundu mu*/
     if(q==NULL)
         return NULL; /*aranan yok*/
/* 2 alt cocugu varsa */
     if(q->sol!=NULL && q->sag!=NULL)
     {
         s=q->sol;
         sa=q;
/*sol alt agacçn en buyuk dugumu bulunuyor*/
         while(s->sag!=NULL)
         {
             sa=s;
             s=s->sag;
         }
/*silinenin Åzerine bulunan dugum yazçlçr*/
         q->bilgi=s->bilgi;
         strcpy(q->mesaj,s->mesaj);
         q=s;
         qa=sa;
      }
/* bu asamada yeni q nun tek cocugu olabilir*/
      if(q->sol!=NULL)
          qc=q->sol;
      else
          qc=q->sag;
/* dÅgÅm silme*/
      if(q==agacKok) /*silinecek kok mu*/
          kok=qc;
      else
      {
          if(q==qa->sol)
              qa->sol=qc;
          else
              qa->sag=qc;
      }
      yaz(q);
      free(q);
      return q;
}

/* dugum sayçsçnç sayma */

int sayDugum(AGAC *agacKok,int miktar)
{
/*agac bossa miktarç degistirmeden geri don*/
       if(agacKok==NULL)
       return miktar ;
       miktar++;
       miktar=sayDugum(agacKok->sol,miktar);
       miktar=sayDugum(agacKok->sag,miktar);
       return miktar;
}

/*dugum bilgisini ekrana yaz*/
void yaz(AGAC *veri)
{
     printf("bilgi:%d, mesaj:%s\n",veri->bilgi,veri->mesaj);
}

/*yeni kayçt ekleme*/

AGAC *oku()
{
     AGAC *yeni;
     yeni=(AGAC *)malloc(sizeof(AGAC)) ;
     if(yeni==NULL)
     {
           puts("bellek dolu");
           return NULL;
     }     
     printf("bilgi girin=>");
     scanf("%d",&yeni->bilgi);
     printf("mesaj girin=>");
     scanf("%s",yeni->mesaj);
     yeni->sag=NULL;
     yeni->sol=NULL;
/* bilginin yerleütigi adres gînderiliyor*/
     return yeni;

}
