#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

template<class T>
void printSomeElements(T * array,size_t size)
{
    for(int i = 0 ; i < size; i++)
    {
        std::cout<<array[i]<<"\t";
    }
    std::cout<<std::endl;

}


template<>//для инта
void printSomeElements<int> (int * array, size_t size)
{
    for(int i = 0 ; i < size ; i++)
    {
        if((array[i] % 2) ==0 )
            std::cout<<array[i]<<"\t" ;
    }
}



template<>//dlya chara 
void printSomeElements(char * str, size_t size)
{
    auto is_space = [](char a){return (a==' ');};
    std::cout<<std::count_if(str,str+size, is_space);
}



template <class T>
class TestContainer{
    private:
        T m_value[4];

    public:
        
        TestContainer()
        {
            for(auto & a : m_value)
            {
                a = 0;
            }
        }

        void printSize(){ //печатает размер m_value используя sizeof

            std::cout<< sizeof(m_value)<<std::endl;
        }

        void printArray(){ //печатает элементы массива через пробел

            for(auto & a: m_value)
            {
                std::cout<<a<<" ";
            }
        }

        

};

template <>
class TestContainer<std::string>
{
    private:

        std::string m_value;
        size_t m_size;
    
    public:

        TestContainer(): m_size(0){}

        void printSpaces()
        {
            std::cout<<std::count_if(m_value.begin(), m_value.end(),[](char a){return a == ' ';});
        }

        void printString()
        {
            std::cout<<m_value;
        }

        void setString(std::string str)
        {
            m_value = str;
            m_size+=str.size();
        }
    


};


int main()
{
    // int * IntArr = new int [5];
    // IntArr[0] = 1;
    // IntArr[1] = 2;
    // IntArr[2] = 3;
    // IntArr[3] = 4;
    // IntArr[4] = 5;

    // double * doubleArr = new double [5];
    // doubleArr[0]=1.0;
    // doubleArr[1]=2.0;
    // doubleArr[2]=3.0;
    // doubleArr[3]=4.0;
    // doubleArr[4]=5.0;
    
    // printSomeElements(IntArr,5);
    // printSomeElements(doubleArr,5);

    char txt[40];
    std::cin.getline(txt,40);// dsaks;adsa; dsald;saldd kdsadkn 
  //  std::cout<<txt<<"\t"<<strlen(txt);
    printSomeElements(txt,strlen(txt));


    TestContainer<int> ti;
    ti.printSize();
    std::cout<<std::endl;
    TestContainer<std::string> ts;
    ts.setString("das ds a dsd");
    ts.printSpaces();
    std::cout<<"\n";
    ts.printString();


}
