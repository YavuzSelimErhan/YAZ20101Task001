#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

//Þifrelemeyi ve deþifreleme fonksiyonlarý tanýmlayýp main fonksiyonundan sonra bu fonksiyonlarýn iþlevlerini tanýmlýyoruz.

void sifrele(char metin[], int anahtar);
void desifrele(char metin[], int anahtar);

int main()
{
	
	//Gerekli deðiþkenleri tanýmlýyoruz.
	
	char karakter[1000];
	int anahtar, i;
	
	//Þifreleme bir txt belgesinden olacaðý için input 1.txt isimli dosyayý açýyoruz ve sonra bu dosyanýn þifreli hali olmasý için output dosyasý oluþturuyoruz.
	
	FILE *dosya = fopen("Sifrelenmis.txt", "r+");
	FILE *dosya1 = fopen("Desifrelenmis.txt", "w+");
	
	//Eðer input 1.txt isimli bir dosya bulanamdýysa hata verdirtiyoruz.
	
	if (dosya == NULL) 
	{
        printf("Dosya bulunamadi");
        return 0;
    }
    
    //Kullanýcýdan anahtar deðerini alýyoruz.
    
    printf("Anahtar Degeri:");
    scanf("%d", &anahtar);
    
    //Dosyada alt satýra geçebilmek için getchar kullanýyoruz.

    getchar();
    
    //Döngünün dosya sonlanýnca bitmesini saðlýyoruz ve dosyadan tanýmlanan karakterleri döngü içinde deþifreliyoruz.(Döngünün sebebi boþluk görünce durmasýný önlemek.)

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
