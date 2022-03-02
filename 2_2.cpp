#include <stdio.h> 
#include <stdlib.h> 
#include <mpi.h>
#include <math.h> 
int main(int argc,char **argv) 
{    
    int myrank, numprocs;
    MPI_Status status; 
    int mytag,kk;
    int count_k = 5;
    int j[count_k],*mas; 

    // Для демонстрации я немного изменил программу
  
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
	MPI_Comm_rank(MPI_COMM_WORLD, &myrank);

    printf(" Hello from process: %d  Numprocs is %d\n",myrank,numprocs);
    mytag=150;

    if(myrank == 0) 
    {
        for (int i = 0; i < count_k; i++)   j[i] = 200 + 100 * i;    // в буфере 5 элементов
        MPI_Send(&j,count_k,MPI_INT,1,mytag,MPI_COMM_WORLD);
    } 
    if(myrank == 1)
    {
        MPI_Probe(0, mytag, MPI_COMM_WORLD, &status);
        MPI_Get_count(&status, MPI_INT, &count_k);

        mas=(int*)malloc(count_k*sizeof(int));      // память динамически выделяется под 5 эл-ов
        printf("getting %d\n",count_k);

        MPI_Recv(mas, count_k, MPI_INT, 0, mytag, MPI_COMM_WORLD, &status);
        printf("mas= ");

        for(int i=0; i<count_k; i++)
            printf("%d ", mas[i]); 
        printf("\n"); 
    } 
    MPI_Finalize(); 
} 
