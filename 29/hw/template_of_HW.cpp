#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <numeric>


//Тесты обязательны!




template<class T, size_t N>
class Container{
    private:
        T m_array[N];
    public:

        Container(){
            for(int i = 0 ; i < N ; i ++)
            {
                m_array[i] = (T)0;
            }
        }

        void print(){
            
            for(const auto & a: m_array)
            {
                std::cout<<a<<"\t";
            }
            std::cout<<"\n";
        }

        void fill(const T array[N])
        {
            std::copy(array,array + N , m_array);
        }


};




class Item
{
    private:
        int * m_arr;
        size_t m_size;
    public: 
    Item();
    Item(size_t size);//необходимо выделить сюда массив размера size и заполнить его рандомными числами до 100
    //как делать --- см rand() 

    friend std::ostream & operator<<(std::ostream& out, const Item & it );
    double average() const;//не забываем о приведении типов.
   
    ~Item();

   
};

template<size_t N>
class Container<std::vector<Item>, N > 
{
    private:
        std::vector<Item> m_vec;
    public:
        Container();
        void add(const Item & it);//должна быть проверка, что  
        //кол-вао элементов <= N 
        
        void print(); // для всех обьектов, которые содержатся в контейнере 
        // m_vec необходимо вывести среднее арифметическое
};


template<size_t N> 
class Container<std::list<std::string>, N> 
{
    private: 
        std::list<std::string> listOfStr;
    public:
        Container();//здесь ничего резервировать не надо
        void add(const std::string & str); // не забываем проверку
        
        void print();//для каждой строки, которая содержится в контейнере list 
        //необходимо вывести в консоль количество запятых в строке
   
};