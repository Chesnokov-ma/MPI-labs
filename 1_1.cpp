#include "mpi.h"
#include <stdio.h>

int main(int argc,char *argv[])
{
    int my_id, numprocs;
	MPI_Init(&argc, &argv);

	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_id);					
    fprintf(stdout,"Process %d of %d\n", my_id, numprocs);

    MPI_Finalize();
    return 0;
} 
