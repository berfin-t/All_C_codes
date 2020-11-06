#include<stdio.h>
#pragma warning(disable:4996)
#define size 10
// Find magic matrix 

int calculate_cross(int size, int matrix[][size]) { // sum of cross index in matrix
	int firstCross = 0, lastCross = 0;
	int control1 = 0, control2 = size - 1;
	int i, j;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			if (i == j) {
				firstCross += matrix[i][j];
			}
			if ((i == control1) && (j == control2)) {
				lastCross += matrix[i][j];
				control1++;
				control2--;
			}
		}
	}
	printf("1. Sum of cross: %d\n2.Sum of cross: %d\n", firstCross, lastCross);
	printf("\n");
	if (firstCross == lastCross) {
		return firstCross;
	}
	else {
		return -5;
	}
}

int calculate_line(int size, int matrix[][size]) { // sum of line index in matrix
	int i, j, sumLine;
	int lineMatrix[size];
	for (i = 0; i < size; i++) {
		sumLine = 0;
		for (j = 0; j < size; j++) {
			sumLine += matrix[i][j];
		}
		lineMatrix[i] = sumLine;
		printf("%d. Sum of line: %d\n", i + 1, sumLine);
	}


	printf("\n");

	int control = 0;

	int x;
	for (x = 0; x < size - 1; x++) {
		if (lineMatrix[x] != lineMatrix[x + 1]) {
			control++;
		}
	}
	if (control == 0) {
		return lineMatrix[0];
	}
	else {
		return -5;
	}
}

int calculate_column(int size, int matrix[][size]) { // sum of column index in matrix
	int i, j, sumColumn;
	int columnMatrix[3];

	for (i = 0; i < size; i++) {
		sumColumn = 0;
		for (j = 0; j < size; j++) {
			sumColumn += matrix[j][i];
		}
		printf("%d. Sum of column: %d\n", i + 1, sumColumn);
		columnMatrix[i] = sumColumn;
	}
	printf("\n");

	int control = 0;
	int x;
	for (x = 0; x < size - 1; x++) {
		if (columnMatrix[x] != columnMatrix[x + 1]) {
			control++;
		}
	}

	if (control == 0) {
		return columnMatrix[0];
	}
	else {
		return -5;
	}
}

int checkResult(int size, int matrix[][size]) {
	int lineResult = calculate_line(size, matrix);
	int columnResult = calculate_column(size, matrix);
	int crossResult = calculate_cross(size, matrix);
	if ((lineResult != -5) && (columnResult == lineResult) && (columnResult == crossResult)) {
		return 0;
	}
	else {
		return -2;
	}
}

int program(int size) {
	int i, j;
	int matrix[size][size]; 

	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			printf("%d x %d enter the number:\n", i + 1, j + 1);
			scanf("%d", &matrix[i][j]);

		}
	}
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			printf("%d\t", matrix[i][j]); 

		}
		printf("\n");
	}
	printf("\n");
	if (checkResult(size, matrix) == 0) {
		printf("-->This is magic matrix");
	}
	else {
		printf("-->This is not magic matrix");
	}
}

void main() {
	int size;
	printf("Enter the size:\n");
	scanf("%d", &size); 
	if (size > 0) {
		program(size);
	}
	else {
		printf("Error");
	}
	system("pause");

}