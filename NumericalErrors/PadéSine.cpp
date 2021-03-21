#include<iostream>
#include<cmath>

typedef double Real;

Real Seno(Real x);

int main(int argc, char** argv)
{
    std::cout.precision(8);std::cout.setf(std::ios::scientific);
    double N=std::atof(argv[1]);
    for(int ii=1; ii <= N ; ii++)
    {
        std::cout << ii*4*M_PI/N << "\t" << Seno(ii*4*M_PI/N) - std::sin(ii*4*M_PI/N)<< "\n";
    }

}


Real Seno(Real x)
{
    int N= std::floor(x/(2*M_PI));
    Real x1= x - N*2*M_PI;
    Real z=0; //z is our value betwen -pi/2 and pi/2 for the evaluation
    if(0<=x1 && x1<=M_PI/2)
    {
        z=x1;
    }
    if(M_PI/2<=x1 && x1<=M_PI)
    {
        z=M_PI-x1;
    }
    if(M_PI<=x1 && x1<=3*M_PI/2)
    {
        z=M_PI-x1;
    }
    if(3*M_PI/2<=x1 && x1<=2*M_PI)
    {
        z=x1-2*M_PI;
    }


    if(std::fabs(z)<1.0e-08)
    {return z;}
    if(std::fabs(z)>M_PI/6)
    {
        z=Seno(z/3);
        return (3-4*z*z)*z;
    }
    Real z2=z*z;
    return z*(1-29593*z2/207636+34911/7.613320e06*z2*z2-4.79249e05*z2*z2*z2/1.1511339840e10)/(1+1.671e03*z2/6.9212e04+97*z2*z2/3.51384e05+2.623e03*z2*z2*z2/1.644477120e09);

}
