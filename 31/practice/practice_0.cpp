#include <queue>
#include <iostream>
#include <deque> 
#include <list> 
#define push_back pb
#define f(a,b) a+b
#define long long ll 


void printQueue( std::priority_queue<int,std::deque<int> >  pq)
{
    while(!pq.empty())
    {
        std::cout<<pq.top()<<"\t";
        pq.pop();
    }
    std::cout<<"\n";
}


class Person
{  
private:

    double m_height;
    std::string m_name;

public:

    Person(double height=150.0, std::string name=""):m_height(height),m_name(name){}

    Person(const Person & other):m_height(other.m_height), m_name(other.m_name){}

    friend std::ostream & operator<<(std::ostream & os, const Person & pr);
    friend bool operator<(const Person & pr1 , const Person & pr2);
};

bool operator<(const Person & pr1 , const Person & pr2)
{
    return pr1.m_height < pr2.m_height;

}


std::ostream & operator<<(std::ostream & os, const Person & pr)
{
    os<<"Person name: "<<pr.m_name<<"\nHis height: "<<pr.m_height<<"\n";
    return os;
}










int main()
{
    std::priority_queue<int,std::deque<int> > pqi;
    pqi.push(5);
    pqi.push(12);
    pqi.push(3);
    pqi.push(76);
    pqi.push(9);
    pqi.push(4);
    pqi.push(43);
}










// int main ()
// {
//     Person p1(98.6,"Jhon");
//     Person p2(137,"Mike");
//     Person p3(173.2,"Michael");
//     Person p4(165.6,"Elisabeth");
//     Person p5(212.9,"Ann");
//     Person p6(199.0,"Luke");


//     std::priority_queue<Person, std::vector<Person>> pqp;
//     pqp.push(p1);
//     pqp.push(p2);
//     pqp.push(p3);
//     pqp.push(p4);
//     pqp.push(p5);
//     pqp.push(p6);


//     while(!pqp.empty())
//     {
//         std::cout<<pqp.top();
//         pqp.pop();
//     }



// }