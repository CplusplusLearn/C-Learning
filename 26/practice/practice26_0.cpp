#include <iostream>
#include <array>
using namespace std;

int main()
{
    array<int,10> arr{0};  

    for(auto & a : arr)
    {
        std::cout<<a<<"\t";
    }

}