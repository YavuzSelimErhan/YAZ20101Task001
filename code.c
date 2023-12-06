#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void sifrele(char metin[], int anahtar);
void desifrele(char metin[], int anahtar);

int main()
{
	//Gerekli deðiþkenleri tanýmlýyoruz.
	
	char karakter[1000];
	int anahtar, secim;
	char karakterdizisi[26];
	
	//Kullanýcýdan deðiþkenlerin deðerlerini alýyoruz.
	
	printf("Metin: ");
	gets(karakter);
	
	printf("Anahtar Degeri:");
	scanf("%d",&anahtar);
	
	//Kullanýcýya hangi iþlemin yapýlmasýný istediðini seçtiriyoruz.
	
	printf("Sifreleme yapacaksaniz 1 Desifreleme yapacaksaniz 2 yaziniz:");
	scanf("%d",&secim);
	
	//Kullanýcýnýn yaptýðý seçime göre þifreleme ve deþifreleme uygulanýp ekrana yazdýrýyoruz.
	
	if(secim == 1)
	{
	sifrele(karakter, anahtar);
	printf("Sifrelenen metin: %s", karakter);
    }
    
    else if(secim == 2)
    {
	desifrele(karakter, anahtar);
	printf("Desifre edilen metin: %s", karakter);
	}
	
	else
	{
		printf("Gecersiz Deger Girisi");
		return 0;
	}
	
	
	return 0;
}

//Büyük ve küçük harfe dikkat ederek tanýmladýðýmýz sifreleme fonksiyonuna þifreleme iþleminin nasýl yapýlacaðýný tanýmlýyoruz.
void sifrele(char karakter[], int anahtar) 
{
	int i;
    for (i = 0; karakter[i] != '\0'; i++) 
	{
        if (isalpha(karakter[i]))
		{
            if (isupper(karakter[i])) 
			{
                karakter[i] = (karakter[i] - 'A' + anahtar) % 26 + 'A';
            } else 
			{
                karakter[i] = (karakter[i] - 'a' + anahtar) % 26 + 'a';
            }
        }
    }
}

// Þifreleme iþlemini tersine çevirerek deþifreleme fonksiyonuna deþifreleme iþlemini tanýmlýyoruz.

void desifrele(char karakter[], int anahtar) 
{
    sifrele(karakter, 26 - anahtar);
}
