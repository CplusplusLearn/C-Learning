#include <iostream>
#include <iomanip> 

template <class T>
class Repository
{
private:
    T m_value;
public:
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
Repository<char*>::Repository(char* value)
{
    // Определяем длину value
    int length=0;
    while (value[length] != '\0')
        ++length;

    ++length; // +1, учитывая нуль-терминатор
 
    // Выделяем память для хранения значения value
    m_value = new char[length];
 
    // Копируем фактическое значение value в m_value
    for (int count=0; count < length; ++count)
        m_value[count] = value[count];
}

template <>
Repository<char*>::~Repository()
{
    delete[] m_value;
}

int main()
{
    // Динамически выделяем временную строку
    char * string = new char[40];
 
    // Просим пользователя ввести свое имя
    std::cout << "Enter your name: ";
    std::cin >> string;
 
    // Сохраняем то, что ввел пользователь
    Repository<char*> repository(string);

    // Удаляем временную строку
    delete[] string;
 
    repository.print(); // получаем мусор
    
    // Пытаемся вывести то, что ввел пользователь

}













/*

template <>
Repository<char*>::Repository(char* value)
{
    // Определяем длину value
    int length=0;
    while (value[length] != '\0')
        ++length;
    ++length; // +1, учитывая нуль-терминатор
 
    // Выделяем память для хранения значения value
    m_value = new char[length];
 
    // Копируем фактическое значение value в m_value
    for (int count=0; count < length; ++count)
        m_value[count] = value[count];
}
















*/