#include<iostream>
#include<cmath>
typedef float Real;
int main(int argc, char** argv)
{
    Real c=1.0/10;
    std::cout.precision(7);
    std::cout.setf(std::ios::scientific);
    int n=std::atoi(argv[1]);
    Real x1=0,x2=0,x3=0,x4=0;
    for(int ii=1; ii<=n;ii++)
    {
        x1=(-1+std::sqrt(1-4*c))/2;
        x2=(-1-std::sqrt(1-4*c))/2;
        x3=-2*c/(1+std::sqrt(1-4*c));
        x4=-2*c/(1-std::sqrt(1-4*c));
        std::cout  << n <<"\t" << x1 << "\t" << x2 << "\t"<< x3 <<"\t"<< x4 << "\n";
        c=c/10.0;
    }
}
