#include <iostream> 
#include <cstring>



template <class T, int size> // size является non-type параметром шаблона
class StaticArray
{
private:
    // Параметр size отвечает за длину массива
    T m_array[size];
 
public:
    T* getArray() { return m_array; }
	
    T& operator[](int index)
    {
        return m_array[index];
    }
};


template <typename T, int size>
void print(StaticArray<T, size> &array)
{
    for (int count=0; count < size; ++count)
        std::cout << array[count] << ' ';
}


//     int main()
// {
// 	// Объявляем целочисленный массив
// 	StaticArray<int, 5> int5;
// 	int5[0] = 0;
// 	int5[1] = 1;
// 	int5[2] = 2;
// 	int5[3] = 3;
// 	int5[4] = 4;
 
// 	// Выводим элементы массива
// 	print(int5);
 
// 	return 0;
// }





template <>
void print(StaticArray<char, 14> &array)
{
	for (int count = 0; count < 14; ++count)
		std::cout << array[count];
}





    int main()
    {
        // Объявляем массив типа char
        StaticArray<char, 14> char14;
    
        strcpy_s(char14.getArray(), 14, "Hello, world!");
    
        // Выводим элементы массива
        print(char14);
    
        return 0;
    }




/* about specialization  approach #1



*/


/* aproach 1 problem

int main()
{
    // Объявляем массив типа char
    StaticArray<char, 12> char12;
 
    strcpy_s(char12.getArray(), 12, "Hello, dad!");
 
    // Выводим элементы массива
    print(char12);
 
    return 0;
}

*/