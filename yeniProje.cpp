#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct Film
{
	char ad[30];
	char yonetmen[30];
	char senarist[30];
	char basrol[30];
	char yil[30];
};
/*------------------------------------------------ANA MENÜ------------------------------------------------*/	
int main()
{
	int secim;
	printf("\t\t---MENUYE HOSGELDINIZ---\n");
	printf("\n\t*****************************************\n");
	printf("\t***                                   ***\n");
	printf("\t***          ARAMA TURLERI            ***\n");
	printf("\t***         ---------------           ***\n");
	printf("\t***         1-) Film Ekleme           ***\n");
	printf("\t***         2-) Film Listeleme        ***\n");
	printf("\t***         3-) Film Guncelleme       ***\n");
	printf("\t***         4-) Film Silme            ***\n");
	printf("\t***         5-) Film Arama            ***\n");
	printf("\t***         6-) Cikis                 ***\n");
	printf("\t***                                   ***\n");
	printf("\t*****************************************\n");
	printf("\t\t   Menu Secim: "); scanf("%d",&secim);
	printf("\n");
	/*---------------------------------------------FÝLM EKLEME---------------------------------------------*/
	if(secim==1)
	{
		typedef Film flm;
		flm a;
		FILE *fp = fopen("filmliste.txt","a");
	    if(fp==NULL) printf("Dosya Bulunamadi"); //Dosya Kontrol
	  	printf("Film Adini Giriniz: ");
	    scanf("%s",a.ad);
	    printf("Yonetmen Giriniz: ");
	    scanf("%s",a.yonetmen);
	    printf("Senarist Giriniz: ");
	    scanf("%s",a.senarist);
	    printf("Basrol Giriniz: ");
	    scanf("%s",a.basrol);
	    printf("Yil Giriniz: ");
	    scanf("%s",a.yil);
	           
	    fprintf(fp,"%s %s %s %s %s\n",a.ad,a.yonetmen,a.senarist,a.basrol,a.yil);
	    printf("\nFILM BASARIYLA EKLENMISTIR!");
	    fclose(fp);
	    printf("\nDevam Etmek Icin Herhangi Bir Tusa Basiniz..");
	    _getch();
	}
	/*----------------------------------------FÝLM LÝSTELEME(YILA GÖRE)----------------------------------------*/
	else if(secim==2)
	{
		typedef Film flm;
		flm a[100];
		FILE *fp1 = fopen("filmliste.txt","r");
	    if(fp1==NULL) printf("Dosya Bulunamadi"); //Dosya Kontrol
	    int i,j=0,next=0,sayac1=0,sayac2=0,flmsyc=0;;
		while(!feof(fp1)){
		
		   fscanf(fp1,"\n%s %s %s %s %s\n",a[sayac1].ad,a[sayac1].yonetmen,a[sayac1].senarist,a[sayac1].basrol,a[sayac1].yil);
		   sayac1++;
		   flmsyc++;//flmssayac kadar dongunun gonmesi için olusturuldu.
		}
		char temp1[flmsyc],temp2[flmsyc],temp3[50];
		while(sayac1>0)
		{
		   while(sayac2<sayac1+j)
		   {
		      for(i=0;i<flmsyc;i++)
			  {		
		         temp1[i]=a[next].yil[i];
		         temp2[i]=a[sayac2+1].yil[i];
		      }
		      if(strcmp(temp2,temp1)>0)
			  {  
			  
			  	 strcpy(temp3,a[next].yil);
		         strcpy(a[next].yil,a[sayac2+1].yil);
		         strcpy(a[sayac2+1].yil,temp3);
		         
		         strcpy(temp3,a[next].ad);
		         strcpy(a[next].ad,a[sayac2+1].ad);
		         strcpy(a[sayac2+1].ad,temp3);
		
		         strcpy(temp3,a[next].yonetmen);
		         strcpy(a[next].yonetmen,a[sayac2+1].yonetmen);
		         strcpy(a[sayac2+1].yonetmen,temp3);
		
		         strcpy(temp3,a[next].senarist);
		         strcpy(a[next].senarist,a[sayac2+1].senarist);
		         strcpy(a[sayac2+1].senarist,temp3);
		         
		         strcpy(temp3,a[next].basrol);
		         strcpy(a[next].basrol,a[sayac2+1].basrol);
		         strcpy(a[sayac2+1].basrol,temp3);
		      }
		      sayac2++;
		   }
		   sayac2=0;
		   j++;
		   sayac2+=j;
		   sayac1--;
		   next++;
		}
		fclose(fp1);
		printf("\n");
		i=0;
		printf("ADI  \t  YONETMEN  SENARIST  \tBASROL      YIL");
		while(strcmp(a[i].ad,"")!=0)
		{
		   printf("\n%-10s %-10s%-10s %-10s  %-10s\n",a[i].ad,a[i].yonetmen,a[i].senarist,a[i].basrol,a[i].yil);
		   i++;
		}
			printf("\nDevam Etmek Icin Herhangi Bir Tusa Basiniz..");
			_getch();
	}
	/*---------------------------------------------FÝLM GÜNCELLEME---------------------------------------------*/
	else if(secim==3)
	{
		typedef Film flm;
		flm a;		
	    FILE *fp2,*yeni;
	    fp2=fopen("filmliste.txt","r");
		yeni=fopen("filmliste1.txt","w");
		if(fp2==NULL) printf("Dosya Bulunamadi");
		char aranan[15];
		printf("Guncellenecek Filmin Adi? :"); 
		scanf("%s",aranan);
		while(!feof(fp2))
		{
	    	fscanf(fp2,"%s %s %s %s %s\n",a.ad,a.yonetmen,a.senarist,a.basrol,a.yil);
		if(strstr(a.ad,aranan))
		{											
	  		printf("            Yeni Bilgiler:\n\n");//yeni bilgileri al.
	  		printf("Ad: "); scanf("%s",a.ad);
	  		printf("Yonetmen : "); scanf("%s",a.yonetmen);
	  		printf("Senarist : "); scanf("%s",a.senarist);
	      	printf("Basrol : "); scanf("%s",a.basrol);
	      	printf("Yil : "); scanf("%s",a.yil);
		}
			fprintf(yeni,"\n%s %s %s %s %s",a.ad,a.yonetmen,a.senarist,a.basrol,a.yil);
		}
			fclose(fp2);
			fclose(yeni);
			remove("filmliste.txt");
			rename("filmliste1.txt","filmliste.txt");
			printf("\nDevam Etmek Icin Herhangi Bir Tusa Basiniz..");
			_getch();
	}
	/*------------------------------------------------FÝLM SÝLME-----------------------------------------------*/
	else if(secim==4)
	{
		typedef Film flm;
		flm a;
		FILE *fp3,*yeni2; 
		char aranan[15],karar[5];
		printf("Silinecek Filmin Adi ? :");
		scanf("%s",aranan);
		fp3=fopen("filmliste.txt","r"); //bilgiler fp3'den okunacak.
		yeni2=fopen("filmliste1.txt","w"); //yeni bilgiler bu yeni2'ye yazýlacak.
		if(fp3==NULL) printf("Dosya Bulunamadi");
		printf("\nFilm Silinecektir Devam Etmek Istiyor musunuz? [E/H]: ");
		scanf("%s",karar);
		if(strcmp(karar,"E")==0)
		{
			while(!feof(fp3))
			{
				fscanf(fp3,"%s %s %s %s %s\n",a.ad,a.yonetmen,a.senarist,a.basrol,a.yil);
				if(strstr(a.ad,aranan))
				{
					continue;
				}
				fprintf(yeni2,"%s %s %s %s %s\n",a.ad,a.yonetmen,a.senarist,a.basrol,a.yil);
			}
				/*if(!strstr(a.ad,aranan))
				{
					printf("Listede Olan Bir Film Giriniz");
				}*/
		}
		else if(strcmp(karar,"H")==0)
		{
			printf("\nFILM SILINMEDI");
			printf("\nAna Menuye Donmek Icin Herhangi Bir Tusa Basiniz...");
			_getch();
			system("CLS");
			return main();
		}
		else
		{
			printf("\nGecerli Bir Deger Giriniz!");
			printf("\nAna Menuye Donmek Icin Herhangi Bir Tusa Basiniz...");
			_getch();
			system("CLS");
			return main();
		}
		fclose(fp3);
		fclose(yeni2);
		remove("filmliste.txt");
		rename("filmliste1.txt","filmliste.txt");
		printf("\nDevam Etmek Icin Herhangi Bir Tusa Basiniz..");
		_getch();
	}
	/*-----------------------------------------FÝLM ARAMA(TÜRLERE GÖRE)-----------------------------------------*/	
	else if(secim==5)
	{
		typedef Film flm;
		flm a;
		char aranan[15];
		int arama;
		system("CLS");
		printf("\tHangi Ture Gore Arama Yapmak Istiyorsunuz?\n");
		printf("\n\t*****************************************\n");
		printf("\t***                                   ***\n");
		printf("\t***          ARAMA TURLERI            ***\n");
		printf("\t***         ---------------           ***\n");
		printf("\t***         1-) Isme Gore             ***\n");
		printf("\t***         2-) Yonetmene Gore        ***\n");
		printf("\t***         3-) Senariste Gore        ***\n");
		printf("\t***         4-) Basrole Gore          ***\n");
		printf("\t***         5-) Yila Gore             ***\n");
		printf("\t***         6-) Ana Menu              ***\n");
		printf("\t***                                   ***\n");
		printf("\t*****************************************\n");
		printf("\t\t   Menu Secim: "); scanf("%d",&arama);
		printf("\n");
		/*----------------------------------------FÝLM ÝSMÝNE GÖRE ARAMA----------------------------------------*/
		if(arama==1)
		{
			typedef Film flm;
			flm a;
			char aranan[15];
			FILE *fp4 = fopen("filmliste.txt","r");
		 	if(fp4==NULL) printf("Dosya Bulunamadi");
		 	printf("\nAramak Istediginiz Film Adi: ");
		 	scanf("%s",aranan);
		 	printf("\nADI  \t  YONETMEN  SENARIST  \tBASROL      YIL");
			while(!feof(fp4))
			{
				fscanf(fp4,"\n%s %s %s %s %s\n",a.ad,a.yonetmen,a.senarist,a.basrol,a.yil);
				if(strcmp(aranan,a.ad)==0)
				{
					printf("\n%-10s %-10s%-10s %-10s  %-10s\n",a.ad,a.yonetmen,a.senarist,a.basrol,a.yil);
				}
			}
				fclose(fp4);
				printf("\nDevam Etmek Icin Herhangi Bir Tusa Basiniz..");
				_getch();
		}
		/*-------------------------------------FÝLM YÖNETMENÝNE GÖRE ARAMA-------------------------------------*/
		else if(arama==2)
		{
			typedef Film flm;
			flm a;
			char aranan[15];
			FILE *fp5 = fopen("filmliste.txt","r");
		 	if(fp5==NULL) printf("Dosya Bulunamadi");
		 	printf("\nAramak Istediginiz Yonetmen Adi: ");
		 	scanf("%s",aranan);
		 	printf("\nADI  \t  YONETMEN  SENARIST  \tBASROL      YIL");
			while(!feof(fp5))
			{
				fscanf(fp5,"\n%s %s %s %s %s\n",a.ad,a.yonetmen,a.senarist,a.basrol,a.yil);
				if(strcmp(aranan,a.yonetmen)==0)
				{
					printf("\n%-10s %-10s%-10s %-10s  %-10s\n",a.ad,a.yonetmen,a.senarist,a.basrol,a.yil);
				}
			}
				fclose(fp5);
				printf("\nDevam Etmek Icin Herhangi Bir Tusa Basiniz..");
				_getch();
		}
		/*-------------------------------------FÝLM SENARÝSTÝNE GÖRE ARAMA-------------------------------------*/
		else if(arama==3)
		{
			typedef Film flm;
			flm a;
			char aranan[15];
			FILE *fp6 = fopen("filmliste.txt","r");
		 	if(fp6==NULL) printf("Dosya Bulunamadi");
		 	printf("\nAramak Istediginiz Senarist Adi: ");
		 	scanf("%s",aranan);
		 	printf("\nADI  \t  YONETMEN  SENARIST  \tBASROL      YIL");
			while(!feof(fp6))
			{
				fscanf(fp6,"\n%s %s %s %s %s\n",a.ad,a.yonetmen,a.senarist,a.basrol,a.yil);
				if(strcmp(aranan,a.senarist)==0)
				{
					printf("\n%-10s %-10s%-10s %-10s  %-10s\n",a.ad,a.yonetmen,a.senarist,a.basrol,a.yil);
				}
			}
				fclose(fp6);
				printf("\nDevam Etmek Icin Herhangi Bir Tusa Basiniz..");
				_getch();
		}
		/*--------------------------------------FÝLM BAÞROLÜNE GÖRE ARAMA--------------------------------------*/
		else if(arama==4)
		{
			typedef Film flm;
			flm a;
			char aranan[15];
			FILE *fp7 = fopen("filmliste.txt","r");
		 	if(fp7==NULL) printf("Dosya Bulunamadi");
		 	printf("\nAramak Istediginiz Basrol Adi: ");
		 	scanf("%s",aranan);
		 	printf("\nADI  \t  YONETMEN  SENARIST  \tBASROL      YIL");
			while(!feof(fp7))
			{
				fscanf(fp7,"\n%s %s %s %s %s\n",a.ad,a.yonetmen,a.senarist,a.basrol,a.yil);
				if(strcmp(aranan,a.basrol)==0)
				{
					printf("\n%-10s %-10s%-10s %-10s  %-10s\n",a.ad,a.yonetmen,a.senarist,a.basrol,a.yil);
				}
			}
				fclose(fp7);
				printf("\nDevam Etmek Icin Herhangi Bir Tusa Basiniz..");
				_getch();
		}
		/*--------------------------------------------YILA GÖRE ARAMA-------------------------------------------*/
		else if(arama==5)
		{
			typedef Film flm;
			flm a;
			char aranan[15];
			FILE *fp8 = fopen("filmliste.txt","r");
		 	if(fp8==NULL) printf("Dosya Bulunamadi");
		 	printf("\nAramak Istediginiz Yil: ");
		 	scanf("%s",aranan);
		 	printf("\nADI  \t  YONETMEN  SENARIST  \tBASROL      YIL");
			while(!feof(fp8))
			{
				fscanf(fp8,"\n%s %s %s %s %s\n",a.ad,a.yonetmen,a.senarist,a.basrol,a.yil);
				if(strcmp(aranan,a.yil)==0)
				{
					printf("\n%-10s %-10s%-10s %-10s  %-10s\n",a.ad,a.yonetmen,a.senarist,a.basrol,a.yil);
				}
			}
				fclose(fp8);
				printf("\nDevam Etmek Icin Herhangi Bir Tusa Basiniz..");
				_getch();
		}
		/*-------------------------------------------ANA MENÜYE DÖNÜÞ------------------------------------------*/
		else if(arama==6)
		{
			system("CLS");
			return main();
		}
		/*---------------------------------------------HATA MESAJI---------------------------------------------*/
		else 
		{
			printf("Lutfen Gecerli Bir Deger Giriniz!");
			_getch();
			return main();
		}
	}
	
	else if(secim==6)
	{
		printf("\nCIKIS YAPTINIZ!");
		return 0;
	}
	/*-----------------------------------------------HATA MESAJI-----------------------------------------------*/
	else
	{
		printf("Lutfen Gecerli Bir Deger Giriniz!");
		_getch();
		system("CLS");
		return main();
	} 
		system("CLS");
		return main();
}
