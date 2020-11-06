#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)
// Flight information using linked list 

struct list { // information of flight

	char source[50];
	char destination[50];
	int number;

	struct	list* next;
	struct	list* previous;
};

struct list* prev = NULL, * ptr = NULL, * temp = NULL, * end;
struct list* first = NULL, * point = NULL, * temp1 = NULL, * last;

int sort() {

	if (first == NULL) {

		first = (struct list*)malloc(sizeof(struct list));
		first = prev;
		first->next = NULL;
		first->previous = NULL;
		last = first;
	}
	else {

		point = (struct list*)malloc(sizeof(struct list));
		point = prev;


		if (point->number <= first->number) {

			point->next = first;
			point->next = NULL;
			first->next = first;
			first = point;

		}
		else {
			temp1 = first;

			while (temp1->number < point->number) {

				if (temp1->next == NULL) {
					temp1->next = point;
					point->previous = temp1;
					point->next = NULL;
					last = point;
					break;
				}

				temp1 = temp1->next;

			}
			if (temp1->next != point) {

				point->previous = temp1->previous;
				temp1->previous = point;
				point->previous->next = point;
				point->next = temp1;
			}
		}
	}
	point = NULL;
	temp1 = NULL;

	printf("\n\n   !!!!!    Your Transaction Has Succeeded    !!!!!!");
}


int display1() {

	if (prev == NULL) { printf(" \n\n !!!  Nobody on the List !!!"); return 0; }

	point = prev;

	while (point != NULL) {

		printf("\n\tSorurce - Destination: %s\t - %s\tNumber  : %d ", point->source, point->destination, point->number);


		point = point->next;
	}
	point = NULL;
}

int adding() {


	if (prev == NULL) {

		prev = (struct list*)malloc(sizeof(struct list));
		printf("\n Enter source \t\t:  ");
		scanf("%s", prev->source);
		printf("\n Enter destination \t\t:  ");
		scanf("%s", prev->destination);
		printf("\n Enter number \t:  ");
		scanf("%d", &prev->number);


		prev->next = NULL;
		prev->previous = NULL;
		end = prev;
	}
	else {

		ptr = (struct list*)malloc(sizeof(struct list));
		printf("\n Enter source \t\t:  ");
		scanf("%s", ptr->source);
		printf("\n Enter destination \t\t:  ");
		scanf("%s", ptr->destination);
		printf("\n Enter number \t:  ");
		scanf("%d", &ptr->number);


		if (ptr->number <= prev->number) {

			ptr->next = prev;
			ptr->previous = NULL;
			prev->previous = ptr;
			prev = ptr;

		}
		else {
			temp = prev;

			while (temp->number < ptr->number) {

				if (temp->next == NULL) {
					temp->next = ptr;
					ptr->previous = temp;
					ptr->next = NULL;
					end = ptr; break;
				}

				temp = temp->next;

			}
			if (temp->next != ptr) {

				ptr->previous = temp->previous;
				temp->previous = ptr;
				ptr->previous->next = ptr;
				ptr->next = temp;
			}
		}
	}
	ptr = NULL;
	temp = NULL;

	printf("\n\n   !!!!!    Your Transaction Has Succeeded    !!!!!!");
}


int deleting() {

	if (prev == NULL) { printf(" \n\n !!!  Nobody on the List !!!"); return 0; }

	int del;
	printf("\n\n Enter the number you want to delete : ");
	scanf("%d", &del);

	temp = prev;

	if (prev->number == del) {

		if (prev->next == NULL) {
			free(prev);
			prev = NULL;
			temp = NULL;
			printf("\n\n   !!!!!   Your Transaction Has Succeeded   !!!!!!");
			return 0;
		}

		prev->next->previous = NULL;
		prev = prev->next;
		free(temp);
		temp = NULL;
		printf("\n\n   !!!!!   Your Transaction Has Succeeded     !!!!!!");
		return 0;
	}


	while (temp->number != del) {
		temp = temp->next;
		if (temp == NULL)break;

	}

	if (temp == NULL) {

		printf(" \n\n !!!  No such number is listed !!!");
	}
	else {
		if (temp->next == NULL) {
			temp->previous->next = NULL;
			free(temp);
			temp = NULL;
		}
		else {

			temp->previous->next = temp->next;
			temp->next->previous = temp->previous;
			free(temp);
			temp = NULL;
		}
		printf("\n\n   !!!!!   Your Transaction Has Succeeded   !!!!!!");
	}
}

int display() {

	if (prev == NULL) { printf(" \n\n !!!  Nobody on the List  !!!"); return 0; }

	ptr = prev;

	while (ptr != NULL) {

		printf("\n\t Source - Destination: %s\t - %s\tNumber : %d ", ptr->source, ptr->destination, ptr->number);


		ptr = ptr->next;
	}
	ptr = NULL;
}

void options() {
	printf("\nPlease enter 1 to insert a flight");
	printf("\nPlease enter 2 to delete a flight.");
	printf("\nPlease enter 3 to sort the flights according to their numbers in ascendingorder.");
	printf("\nPlease enter 4 to print the information of all flights. ");
	printf("\nPlease enter 5 to exit the program");
}

int main() {

	int choice;
	int number;

	do {
		options();

		printf("\n\n\n\t\t Enter the option number you want to select:  \n\n");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			adding();
			break;
		case 2:
			deleting();
			break;
		case 3:
			display1();
			break;
		case 4:
			display();
			break;
		}
	} while (choice != 5);

		
	return 0;
	system("pause");
}