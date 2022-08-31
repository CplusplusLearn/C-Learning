#include <iostream>
#include <cmath>
//first task 


template<class T>
class ComplexNumber {
private:
	T m_real;
    T m_im;
public:
    

    ComplexNumber(T real) :m_real(real), m_im(0)
    {
      //  std::cout << "\nConstructor executed\n";
    }
    ComplexNumber(T real, T image) :m_real(real), m_im(image)
    {
     //   std::cout << "\nConstructor executed\n";
    }
    ComplexNumber(const ComplexNumber& other) :m_real(other.m_real), m_im(other.m_im)
    {
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
        return ComplexNumber(tmpReal,tmpIm)
;
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

		return ComplexNumber(tmpReal,tmpIm)
;
	}
   

	friend std::ostream& operator<<(std::ostream& ost, const ComplexNumber& other)
	{
		
		if (other.m_real)
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


int main()
{
    ComplexNumber<double> c1(3, 14);
    ComplexNumber<double>c2(5, 12);
    ComplexNumber<double> c3 = c1.pow1(5);
	//ComplexNumber<double> c3 = c1 + c2;
	//ComplexNumber<double> c3 = c1 - c2;
	//ComplexNumber<double> c3 = c1 * c2;
	//ComplexNumber<double> c3 = c1 / c2;


	ComplexNumber<double> c4(std::move(c3));
	std::cout << c4 << std::endl;
	
	std::cout << c3;
 //   delete &c3;

}

