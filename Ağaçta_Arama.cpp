#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct Agaclar{
	struct Agaclar *sol;
	struct Agaclar *sag;
	int sayi;
}Ag;
Ag *kok=NULL;

void Ekle(Ag *agackok, Ag *yeni)
{
	if(agackok==NULL)
	{
		kok=yeni;
	}
	else
	{
		if(yeni->sayi < agackok->sayi)
		{
			if(agackok->sol == NULL)
			{
				agackok->sol=yeni;
			}
			else
			{
				Ekle(agackok->sol,yeni);
			}
		}
		else
		{
			if(agackok->sag == NULL)
			{
				agackok->sag=yeni;
			}
			else
			{
				Ekle(agackok->sag,yeni);
			}
		}
	}
}

int Agac_Arama(Ag *agackok,int aranan)
{
	if(agackok==NULL)
	{
		return 0;
	}
	else if(aranan == agackok->sayi)
	{
		return agackok->sayi;
	}
	else if(aranan < agackok->sayi)
	{
		Agac_Arama(agackok->sol,aranan);
	}
	else if(aranan > agackok->sayi)
	{
		Agac_Arama(agackok->sag,aranan);
	}
	
}

int enkucuk(Ag *agackok)
{
	if(agackok->sol == NULL)
	{
		return agackok->sayi;
	}
	else
	{
		enkucuk(agackok->sol);
	}
}

int enbuyuk(Ag *agackok)
{
	if(agackok->sag == NULL)
	{
		return agackok->sayi;
	}
	else
	{
		enbuyuk(agackok->sag);
	}
}
int main ()
{	
	Ag *yeni;
	yeni = new Ag;
	printf("Sayiyi giriniz :");
	scanf("%d",&(yeni->sayi));
	yeni->sol=NULL;
	yeni->sag=NULL;
	Ekle(kok,yeni);
	
	yeni=new Ag;
	printf("Sayiyi giriniz :");
	scanf("%d",&(yeni->sayi));
	yeni->sol=NULL;
	yeni->sag=NULL;
	Ekle(kok,yeni);
	
	yeni=new Ag;
	printf("Sayiyi giriniz :");
	scanf("%d",&(yeni->sayi));
	yeni->sol=NULL;
	yeni->sag=NULL;
	Ekle(kok,yeni);
	
	yeni=new Ag;
	printf("Sayiyi giriniz :");
	scanf("%d",&(yeni->sayi));
	yeni->sol=NULL;
	yeni->sag=NULL;
	Ekle(kok,yeni);
	
	
	printf("\nEn buyuk %d \n",enbuyuk(kok));
	printf("En kucuk %d \n",enkucuk(kok));
	
	int aranansayi;
	printf("\nAranan sayiyi giriniz: ");
	scanf("%d",&aranansayi);
	if(Agac_Arama(kok,aranansayi)==0)
	{
		printf("Aradiginiz eleman agac yapisinda yok \n");
	}
	else
	{
		printf("Aradiginiz sayi %d bulundu ",aranansayi);
	}
	
	getch();
	return 0;
}
