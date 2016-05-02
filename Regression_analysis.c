#include <stdio.h>
#include <math.h>

double ortalama_bul(double dizi[],int boyut);
double standart_sapma_bul(double dizi[],int boyut);
double ro_bul(double dizi_x[],double dizi_y[],int boyut);

int main()
{
	int boyut = 0;
	printf("Veriler kac elemanli olucak ? ");
	scanf("%d",&boyut);
	
	double dizi_x[boyut];
	double dizi_y[boyut];
	
	int i;
	
	printf("1.Dizinin elemanarini giriniz \n");	
	for(i=0;i<boyut;i++)
	{
		printf("%d.Eleman : ",i+1);
		scanf("%lf",&dizi_x[i]);
	}
	
	printf("2.Dizinin elemanarini giriniz \n");
	for(i=0;i<boyut;i++)
	{
		printf("%d.Eleman : ",i+1);
		scanf("%lf",&dizi_y[i]);
	}
	

	
	double x_ort = ortalama_bul(dizi_x,boyut);
    double y_ort = ortalama_bul(dizi_y,boyut);
	
	double x_ss = standart_sapma_bul(dizi_x,boyut);
	double y_ss = standart_sapma_bul(dizi_y,boyut);
	
	
	printf("1.Dizinin ortalamasi = %lf \n",x_ort);
	printf("1.Dizinin standart sapmasi = %lf \n",x_ss);
	printf("2.Dizinin ortalamasi = %lf \n",y_ort);
	printf("2.Dizinin standart sapmasi = %lf \n",y_ss);
	
		
	double ro = ro_bul(dizi_x,dizi_y,boyut);
	
	printf("Ro degeri = %lf ",ro);
	

	
	return 0;
}


double ortalama_bul(double dizi[],int boyut)
{
	double toplam = 0;
	int i;
	
	for(i=0;i<boyut;i++)
	{
		toplam += dizi[i];
	}
	
	return (toplam / boyut);
}

double standart_sapma_bul(double dizi[],int boyut)
{
		double dizi_yerel[boyut];
		
		double ort = ortalama_bul(dizi,boyut);
		
		double toplam = 0;
		
		int i;
		
		/*Gelen dizideki değerler değişmemesi için, değerler oluşturulan yerel diziye aktarılıyor.*/
		for(i=0;i<boyut;i++)
		{
			dizi_yerel[i] = dizi[i];
		}
		
		
		for(i=0;i<boyut;i++)
		{
			dizi_yerel[i] = dizi_yerel[i] - ort; /*Her elemandan dizinin ortalaması cikartiliyor.*/
			dizi_yerel[i] = dizi_yerel[i] * dizi_yerel[i]; /*Her elemanın karesi alınıyor.*/
			toplam = toplam + dizi_yerel[i]; /*Her eleman son haliyle toplama ekleniyor.*/
		}
		
		return sqrt(toplam /(boyut-1));
		
}

double ro_bul(double dizi_x[],double dizi_y[],int boyut)
{
	double toplam = 0;
	
	double x_ort = ortalama_bul(dizi_x,boyut);
	double y_ort = ortalama_bul(dizi_y,boyut);
	
	double x_ss = standart_sapma_bul(dizi_x,boyut);
	double y_ss = standart_sapma_bul(dizi_y,boyut);
	
	double dizi[boyut];
	
	int i;
	
	for(i=0;i<boyut;i++)
	{
		dizi[i] = (dizi_x[i] - x_ort) * (dizi_y[i] - y_ort);
		printf("%lf + ",dizi[i]);
		toplam += dizi[i];
	}
	printf("\n");
	
	printf("= %lf / ",toplam);
	printf("%lf \n",boyut*x_ss*y_ss);
	
	return (toplam / (boyut * x_ss * y_ss));
}
