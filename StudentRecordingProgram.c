#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)
// Student recording program using the linked list 

void options () {
	printf("\n\nOPTIONS MENU:\n");
	printf(" Please enter 1 to add a new record of students.\n");
	printf(" Please enter 2 to search for a student (using its ID number).\n");
	printf(" Please enter 3 to sort the records of students according to their ID numbers in an ascending order.\n");
	printf(" Please enter 4 to show the information of all students.\n");
	printf(" Please enter 5 to exit the program.\n");
	
}

struct student {
	char name[25];
	char surname[25];
	char major[50];
	int id;
};

struct student data[100];
int s; 
int result=0;

void acceptStudent(struct student list[100], int s) //s:size
{
    int i ,n;
    int counter=0;
     printf("\nNumber of accept you want to enter? : ");
   	 scanf("%d", &s);
    
    for (i =result; i <result+ s; i++)
    {
        printf("\nEnter name : ");
        scanf("%s", &list[i].name);
        printf("Enter surname : ");
        scanf("%s" ,&list[i].surname);
        printf("Enter major : ");
        scanf("%s", &list[i].major);
        printf("Enter ID:");
        scanf("%d" ,&list[i].id);
        counter++;
    } 
    result+=counter;
    
}

void display(struct student list[100] ,int s) {
	int i;
	for(i=0; i<result; i++) {
		
		printf("\nNAME:%s\nSURNAME:%s\nMAJOR:%s\nID:%d\n" ,list[i].name ,list[i].surname ,list[i].major ,list[i].id);
	
	}
	
}

void searchId() {
	int i,a=0;
	int number;
	printf("please enter a number to search ID:");
	scanf("%d",&number);
	for(i=0; i<result; i++) {
		if(data[i].id==number) {
			printf("\nNAME:%s\nSURNAME:%s\nMAJOR:%s\nID:%d\n" ,data[i].name ,data[i].surname ,data[i].major ,data[i].id);
			a=1;
		break;
		}
	} 
	if(a==0)
    	printf("\nID is not found!");
	
}

void sort(struct student list[] ,int s)
{
	int i,j ,temp;
	for(i=0; i<result; i++) {
		for(j=1; j<result-1; j++) {
			if(list[j-1].id > list[j].id) {
				temp = list[j].id;
				list[j].id = list[j-1].id;
				list[j-1].id = temp;
			}
		}
	}
}

int printSort (struct student list[100] ,int s) {
	int i;

	sort(list ,s);
	for(i=0; i<result; i++) {
	    printf("ID:%d\n" ,list[i].id);
	}
}

int main() {
	
	int x, choice ,n ,id ,i ,s ,j ,number;
	int list[i];
	options();
	acceptStudent(data, s);
	
	do{
	
	options();
	printf("\nEnter the option number you want to select: ");
	scanf("%d" ,&choice);

	switch (choice) {
		case 1:
    		acceptStudent(data ,s);
    	    break;
    	    
		case 2:
		    searchId();
		    break;
				
		case 3:
			printSort(data ,n);
		    break;
		    
		case 4:
			display(data ,n);
			break;	
	
	}
}
	
	while(choice != 5);

	return 0;
	system("pause");
}

