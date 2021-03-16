#include<iostream>
#include<cmath>
float sup(int N);
float sdown(int N);
int main(int argc, char**argv)
{
    std::cout.precision(7);std::cout.setf(std::ios::scientific);
    int N=std::atoi(argv[1]);
    for(int ii=1; ii <= N ; ii++)
    {
        float up=sup(ii),down=sdown(ii);
        std::cout << ii << "\t" << up << "\t" << down << "\t"<< std::fabs(up-down)/up<< "\n";
    }

}
float sup(int N)
{
    float sum=0.0;
    for(int ii=N; ii>=1; ii--)
    {
         sum+=1.0/ii;
    }
    return sum;
}
float sdown(int N)
{
    float sum=0.0;
    for(int ii=1; ii <=N; ii++)
    {
        sum+=1.0/ii;

    }
    return sum;
}
