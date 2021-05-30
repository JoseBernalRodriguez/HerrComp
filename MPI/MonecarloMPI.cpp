#include<iostream>
#include<cmath>

int MontCarloPi( int n, int seed);

int main(int argc, char * argv[])
{	

	MPI_Init(&argc, &argv);
	int N = std::atoi(argv[1]); //total number of samples
        int seed = std::atoi(argv[2]);
	
	int pid; //process id
	int np; //number of processes
	MPI_Comm_size(MPI_COMM_WORLD, &np);
	MPI_Comm_rank(MPI_COMM_WORLD, &pid);
	
	int localresult = MontCarloPi((int)(N/np), seed); 
	std::cout << localresult << std::endl;
	
	MPI_Finalize();

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
