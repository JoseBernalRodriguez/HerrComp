#include<iostream>
#include<vector>

//we will create a function that applies some other function to the elements of our vector

void Modif( std::vector<int> & vec, int(*func)(int))
{
    for(auto & x : vec)
    {
        x= func(x);
    }
}

int main(void)
{
    std::vector<int> Veco={3,2,4,5};

    for(int x: Veco)
        std::cout << x << " ";
    std::cout << "\n";

    auto TwoTimes = [](int a){return 2*a;};

    Modif(Veco, TwoTimes);

    for(int x: Veco)
        std::cout << x << " ";
    std::cout << "\n";

    return 0;
}
