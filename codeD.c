#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

//�ifrelemeyi ve de�ifreleme fonksiyonlar� tan�mlay�p main fonksiyonundan sonra bu fonksiyonlar�n i�levlerini tan�ml�yoruz.

void sifrele(char metin[], int anahtar);
void desifrele(char metin[], int anahtar);

int main()
{
	
	//Gerekli de�i�kenleri tan�ml�yoruz.
	
	char karakter[1000];
	int anahtar, i;
	
	//�ifreleme bir txt belgesinden olaca�� i�in input 1.txt isimli dosyay� a��yoruz ve sonra bu dosyan�n �ifreli hali olmas� i�in output dosyas� olu�turuyoruz.
	
	FILE *dosya = fopen("Sifrelenmis.txt", "r+");
	FILE *dosya1 = fopen("Desifrelenmis.txt", "w+");
	
	//E�er input 1.txt isimli bir dosya bulanamd�ysa hata verdirtiyoruz.
	
	if (dosya == NULL) 
	{
        printf("Dosya bulunamadi");
        return 0;
    }
    
    //Kullan�c�dan anahtar de�erini al�yoruz.
    
    printf("Anahtar Degeri:");
    scanf("%d", &anahtar);
    
    //Dosyada alt sat�ra ge�ebilmek i�in getchar kullan�yoruz.

    getchar();
    
    //D�ng�n�n dosya sonlan�nca bitmesini sa�l�yoruz ve dosyadan tan�mlanan karakterleri d�ng� i�inde de�ifreliyoruz.(D�ng�n�n sebebi bo�luk g�r�nce durmas�n� �nlemek.)

    int lineCount = 0;
    
    while (fgets(karakter, sizeof(karakter), dosya) != NULL)
    {
    size_t length = strlen(karakter);
    if (length > 0 && karakter[length - 1] == '\n')
    {
        karakter[length - 1] = '\0';
    }

    desifrele(karakter, anahtar);
    fprintf(dosya1, "%s ", karakter);
    fprintf(dosya1, "\n");
    lineCount++;
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
