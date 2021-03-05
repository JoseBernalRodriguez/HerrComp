#include<iostream>

int main(int argc, char **argv)
{
    float under=1.0;
    float over=1.0;
    int N=std::atoi(argv[1]);
    for(int ii=1; ii<=N ; ii++)
    {
        over=over*2.0;
        under=under/2.0;
        std::cout << over << "\t" << under << "\t"<< ii << "\n";
    }




    return 0;
}
