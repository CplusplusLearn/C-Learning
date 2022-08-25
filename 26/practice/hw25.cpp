#include <iostream> 
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <numeric>
#include <cstring>
#include <typeinfo>


//24.1 function with "const"
template<class T1, class T2>
T2* searchThreeMax(const T1* array, int size)
{
    T2* newArray = new T2[3];
    if (array == nullptr)
        return newArray;// 0 0 0 

    std::vector<T1> tmpData(size);
    T1* ptr = tmpData.data();//
    std::copy(array, array + size, ptr);
    std::sort(tmpData.begin(), tmpData.end());
    std::reverse(tmpData.begin(),tmpData.end());

    size = size > 3 ? 3 : size;//size = 2
    for (int i = 0; i < size; i++)
    {
        newArray[i] = tmpData[i];
    }
    return newArray;
}
/*

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
*/


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




class ArrayWrapper {
private:
    double* m_array;
    uint64_t m_size;//unsigned int size_t 
    std::string m_name;

public:
    //ArrayWrapper aw1;
    //ArrayWrapper array[14];

    ArrayWrapper(double* array = nullptr, uint64_t size = 0, std::string name = "No name") :m_array(array),
        m_size(size), m_name(name) {
       // std::cout << "\nConstructor by default executed\n";

    }
    ArrayWrapper(const ArrayWrapper& copyElement) : m_size(copyElement.m_size), m_name(copyElement.m_name)
    {
        m_array = new double[m_size];
        // if(copyElement.m_array != nullptr) is it nessecary???
        for (int i = 0; i < m_size; i++)
        {
            m_array[i] = copyElement.m_array[i];
        }
        //std::cout << "\nCopy constructor executed\n";
    }

    ArrayWrapper(uint64_t size, const std::string& name) :m_size(size), m_name(name)
    {
        m_array = new double[size];
        std::cout << "\nEnter " << size << " values:";
        for (int i = 0; i < size; i++)
        {
            std::cout << ">";
            std::cin >> m_array[i];
        }
        //std::cout << "\nConsole costructor executed\n";
    }

    ArrayWrapper(double value) :m_size(1), m_name("No name")
    {
        m_array = new double[1];
        m_array[0] = value;
    }// ArrayWrapper aw = 0.5;

    ArrayWrapper(ArrayWrapper&& moveElement)//move constructor 
    {
        m_name = moveElement.m_name;
        moveElement.m_name = "name is moved";
        m_size = moveElement.m_size;
        moveElement.m_size = 0;
        m_array = moveElement.m_array;//
        moveElement.m_array = nullptr;
       // std::cout << "\nMove constructor executed\n";
    }

    uint64_t getSize() const
    {
        return m_size;
    }

    std::string getName() const 
    {
        return m_name;
    }

    double* getArr() const {
        return m_array;
    }

    double mean() const
    {
        return std::accumulate(m_array, m_array + m_size, 0.0) / m_size;
    }

    operator double() 
    {
        return mean();
    }

    bool operator>(const ArrayWrapper& right)
    {
        return this->mean() > right.mean();
    }

    bool operator<(const ArrayWrapper& right)
    {
        return mean() < right.mean();
    }


   // ArrayWrapper aw1{..};
   // ArrayWrapper aw2 = aw1;
   // aw1 = aw2
    ArrayWrapper& operator=(const ArrayWrapper& other)//copy assigment 
    {
        if (this == &other)
        {
            return *this;
        }

        delete[] m_array;
        m_size = other.m_size;
        m_name = other.m_name;
        m_array = new double[m_size];
        for (int i = 0; i < m_size; i++)
        {
            m_array[i] = other.m_array[i];
        }

        return *this;


    }

    ArrayWrapper& operator=(ArrayWrapper&& other) //
    {
        m_name = other.m_name;
        m_array = other.m_array;
        m_size = other.m_size;
        other.m_name = "No name";
        other.m_size = 0;
        other.m_array = nullptr;
        //std::cout << "\nMove constructor executed\n";
        return *this;
    }

    ~ArrayWrapper()
    {
        delete[] m_array;
       // std::cout << "\nDestructor executed\n";
    }

    friend std::ostream& operator<<(std::ostream& ost, const ArrayWrapper& element);

};

std::ostream& operator<<(std::ostream& ost, const ArrayWrapper& element)
{
    uint64_t size = element.getSize();
    ost << "\nArray name : " << size;
    ost << "\nArray size : " << element.getName();
    double* ArrPtr = element.getArr();
    ost << "\nArray velues: ";
    for (int i = 0; i < size; i++)
    {
        ost << ArrPtr[i] << "\t";
    }
    return ost;

}

int main()
{
     /*
    //First task testing
//     //Char -> int 
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
     */
    
    

    //Здесь необходимо вводить из консоли значение 
    
    ArrayWrapper* wrappers = new ArrayWrapper[5];
    wrappers[0] = ArrayWrapper{ 5,"wpar0" };
    wrappers[1] = ArrayWrapper{ 4,"wrap1" };
    wrappers[2] = ArrayWrapper{ 3,"wrap2" };
    wrappers[3] = ArrayWrapper{ 3,"wrap3" };
    wrappers[4] = ArrayWrapper{ 2,"wrap4" };

    ArrayWrapper * newWrapps = searchThreeMax<ArrayWrapper,ArrayWrapper>(wrappers,5);
    for(int i = 0 ; i < 3 ; i++)
        std::cout<<newWrapps[i]<<"\n";


    double * newWrappsDouble = searchThreeMax<ArrayWrapper,double>(wrappers,5);
    for(int i = 0 ; i < 3 ; i++)
        std::cout<<newWrappsDouble[i]<<"\n";
    
}

