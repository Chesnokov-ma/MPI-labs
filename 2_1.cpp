#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
int main(int argc,char *argv[]) 
{
	MPI_Init(&argc, &argv);
    int *buffer; int myrank;
    MPI_Status status;
    int buffsize = 1;
    int TAG = 0; 
	MPI_Comm_rank(MPI_COMM_WORLD, &myrank);

    if (myrank == 0) 
    {
        buffer = (int *) malloc(buffsize + MPI_BSEND_OVERHEAD);
        MPI_Buffer_attach(buffer, buffsize);

        // ?????????

        buffer = (int *) 10;

        MPI_Bsend(&buffer,buffsize,MPI_INT,1,0,MPI_COMM_WORLD);
    }
    else 
    { 
        MPI_Recv(&buffer, buffsize, MPI_INT, 0, TAG, MPI_COMM_WORLD, &status);
        printf("received: %i\n", buffer); 
    }

    MPI_Buffer_detach(&buffer, &buffsize);
    MPI_Finalize();
    return 0; 
}  
