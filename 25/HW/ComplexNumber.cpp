 #include <iostream>
 //first task 


 template<class T>
 class ComplexNumber{
    private:
        T m_real;
        T m_im;
    public:
        ComplexNumber(T real);
        ComplexNumber(const ComplexNumber & other);
        ComplexNumber(ComplexNumber && other); //необходимо изучить, что такое
        //оператор перемещения 

        ComplexNumber& operator/(const Complex & other);
        ComplexNumber& operator*(const Complex & other);
        ComplexNumber& operator+(const Complex & other);
        ComplexNumber& operator-(const Complex & other);
        ComplexNumber& pow1(int degree);//возведение в степень, учтите, что она может быть отрицательной
        uint64_t abs1() const;//норма комплексного числа

        ~ComplexNumber();

 };