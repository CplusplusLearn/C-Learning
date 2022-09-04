#include <iostream>
#include <cassert>
//second task

template<class T>
class Auto_ptr1
{

	T* m_ptr;
public:
	// Получаем указатель для "владения" через конструктор
	Auto_ptr1(T* ptr=nullptr):m_ptr(ptr){}
	
	// Деструктор позаботится об удалении указателя
	~Auto_ptr1()
    {
        delete m_ptr;
    }

 
	// Выполняем перегрузку оператора разыменования и оператора ->, чтобы иметь возможность использовать Auto_ptr1 как m_ptr
	T& operator*() const 
    {
        return *m_ptr;
    }
    
	T* operator->() const 
    {
        return m_ptr;
    }
};

class Item
{
public:
    int m_value;

    Item(int value=0):m_value(value) { std::cout << "\nItem acquired\n"; }

    ~Item() { std::cout << "\nItem destroyed\n"; }
};
 
int main()
{
    /*
    
    int a = 6;
    int * ptr = & a;  
    *(ptr)=12;

    */ 


	Auto_ptr1<Item> ptrToItem(new Item); // динамическое выделение памяти
    std::cout<<(ptrToItem->m_value)<<std::endl;
    (*ptrToItem).m_value = 1221321312;
    std::cout<<(ptrToItem->m_value)<<std::endl;


} 
