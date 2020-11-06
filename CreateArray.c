#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
// Create array, insertion sort array and find index 


void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;


		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}

}

void printArray(int arr[], int n)
{

	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");

}

void BinarySearch(int arr[], int num, int first, int last) {

	int mid;

	if (first > last) {

		printf("Number is not found");

	}
	else {


		mid = (first + last) / 2;

		if (arr[mid] == num) {

			printf("Element is found at index %d ", mid);
			exit(0);

		}
		else if (arr[mid] > num) {

			BinarySearch(arr, num, first, mid - 1);

		}
		else {

			BinarySearch(arr, num, mid + 1, last);
		}
	}
}


int main() {

	int arr[100], beg, mid, end, i, n, num;

	printf("Enter the size of an array ");
	scanf("%d", &n);

	printf("Enter the values in sorted sequence \n");

	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}


	beg = 0;
	end = n - 1;

	printf("Enter a value to be search: ");
	scanf("%d", &num);

	insertionSort(arr, n);
	printArray(arr, n);
	BinarySearch(arr, num, beg, end);
	system("pause");
}
