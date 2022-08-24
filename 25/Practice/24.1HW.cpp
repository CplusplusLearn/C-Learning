#include <iostream> 
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <numeric>
#include <cstring>
#include <typeinfo>


//24.1 function with "const"
// template<class T1, class T2>
// T2* searchThreeMax(const T1* array, int size)
// {
//     T2* newArray = new T2[3]{ 0 };
//     if (array == nullptr)
//         return newArray;// 0 0 0 

//     std::vector<T1> tmpData(size);
//     T1* ptr = tmpData.data();//
//     std::copy(array, array + size, ptr);
//     std::sort(tmpData.begin(), tmpData.end(), std::greater<T1>());
//     //std::reverse(tmpData.begin(),tmpData.end());

//     size = size > 3 ? 3 : size;//size = 2
//     for (int i = 0; i < size; i++)
//     {
//         newArray[i] = tmpData[i];
//     }
//     return newArray;
// }



template<class T1,class T2>
T2 * searchThreeMax(T1 * array,int size)
{
    T2 * nArray = new T2[3]{0};
    if(array == nullptr)
    {
        return nArray;
    }
    std::sort(array, array+ size,std::greater<T1>());
    size = size>3? 3: size;
    for(int i = 0 ; i < size ; i++)
    {
        nArray[i]=array[i];
    }
    return nArray;
}



template<class T1, class T2>
void printAndDelete(const T1* input, size_t size, const T2* output)
{
    std::cout << "\nTesting <" << typeid(input[0]).name() << " -> " <<
        typeid(output[0]).name() << ">" << '\n';
    std::cout << "input: ";
    for (int i = 0; i < size; i++)
    {
        std::cout << input[i] << "\t";
    }
    std::cout << "\noutput: ";
    for (int i = 0; i < 3; i++)
    {
        std::cout << output[i] << '\t';
    }
    std::cout << "\n";
    delete[] output;
}


int main()
{

    //First task testing
    //Char -> int 
    char * inputChar = new char[6];
    inputChar[5] = '\0';
    inputChar[0] = 'a';inputChar[1] = 'j';inputChar[2]='l';inputChar[3]='y';inputChar[4]='w';  
    int * outputInt = searchThreeMax<char,int>(inputChar,5);
    printAndDelete(inputChar,5,outputInt);

   // Char -> char 
    char * outputChar = searchThreeMax<char,char>(inputChar,5);
    printAndDelete<char,char>(inputChar,5,outputChar);
    delete [] inputChar;


   // int -> int 
    int siArr[2] = {12,76};  
    int * outIntArray = searchThreeMax<int,int>(siArr,2);
    printAndDelete<int,int>(siArr,2,outIntArray);

    //double -> double 
    double inputDouble[5] = {145.32,4231.53,3321.444,31.3,721.4};
    double * outputDouble = searchThreeMax<double,double>(inputDouble,5);
    printAndDelete<double,double>(inputDouble,5,outputDouble);


   // double -> int 

    outputInt=searchThreeMax<double,int>(inputDouble,5);
    printAndDelete(inputDouble,5,outputInt);

 //end of first task testing
}