#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>

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
        int * arr;
    public: 
    Item();
    Item(size_t size);//необходимо выделить сюда массив размера size и заполнить его рандомными числами до 100
    //как делать --- см rand() 
    friend std::ostream & operator<<(std::ostream& out, const Item & it );
    double average();//не забываем о приведении типов.
    ~Item();
};

template<size_t N>
class Container<std::vector<Item>, N > 
{
    private:
        std::vector<int> m_vec;
    public:
        Container();
        void print();

};


template<size_t N> 
class Container<std::list<std::string>, N> 
{
    private: 
        std::list<std::string> listOfStr;
    public:
        Container();
        void print();

};
