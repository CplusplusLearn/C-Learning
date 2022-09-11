#include <iostream>
#include <map>
#include <vector>


class User{
    private:
        std::string m_name;
    public:
        User();
        User(std::string name);
        void setName(std::string name);
        std::string getName();
        ~User();
};

class SocialNetwork{
    private:
        std::map< User, std::vector<std::string> > m_friends;

    public: 
        SocialNetwork();
        SocialNetwork(const SocialNetwork & other);
        bool addUser(const User );//проверка, если юзер существует и добавление
        //1 - если добавился, 0 - если нет.
        void befriend(const User & us, std::string who);
        void unfriend(const User & us, std::string who);
        std::vector<std::string> getFriend(const User & us);
        void printSN() const;//распечатать всю социальную сеть в таком формате 
        //имя юзера --- список его друзей через запятую.

        bool deleteUser(User &  us);//Задача сложного уровня!
        //удаление юзера. Имейте в виду, что нужно удалять еще и юзера у всех из друзей!
        ~SocialNetwork();//нужно ли освобождать память???
};

