#include <stdio.h>
#pragma warning(disable:4996)
// Print stars

int main(void) {
	int  i, j, z;

	for (i = 1; i <= 10; i++) {
        for (j = 1; j <= i; j++) {
			printf("*");

		}
		printf("\n");
	}
	
	for (i = 1; i <= 10; i++) {
		for (j = 10; j >= i; j--) {
			printf("*");
		}
		printf("\n");
	}
	
	for (i = 1; i <= 10; i++) {
		for (z = 1; z < i; z++) {
			printf(" ");
		}

		for (j = 10; j >= i; j--) {
			printf("*");
		}
		printf("\n");
	}
	
	for (i = 1; i <= 10; i++) {
		for (z = 10; z > i; z--) {
			printf(" ");
		}

		for (j = 1; j <= i; j++) {
			printf("*");
		}
		printf("\n");
	}

	system("pause");
}
