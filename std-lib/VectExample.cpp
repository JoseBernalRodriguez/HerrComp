#include<iostream>
#include<vector>


int main(void)
{
    std::vector<int> prueba={1,3,2};
    prueba.push_back(6);

    prueba.insert(prueba.begin()+2,6);
    for(auto x : prueba)
    {
        std::cout << x << "\n";
    }


    return 0;
}
