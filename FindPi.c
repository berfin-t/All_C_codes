#include <stdio.h>
#pragma warning(disable:4996)
// Finding at what step pi will be 3.14

int main(void) {

	int piKontrol, i = 1, x = 1, adim = 0;
	float sonPi = 0;
	float pi = 0;
	while (i < 2000) {
		if (x % 2 == 0) {
			pi -= (4.0 / i);

		}
		else {
			pi += (4.0 / i);
		}
		printf("%d. adim pi: %f\n", x, pi);

		piKontrol = pi * 100;

		if (piKontrol == 314) {
			if (adim == 0) {
				adim = x;
				sonPi = pi;
			}
		}
		i += 2;
		x++;
	}
	printf("\nsonuc: %d. adim pi: %f\n", adim, sonPi);

system("pause");
}
