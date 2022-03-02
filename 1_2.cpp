#include "mpi.h"
#include <stdio.h>
int main(int argc,char *argv[])
{
    int myid, numprocs;
    char message[20];
    int myrank;
    MPI_Status status;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
	MPI_Comm_rank(MPI_COMM_WORLD, &myrank);

    if (myrank == 0)
    {
        strcpy(message, "Hi, Second Processor!");
        MPI_Send(&message,20,MPI_CHAR,1,0,MPI_COMM_WORLD);						  	
    }
    else
    {
		MPI_Recv(&message, 20, MPI_CHAR, 0, MPI_ANY_TAG, MPI_COMM_WORLD, &status);				
        printf("received: %s\n", message);
    }

    MPI_Finalize();
    return 0;
}
