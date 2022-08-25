#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>

int square(const int & a){
    return a*a;
}


int main()
{


    int b = 15;
    auto func = [](int a ){ return a*a; };//лямбда функция
    std::cout<<func(5);
    
    
    std::function<int(int)> func_2 = [](int a)->decltype(a){return a*a*a*a;};
    std::cout<<"\n"<<func_2(5);
    
    
    std::function<int(const int & )> func_3 = &square;
    std::cout<<"\n"<<func_3(3);

}
//google :
// std::function c++ 
// lyambda functions c++ 
// pointers to functions c++ 