#include<iostream>
#include<omp.h>
#include<vector>
#include<random>
void fill_random_vector(std::vector<double> & v);
#define INITIALIZATIONI 5555555
double average(const std::vector<double> & aja);
double mimin(double old, double nw)
{
    if(old <= nw)
    {
        return old;
    }
    if(old > nw)
    {
        return nw;
    }
}
int main()
{
    std::vector<double> a(1000001);
    std::iota(a.begin(),a.end(),-500000+8);
    double result1= INITIALIZATIONI;
    double result2=0;
    double avg=average(a);

#pragma omp declare reduction                   \
    (JDmin:double:omp_out=mimin(omp_out,omp_in))   \
    initializer(omp_priv=INITIALIZATIONI)


 #pragma omp parallel for reduction(JDmin:result1)
    for(int ii=0; ii < a.size();ii++)
    {
        result1 = mimin(result1,a[ii]);
    }

#pragma omp parallel for reduction(+:result2)
    for(auto x:a)
    {
        result2+=x;
    }

    std::cout << result1 << "\t" << result2 << "\t" << avg << "\n";
    return 0;
}

void fill_random_vector(std::vector<double> & v)		//This vector is used to fill the arrays used in direct/blocking multiplication and transposition
{
    std::mt19937 gen(1);
    std::uniform_real_distribution<> dist(-1.0,1.0);
    for(auto & x: v)
    {
        x=dist(gen);
    }
}
double average(const std::vector<double> & aja)
{
    double result=0;
    int size = aja.size();
#pragma omp parallel
    {
        double localsum=0;
#pragma omp for
        for(int ii=0; ii < size; ++ii){
            localsum +=aja[ii]/size;
        }
#pragma omp atomic
        result += localsum;
    }
    return result;
}
