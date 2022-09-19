#include <iostream>
#include <string>
#include <list>
#include <set>
#include <deque>
#include <queue>
#include <unordered_set>
#include <unordered_map>
class info
{


};



class Node
{
    private:
       Node * parent;
       Node* leftChild;
       Node* rightChild;


};


int main()
{
    std::priority_queue<int> pq;
    for(int i = 0 ; i < 6 ; i ++)
    {
        int value = rand()%150;
        std::cout<<value<<"\t";
        pq.push(value);
    }
    std::cout<<"\n\n";
    while(!pq.empty())
    {
        std::cout<<pq.top()<<"\t";
        pq.pop();
    }

    std::unor
}