#include<iostream>
double func(double x);
double Integral(double xi, double xf, int Nsteps, double (*fptr)(double));
double TrapesoidIntegral(double xi, double xf,int Nsteps, double (*fptr)(double));
int main(int argc,char *argv[])
{
    double A=Integral(0,10.0,std::atoi(argv[1]),func);
    double B=TrapesoidIntegral(0,10.0,std::atoi(argv[1]),func);

    std::cout.precision(15); std::cout.setf(std::ios::scientific);
    std::cout << A << "\t"   \
        << std::abs(A-1000/3)/(1000/3) << "\n";
    std::cout << B << "\t"   \
        << std::abs(B-1000/3)/(1000/3) << "\n";
    return 0;
}

double func(double x)
{
    return x*x;
}

double Integral(double xi, double xf,int Nsteps, double (*fptr)(double))
{
    double deltx= (xf-xi)/Nsteps;
    double result=0;
#pragma omp parallel for reduction(+:result)
    for(int ii=1; ii <= Nsteps; ii++)
    {
        result += fptr(xi+ii*deltx)*deltx;
    }
    return result;
}
double TrapesoidIntegral(double xi, double xf,int Nsteps, double (*fptr)(double))
{
    double deltx = (xf-xi)/Nsteps;
    double result = 0;
    result += (fptr(xf)+fptr(xi))/2*deltx;
#pragma omp parallel for reduction(+:result)
    for(int ii=1; ii < Nsteps; ii++)
    {
        result += fptr(xi+ii*deltx)*deltx;
    }
    return result;
}
