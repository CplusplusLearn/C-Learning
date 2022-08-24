#include <iostream>
#include <string>
#include <array>
#include <map>//multimap

const long MAX_VALUE = 123123123;

class testClass
{
    public:
        int m_a;
        double * m_arr;

        testClass(double * arr ,int a): m_arr(arr), m_a(a){
        }

};

int main()
{   
    double * arr = new double [5];
    arr[0] = 0;
    arr[1] = 0;
    arr[2] = 0;
    arr[3] = 0;
    arr[4] = 0;
    int a = 15;

    testClass t1(arr, a);
    testClass t2(t1);
    //copy cons 
    // copy assigment 
    //default cons 
    //destr
    //move cons
    //move assigment 
} 
