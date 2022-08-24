#include <iostream>
 

//second task
template<class T>
class Auto_ptr1
{
	T* m_ptr;
public:
	// Получаем указатель для "владения" через конструктор
	Auto_ptr1(T* ptr=nullptr);
	
	// Деструктор позаботится об удалении указателя
	~Auto_ptr1();

 
	// Выполняем перегрузку оператора разыменования и оператора ->, чтобы иметь возможность использовать Auto_ptr1 как m_ptr
	T& operator*() const ;
	T* operator->() const ;
};

class Item
{
public:
    Item() { std::cout << "Item acquired\n"; }
    ~Item() { std::cout << "Item destroyed\n"; }
};
 
int main()
{
	Auto_ptr1<Item> item(new Item); // динамическое выделение памяти
    return 0;
    //реализация должно быть выполнена таким образом, чтобы здесь не было необходимости писать delete
    //не смотря на то, что память выделена динамически, подумайте как это можно сделать

}