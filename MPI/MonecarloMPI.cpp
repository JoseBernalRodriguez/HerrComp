#include<iostream>
#include<cmath>
#include<random>
#include<mpi.h>
int MontCarloPi( int n, int seed);
void ResultAccumulation(int x, int pi, int np, int N);

int main(int argc, char * argv[])
{	

	MPI_Init(&argc, &argv);
	int N = std::atoi(argv[1]); //total number of samples
    int CommSeed = std::atoi(argv[2]); //This allow us to change in the execution the set of seeds to be used
	
	int pid; //process id
	int np; //number of processes
	MPI_Comm_size(MPI_COMM_WORLD, &np);
	MPI_Comm_rank(MPI_COMM_WORLD, &pid);

	int localsample = (int)(N/np);

	int localresult = MontCarloPi(localsample,CommSeed*np+ pid);
	ResultAccumulation(localresult, pid, np, N);



	MPI_Finalize();

}

void ResultAccumulation(int val, int pid, int np, int N)
{
	int tag=0;
	if(pid != 0)
	{
		MPI_Send(&val, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
	}else {
		double total = val;
		for (int ipid = 1; ipid < np; ++ipid)
		{
		MPI_Recv(&val, 1, MPI_INT, ipid, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		total += val;
		}
		std::cout << 4.0*total/N << "\n";
	}
}

int MontCarloPi( int n, int seed)
{
	int count=0;
	std::mt19937 gen(seed);
	std::uniform_real_distribution<double> dis(-1.0,1.0);
	for( int ii=0; ii < n; ++ii)
	 {
		double x = dis(gen);
		double y = dis(gen);
		if (x*x + y*y < 1) 
		{ count++; }
	}
	return count;
}
