#include <iostream>
#include <map>
#include <set>
#include <algorithm> 
#include <functional>

int main()
{

    std::multimap <int , std::string>  mis;



    mis.insert(std::make_pair(1,"one"));
    mis.insert(std::make_pair(2,"two"));
    mis.insert(std::make_pair(5,"five"));
    mis.insert(std::make_pair(1,"uno"));
    mis.insert(std::make_pair(1,"ein"));
    mis.insert(std::make_pair(4,"chetire"));
    mis.insert(std::make_pair(4,"four"));
    mis.insert(std::make_pair(3,"three"));

    for(auto & [a,b]: mis)
    {
        std::cout<<a<<" ---> "<<b<<"\n";
    }
    
    auto it = mis.find(4);
    std::cout<<"\n\n"<<it->second;

    auto itb = mis.begin();
    while(itb != mis.end())
    {
        if(itb->first == 4 && itb->second == "chetire")
            std::cout<<itb->first<<"---> "<<itb->second;
        itb++;
    }
 

//     mis.erase(1);
//     std::cout<<"\n\n";

//    // erasing
//     for(auto & [a,b]: mis)
//     {
//         std::cout<<a<<" ---> "<<b<<"\n";
//     }

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


// int main()
// {
//     std::multiset <Person> si;//change to set to differ
//     si.emplace(Person{187.9,"Mike"});
//     si.emplace(Person{187.9,"Jhon"});
//     si.emplace(Person{165.6,"Elisabeth"});
//     si.emplace(Person{212.9,"Ann"});
//     si.emplace(Person{212.9,"Luke"});
//     si.emplace(Person{173.2,"Michael"});
   

//     auto it = si.begin();

//     while(it!=si.end())
//     {
//         std::cout<<*it++;
//     }

//     si.erase({187.9,"Mike"});
//     std::cout<<"\n";

//    it = si.begin();

//     while(it!=si.end())
//     {
//         std::cout<<*it++;
//     }
// }



