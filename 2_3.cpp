#include <stdio.h> 
#include <stdlib.h> 
#include <mpi.h> 
#include <math.h> 
  
  
int main(int argc, char *argv[])
{
    int myrank, numprocs;     
    int buffer;

    MPI_Status status; 
    MPI_Request request; 
  
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
	MPI_Comm_rank(MPI_COMM_WORLD, &myrank);

    int tag=1500, source=0, purpose=1, count=1; 
    request=MPI_REQUEST_NULL;

    if(myrank == source)
    {
        buffer=6780; 
        MPI_Isend(&buffer,count,MPI_DOUBLE,purpose,tag,MPI_COMM_WORLD, &request);
    } 
    if(myrank == purpose)
    { 
        MPI_Irecv(&buffer, count, MPI_DOUBLE, source, tag, MPI_COMM_WORLD, &request); 
    }

    MPI_Wait(&request,&status);     // синхронизация процессов

    if(myrank == source)
    { 
        printf("processor %d  sent %d\n",myrank,buffer);
    } 
    if(myrank == purpose)
    { 
        printf("processor %d  receive %d\n",myrank,buffer);
    } 

    MPI_Finalize(); 
} 
 
