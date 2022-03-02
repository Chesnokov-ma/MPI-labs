#include "mpi.h"
#include <stdio.h>

int main(int argc,char *argv[])
{
    int myrank, numprocs;
    MPI_Status status;
    int message;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
	MPI_Comm_rank(MPI_COMM_WORLD, &myrank);

    if (myrank % 2 == 0)
    {
        message = myrank;
        MPI_Send(&message,1,MPI_INT,myrank+1,0,MPI_COMM_WORLD);						  	
    }
    else
    {
		MPI_Recv(&message, 1, MPI_INT, myrank - 1,MPI_ANY_TAG, MPI_COMM_WORLD, &status);				
        printf("received: %d for %d\n", message, myrank);
    }

    MPI_Finalize();
    return 0;
}
