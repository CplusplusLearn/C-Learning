#include <iostream>


template <class T>
class Repository8
{
private:
    T m_array[8];
 
public:
    void set(int index, const T &value)
    {
        m_array[index] = value;
    }
 
    const T& get(int index)
    {
        return m_array[index];
    }
};


template <>
class Repository8<bool> // специализируем шаблон класса Repository8 для работы с типом bool
{
// Реализация класса
private:
    unsigned char m_data;
 
public:
    Repository8() : m_data(0)
    {
    }
 
    void set(int index, bool value)
    {
        // Выбираем оперируемый бит
        unsigned char mask = 1 << index;
 
        if (value) // если на входе у нас true, то бит нужно "включить"
            m_data |= mask; // используем побитовое ИЛИ, чтобы "включить" бит
        else // если на входе у нас false, то бит нужно "выключить" 
            m_data &= ~mask; // используем побитовое И, чтобы "выключить" бит
	}
	
    bool get(int index)
    {
        // Выбираем бит
        unsigned char mask = 1 << index;
        // Используем побитовое И для получения значения бита, а затем выполняется его неявное преобразование в тип bool
        return (m_data & mask) != 0;
    }

    void printSmth()
    {
        std::cout<<"\nsmhtalsdaspdsd\n";
    }
};
int main()
{
    // Объявляем целочисленный объект-массив
    Repository8<int> intRepository;
    

    for (int count=0; count<8; ++count)
        intRepository.set(count, count);
 
    for (int count=0; count<8; ++count)
        std::cout << intRepository.get(count) << '\n';
 
    // Объявляем объект-массив типа bool
    Repository8<bool> boolRepository;
    boolRepository.printSmth();
    // for (int count=0; count<8; ++count)
    //     boolRepository.set(count, count % 5);//4324324 - true , false - 0 
 
    // for (int count=0; count<8; ++count)
    //     std::cout << (boolRepository.get(count) ? "true" : "false") << '\n';
 
    return 0;
}

/*

template <>
class Repository8<bool> // специализируем шаблон класса Repository8 для работы с типом bool
{
// Реализация класса
private:
    unsigned char m_data;
 
public:
    Repository8() : m_data(0)
    {
    }
 
    void set(int index, bool value)
    {
        // Выбираем оперируемый бит
        unsigned char mask = 1 << index;
 
        if (value) // если на входе у нас true, то бит нужно "включить"
            m_data |= mask; // используем побитовое ИЛИ, чтобы "включить" бит
        else // если на входе у нас false, то бит нужно "выключить" 
            m_data &= ~mask; // используем побитовое И, чтобы "выключить" бит
	}
	
    bool get(int index)
    {
        // Выбираем бит
        unsigned char mask = 1 << index;
        // Используем побитовое И для получения значения бита, а затем выполняется его неявное преобразование в тип bool
        return (m_data & mask) != 0;
    }
};


*/