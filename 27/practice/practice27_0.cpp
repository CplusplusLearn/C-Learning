#include <iostream>
#include <iomanip> 

template <class T>
class Repository
{
private:
    T m_value;
public:


   Repository()
   {
    m_value = 0;
   }

    Repository(T value)
    {
         m_value = value;
    }
 
    ~Repository()
    {
    }
 
    void print()
    {
        std::cout << m_value << '\n';
    }
};

template <>
void Repository<float>::print()
{
    std::cout << std::scientific << m_value << '\n';
}



int main()
{
  //  Инициализируем объекты класса
    Repository<int> nValue(7);
    Repository<float> dValue(84.4);
 
    // Выводим значения объектов класса
    nValue.print();
    dValue.print();

}












/*
template <>
void Repository<double>::print()
{
    std::cout << std::scientific << m_value << '\n';
}

*/
