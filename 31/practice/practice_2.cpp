#include <iostream>
#include <unordered_map>
#include <unordered_set>

class Person
{  
private:

    double m_height;
    std::string m_name;

public:

    Person(double height=150.0, std::string name=""):m_height(height),m_name(name){}

    Person(const Person & other):m_height(other.m_height), m_name(other.m_name){}
    double getHeight() const { return m_height;}
    std::string getName() const {return m_name;}
    friend std::ostream & operator<<(std::ostream & os, const Person & pr);
    friend bool operator<(const Person & pr1 , const Person & pr2);
    friend bool operator==(const Person & pr1 , const Person & pr2);
     
};

bool operator<(const Person & pr1 , const Person & pr2)
{
    return pr1.m_height < pr2.m_height;

}
bool operator==(const Person & pr1 , const Person & pr2)
{
    return pr1.m_height == pr2.m_height;

}


std::ostream & operator<<(std::ostream & os, const Person & pr)
{
    os<<"Person name: "<<pr.m_name<<"\nHis height: "<<pr.m_height<<"\n";
    return os;
}



//update 18:09:2022 --- > with this Hash function it will work
namespace std{
    //implement hash function so we can put Person into an unordered_set*/
    template <> struct hash<Person> {
        typedef Person argument_type;
        typedef std::size_t result_type;
        std::size_t operator() (const Person& id) const noexcept {
            return std::hash<double>()(id.getHeight()*((int)id.getName()[0]));
        }
    };
}

// int main()
// {
//     std::unordered_map<int, Person> mip ;

//     Person p1(98.6,"Jhon");
//     Person p2(137,"Mike");
//     Person p3(173.2,"Michael");
//     Person p4(165.6,"Elisabeth");
//     Person p5(212.9,"Ann");
//     Person p6(199.0,"Luke");

//     mip.insert(std::make_pair(26,p1));
//     mip.insert(std::make_pair(28,p2));
//     mip.insert(std::make_pair(59,p6));
//     mip.insert(std::make_pair(23,p3));
//     mip.insert(std::make_pair(35,p4));
//     mip.insert(std::make_pair(35,p5));


//     // for(auto & [a,b]:mip)
//     // {
//     //     std::cout<<b<<a<<"\n";
//     // }

//     // std::cout<<mip[36];


// }






int main()
{
    std::unordered_set<Person> sp ;

    Person p1(98.6,"Jhon");
    Person p2(137,"Mike");
    Person p3(173.2,"Michael");
    Person p4(165.6,"Elisabeth");
    Person p5(212.9,"Ann");
    Person p6(199.0,"Luke");

    sp.insert(p1);
    sp.insert(p2);
    sp.insert(p3);
    sp.insert(p4);
    sp.insert(p5);
    sp.insert(p6);


    for(auto & p:sp)
    {
        std::cout<<p;
    }
   // sp.erase(
   // std::cout<<mip[36];
   // std::cout<<sp.bucket_size(0);


}
