#include <stdio.h>
#pragma warning(disable:4996)
// find what day of the week

int main(void) {

	int i;
	printf("sayiyi giriniz:");
    scanf("%d",&i);

	switch (i) {
	case 1: printf("pazartesi\n"); break;
	case 2: printf("sali\n"); break;
	case 3: printf("carsamba\n"); break;
	case 4: printf("persembe\n"); break;
	case 5: printf("cuma\n"); break;
	case 6: printf("cumartesi\n"); break;
	case 7: printf("pazar\n"); break;
	default:
		printf("HATA!Bilinmeyen bir deger girdiniz\n");
	}
	
	system("pause");
}
