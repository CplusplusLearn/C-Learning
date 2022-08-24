#include <iostream> 


class Dollars{

    private:
        int m_count;

    public: 
        Dollars(int count): m_count(count)
        {
            
        }

        int get()
        {
            return m_count;
        }

        bool operator>(const Dollars & other);

        Dollars & operator+=(const Dollars & other)
        {
            this->m_count+=other.m_count;
            return *this;
        }

        Dollars & operator/=(int denumerator)
        {
            this->m_count /= denumerator;
            return *this;
        }
    
};

bool Dollars::operator>(const Dollars & other) 
{
            return m_count> other.m_count;
}


template<class T>
T& average(T * array, int size)
{
    T* sum = new T(0); 
    for(int i = 0 ; i < size ; i++)
        *sum+=array[i];
    *sum/=size;
    return *sum;
} 

int main()
{
    Dollars seven(7);
    Dollars tvelve(12);

    Dollars array[5] =
    {   
        Dollars{5},
        {3},
        {7132},
        {3213},
        {3123}
    
    };

    Dollars d1 = average(array, 5);
    std::cout<<d1.get(); 
}




