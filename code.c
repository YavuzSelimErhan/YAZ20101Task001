#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void sifrele(char metin[], int anahtar);
void desifrele(char metin[], int anahtar);

int main()
{
	//Gerekli de�i�kenleri tan�ml�yoruz.
	
	char karakter[1000];
	int anahtar, secim;
	char karakterdizisi[26];
	
	//Kullan�c�dan de�i�kenlerin de�erlerini al�yoruz.
	
	printf("Metin: ");
	gets(karakter);
	
	printf("Anahtar Degeri:");
	scanf("%d",&anahtar);
	
	//Kullan�c�ya hangi i�lemin yap�lmas�n� istedi�ini se�tiriyoruz.
	
	printf("Sifreleme yapacaksaniz 1 Desifreleme yapacaksaniz 2 yaziniz:");
	scanf("%d",&secim);
	
	//Kullan�c�n�n yapt��� se�ime g�re �ifreleme ve de�ifreleme uygulan�p ekrana yazd�r�yoruz.
	
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

//B�y�k ve k���k harfe dikkat ederek tan�mlad���m�z sifreleme fonksiyonuna �ifreleme i�leminin nas�l yap�laca��n� tan�ml�yoruz.
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

// �ifreleme i�lemini tersine �evirerek de�ifreleme fonksiyonuna de�ifreleme i�lemini tan�ml�yoruz.

void desifrele(char karakter[], int anahtar) 
{
    sifrele(karakter, 26 - anahtar);
}
