#include<iostream>

int main(void)
{
    float r=0.1;
    std::cout.setf(std::ios::scientific);
    std::cout.precision(7);
    for(int ii=1; ii<10; ii++)
    {
        r+=0.1;
    }
    float t=0.1+0.1+0.1+0.1+0.1+0.1+0.1+0.1+0.1+0.1;
    std::cout << r << "\n"<< t <<"\n";

    return 0;
}
