#include<iostream>
#include<cmath>
#include<random>
#include<vector>
#include<mpi.h>

int MontCarloPi( int n, int seed);
double ResultAccumulation(int x, int pi, int np, int N);
double maximum( std::vector<double> input );

int main(int argc, char * argv[])
{	

	MPI_Init(&argc, &argv);
	int N = std::atoi(argv[1]); //total number of samples
	int CommSeed = 1; //This allow us to change in the set of seeds to be used
	
	int pid; //process id
	int np; //number of processes
	MPI_Comm_size(MPI_COMM_WORLD, &np);
	MPI_Comm_rank(MPI_COMM_WORLD, &pid);

	int localsample = (int)(N/np);
	
	double init_time = MPI_Wtime();
	
	int localresult = MontCarloPi(localsample,CommSeed*np+ pid);
	double total_result = ResultAccumulation(localresult, pid, np, N);

	double final_time = MPI_Wtime();
	double local_time = final_time - init_time;

	std::vector<double> times(np);

	if(pid != 0)
	{
		MPI_Send(&local_time, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
	} else {
		times[0]=local_time;
		for(int ipid=1; ipid < np; ++ipid)
		{
		MPI_Recv(&times[ipid], 1, MPI_INT, ipid, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		}
		double total_time= maximum(times);
		std::cout << total_result << "\t" << np << "\t" << total_time << "\n";

	}



	MPI_Finalize();

}

double ResultAccumulation(int val, int pid, int np, int N)
{
	int tag=0;
	if(pid != 0)
	{
		MPI_Send(&val, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
		return 0;
	}else {
		double total = val;
		for (int ipid = 1; ipid < np; ++ipid)
		{
		MPI_Recv(&val, 1, MPI_INT, ipid, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		total += val;
		}
		return 4.0*total/N;
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
double maximum( std::vector<double> a )
{
	double result=a[0];
	int size= a.size();
	
	for( int ii=0; ii < size; ii++)
	{
		if( a[ii] > result )
		{ result= a[ii];}
	}
	return result;
}
