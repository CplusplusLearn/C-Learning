#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <queue> 
#include <stack>
#include <unordered_set>
#include <map>
#include <functional>

class Client{
private:
    uint16_t m_id;
    std::string m_name;
    double m_account; //количество денег на аккаунте
    double m_debt;  //задолжность банку
    
    //information about credit date:
    uint16_t day;
    uint16_t moth;
    uint16_t year;
public:
    здесь должно быть кучу геттеров!!!
    + оператор << 
};

enum operationStatus{//почитать что такое enum 
    ENROLL,//зачисление == 0
    WITHDRAW,//снятие  == 1 
    CREDIT//взятие денег в кредит == 2 
};

class Operation{
private:
    operationStatus m_os;
    uint16_t m_fromWho;//айдишник того от кого перевод, если это банк, то айди == 0
    uint16_t m_toWhom;//айди того - кому перевод, банк =>  0 
    double m_value;//сумма перевода 
public:
    Operation(operationStatus os, uint16_t fromWho,uint16_t toWhom,double value):
            m_os(os), m_fromWho(fromWho), m_toWhom(toWhom),m_value(value)
    {}

    геттеры и сеттеры если потребуется!
    оператор << который в красивом виде будет печатать от кого и кому и тд

};

class Bank {
private:

    std::string m_name;  // название банка      
    float m_transactionPercent; // процент на перевод от одного клиента другмоу 
    float m_creditPercent;//процент на кредит
    size_t m_quantityOfClients; // количество клиентов 

    //для анордеред мапа необходимо написать хэшируюшую функцию -- гуглим!!!
    //если гугл не помог - то ко мне в лс.
    std::unordered_map<Client,std::vector<Operation>> m_clients; //ключ - клиент, сортировка по порядковому номеру
    //значение --- (история операция) вектор с обьектами класса "операция" (перевод, вклад в банк, взятие из банка денег)
    std::priority_queue<Client> m_applicationForCredit;//Заявление на получение кредита
    //необходимо сделать таким образом, чтобы в прайорити queue у нас клиенты сортировались по
    //размеру суммы, которая получается в следствии вычитания из денег на счету суммы долга
    //как поменять функцию сортировки -- https://stackoverflow.com/questions/29587439/c-stdpriority-queue-comparing-using-transformation

    
public: 

    Bank(std::string name = "Default bank name",double transPercent = 2.0, double credPercent = 10.0);

    Bank(const Bank & bk);
    bool addClient(std::string name);//добавление в базу 

    bool transAction(Client & from, Client & to, double howMuch);//перевод от одного клиента другому 
    //с учетом комиссии 
    bool application(Client & name);//добавляем имя человека в заявку на кредит
    bool credit(Client & who, double howMuch);//нужно ответить, одобрен ли человеку кредит или нет
    void update();//начисление процентов по кредиту
    void getInfo(const Client & c1);//получение инфы по счёту, по кредиту и по дате следующего начисленяи процентов по кредиту
    void getOperations(const Client & c1); //получение всех операций в нормальном виде.
    ~Bank(); //нужно ли что-то удалять???
};
