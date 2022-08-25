#include <iostream>
#include <typeinfo>

template<class T>
class Point{
    private:
        T m_x;
        T m_y;
        T m_z;

    public:

        Point(T x=0,T y=0, T z=0 ) : m_x(x),m_y(y),m_z(z)
        {

        }
  
};

template<class T>
class typeSize{

    protected:

        T a;//Point<double> a 

    public:
        typeSize(T b = 0): a(b)
        {
            std::cout<<"\nI worked\n";
        }

        void size()
        {
            std::cout<<"\n"<<sizeof(a)<<"\n";
        }

};

template<class T>
class typeInfo: public typeSize<T>{

    private:    
        

    public: 

        typeInfo(T a=0): typeSize<T>(a)
        {
            std::cout<<"\nI worked too\n";
        }

        void info()
        {
            std::cout<<typeid(this->a).name()<<std::endl;
        }


};



int main()
{
    typeInfo<Point<char>> ti;
    typeSize<Point<double>> ts;
    //mojno vot tak 
    //typeSize<double> td;
    
    ti.size();
    ti.info();
    return 0;
}