#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
// Create graph(undirected) and print the adjacency matrix,incidence matrix and the degree of graph 

void options() {

printf("\n\nOPTIONS MENU:\n");
	printf(" Please enter 1 to read the information of an undirected graph \n");
	printf(" Please enter 2  to find and print the adjacency matrix of the graph\n");
	printf(" Please enter 3  to find and print the incidence matrix of the graph\n");
	printf(" Please enter 4 to find and print the degree of the graph (largest vertex degree).\n");
	printf(" Please enter 5 to exit the program.\n");
}

void createGraph(int Matrix[25][25],int totalNodes){

    int i,j;
    int n,counter=0;

    for(i=0;i<totalNodes;i++){


        printf("\n");


        for(j=i;j<totalNodes;j++){


            printf("How many edges between vertex %d is Adjacent to vertex %d ? : ",i+1,j+1);


            scanf("%d",&n);
            counter=counter+n;


                Matrix[i][j]=n;
                Matrix[j][i]=n;

        }

    }
    printf("\nnumber of edge:%d\n" ,counter);
  printf("\nEndpoints:");
				for (i = 0; i < totalNodes; i++) {
		
		for (j = 0; j < totalNodes; j++) {
			
		}
		printf("\n %d\n", i+1);
	}
}


void displayAdjacencyMatrix(int Matrix[25][25],int totalNodes){

    int i,j;


    printf("\n\n");

    for(i=0;i<totalNodes;i++){

        for(j=0;j<totalNodes;j++){
        

            printf(" %d",Matrix[i][j]);

        }

        printf("\n");

    }

}

void createGraphForIncidence(int newMatrix[25][25],int totalNodes,int counter){

    int i,j;

    char a;


    for(i=0;i<totalNodes;i++){


        printf("\n");


        for(j=i;j<counter;j++){


            printf("Is vertex %d is incidence to edge %d ? (Y/N): ",i+1,j+1);

            fflush(stdin);

            scanf("%c",&a);


            if(a=='Y' || a=='y'){

                newMatrix[i][j]=1;

                newMatrix[j][i]=1;

            }else{

                newMatrix[i][j]=0;

                newMatrix[j][i]=0;

            }

        }

    }

}
void displayIncidenceMatrix(int newMatrix[25][25],int totalNodes,int counter){

    int i,j;


    printf("\n\n");

    for(i=0;i<totalNodes;i++){

        for(j=0;j<counter;j++){

            printf(" %d",newMatrix[i][j]);

        }

        printf("\n");

    }

}

void degree(int Matrix[25][25], int totalNodes) {
	
	int i,j,sumLine;
	int lineMatrix[totalNodes];
	for (i = 0; i < totalNodes; i++) {
		sumLine = 0;
		for (j = 0; j < totalNodes; j++) {
			sumLine += Matrix[i][j];
		}
		lineMatrix[i] = sumLine;
		printf("\nDegree of %d. node: %d\n", i + 1, sumLine);
	}
}

int main(){


    int choice,Matrix[25][25],totalNodes,newMatrix[25][25];
int i,j,counter;

    while(1){
    	

       options();
		printf("\nPlease enter choice:");
        scanf("%d",&choice);

        switch(choice){

            case 1 :

                printf("Enter total no of vertex: ");

                scanf("%d",&totalNodes);

                Matrix[25][25]=0;

                createGraph(Matrix,totalNodes);
                
              
		
            break;

            case 2 : 
			   displayAdjacencyMatrix(Matrix,totalNodes);
			   break;

            case 3 :
            	printf("Please number of vertex:");
            	scanf("%d" ,&totalNodes);
            	printf("Please number of edge:");
            	scanf("%d" ,&counter);
            
                 createGraphForIncidence( newMatrix, totalNodes,counter);
                 displayIncidenceMatrix( newMatrix, totalNodes, counter);
            break;
            
            case 4:
            
            degree(Matrix,totalNodes);
            	break;
            	
            	case 5:
            		 exit(0);
            		 }

    }

 return 0;
system("pause");
}


