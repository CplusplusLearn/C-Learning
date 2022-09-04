#include <iostream>
#include <cassert> 
#include <typeinfo>
#include <cmath>
#include <algorithm>
#include <numeric> 

template<class T>
class ComplexNumber {
private:
    T m_real;
    T m_im;
public:
   
   //ComplexNumber(){}

    ComplexNumber(T real=0) :m_real(real), m_im(0) // ComplexNumber c1; c1.m_real == 0 , c1.m_im ==0;
    {
       

      //  std::cout << "\nConstructor executed\n";
    }
    ComplexNumber(T real, T image) :m_real(real), m_im(image)
    {
     //   std::cout << "\nConstructor executed\n";
    }
    ComplexNumber(const ComplexNumber& other) :m_real(other.m_real), m_im(other.m_im)
    {

        /* code */
       // std::cout << "\nCopy constructor executed\n";
    }
    ComplexNumber(ComplexNumber&& other)
    {
        m_real = other.m_real;
        other.m_real = 0;
        m_im = other.m_im;
        other.m_im = 0;
     //   std::cout << "\nmove constructor executed\n";
    } //необходимо изучить, что такое
    //оператор перемещения 

    ComplexNumber operator/(const ComplexNumber& other) const
    {
        T dividor = std::pow(other.m_real, 2) + std::pow(other.m_im, 2);
        T tmpReal = (m_real * other.m_real + m_im * other.m_im) / dividor;
        T tmpIm = (m_im * other.m_real - m_real * other.m_im) / dividor;
        ComplexNumber cTmp(tmpReal,tmpIm);

        return cTmp;
    }

	ComplexNumber operator*(const ComplexNumber& other) const
	{
		T tmpReal = m_real * other.m_real - m_im * other.m_im;
		T tmpIm = m_im * other.m_real + m_real * other.m_im;
	
		return ComplexNumber(tmpReal,tmpIm);
	}

	ComplexNumber operator+(const ComplexNumber& other) const
	{
		T tmpReal = m_real + other.m_real;
		T tmpIm = m_im + other.m_im;
		return ComplexNumber(tmpReal,tmpIm);
	}
	ComplexNumber operator-(const ComplexNumber& other) const
	{
		T tmpReal = m_real - other.m_real;
		T tmpIm = m_im - other.m_im;
		return ComplexNumber(tmpReal,tmpIm)
;
	}
	double abs1() const//норма комплексного числа
	{
		return std::sqrt(std::pow(m_real, 2) + std::pow(m_im, 2));

	}
	ComplexNumber pow1(int degree) const//возведение в степень, учтите, что она может быть отрицательной
	{
		double alpha = std::atan(((double)m_im) / m_real);
		double absValue = abs1();
		absValue = std::pow(absValue, degree);
		T tmpReal = std::cos(degree * alpha);
		T tmpIm = std::sin(degree * alpha);

		return ComplexNumber(tmpReal,tmpIm);
	}

    ComplexNumber& operator=(const ComplexNumber& other)//copy assigment
    {   
        m_real = other.m_real;
        m_im = other.m_im;
        return *this;

    }
   

	friend std::ostream& operator<<(std::ostream& ost, const ComplexNumber& other)
	{
		
		if (other.m_real || (other.m_real ==0 && other.m_im ==0))
		{
			std::cout << other.m_real;

		}

		if (other.m_im)
		{
			ost << (other.m_im > 0 ? "+" : "");
			ost << other.m_im << "*i";
		}
		return ost;
		
	}

    ~ComplexNumber() {
       // std::cout<<"\nDestructor is executed\n";
    }

};

template<class T, size_t N,size_t M>
class Array2d{
    private: 
         T array2d[N][M];
         
    public: 
        

        //конструктор в принципе не нужен, со своей задачей неплохо справляется
        //дефолтный конструктор, однако есть необходимость в тмо, чтобы после 
        //создания объекта наш массив был заполнен нулями =>

        Array2d()
        {
            for(int i = 0;i < N; i++)
            {
                for(int j = 0; j < M; j++ )
                {
                    array2d[i][j] = 0 ;
                }
            }
        }

        Array2d(const Array2d & other)
        {
            for(int i = 0 ; i < N ; i++)
            {
                for(int j = 0 ; j < M ; ++j)
                    array2d[i][j] = other.array2d[i][j];
            }

        }

        
        T* operator[](size_t i)
        {
            return array2d[i];
        }

        Array2d operator+(Array2d & other)
        {
            
            Array2d tmp;
            for(int i = 0; i < N ; i++)
            {
             for(int j = 0 ; j < M; j++){
                tmp[i][j] = array2d[i][j] + other[i][j];
                }
            }
            return tmp;
        }

        Array2d operator-(Array2d & other)
        {
            
            Array2d tmp;
            for(int i = 0; i < N ; i++)
            {
             for(int j = 0 ; j < M; j++){
                tmp[i][j] = array2d[i][j] - other[i][j];
                }
            }
            return tmp;
        }
        Array2d & operator=(const Array2d & other)
        {
            for(int i = 0 ; i < N;i++)
            {
                for(int j = 0 ; j < M ; j++)
                {
                    array2d[i][j] = other.array2d[i][j];
                }
            }
            return *this;

        } 
        double average()
        {
          T sum = 0;    
        //     sum = std::accumulate(array2d,array2d+N+M,0);
        //     double size = N+M;
        //     return sum/size;
          for(int i = 0; i < N;i++)
          {
              for(int j = 0; j < M;j++)
                sum+=array2d[i][j];

          }
          double size = N+M;
          return sum/size;
        }

        const T* getRow(size_t number)
        {
            return array2d[number];
        }

      
        friend std::ostream& operator<<(std::ostream& ost, const Array2d<T,N,M> & arr);
        
        


};

template<class T, size_t N, size_t M>
std::ostream& operator<<(std::ostream& ost,Array2d<T,N,M> & arr)
{
    const T* tmpRow;
    for(int i = 0 ; i < N ; i++)
    {
        for(int j = 0 ; j < M ; j++)
        {
            tmpRow = arr.getRow(i);
            ost<<tmpRow[j]<<" ";
        }
        ost<<"\n";
    } 
    return ost;
}

template<class T> 
class TypeInfo{
    protected: 
        T value;
    public:
        TypeInfo(T other)
        {
            value = other;

        }

        void getInfo()
        {
            std::cout<< sizeof(value)<<"\n";
        }

};

template<class T> 
class TypeHash: public TypeInfo<T>{

    private:
    public:

        TypeHash(T other): TypeInfo<T>(other)
        {

        }
        void getHash()
        {
            std::cout<<typeid(this->value).hash_code()<<"\n";
        }
};


int main()
{
    Array2d<ComplexNumber<int>,5,6> dArray;


//    // dArray[0][1] = ComplexNumber(14,56);
//     Array2d<int,5,6> dArray1;
//     dArray1[0][1] = 1432;
//     dArray1[0][2] = 1433;
//    //  std::cout<<dArray;
//     std::cout<<dArray1.average();
   //  std::cout<<dArray.average();///нужна спецификация
   //TypeInfo<Array2d<ComplexNumber<int>,5,6>> TA(dArray);
    TypeHash<   Array2d<ComplexNumber<int>,5,6>  > TH(dArray);
    TH.getInfo();

    TH.getHash();

   

  // Array2d<int,5,6> dArray2 =  dArray1 + dArray; 
 //   std::cout<<dArray2;
}
   // std::cout<<typeid(dArray).hash_code();

