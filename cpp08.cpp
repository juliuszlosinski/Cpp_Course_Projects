#include <iostream>
#include <cstdlib>
#include <ctime>

template<class T> class Node
{
    private:
    T value;
    Node<T>* next;

    public:
    Node(T value, Node<T>* next)
    {
        this->value=value;
        this->next=next;
    }

    T GetValue()
    {
        return value;
    }

    void SetValue(T value)
    {
        this->value=value;
    }

    Node<T>* GetNext()
    {
        return next;
    }

    void SetNext(Node<T>* next)
    {
        this->next=next;
    }
};

template <class T> class Stack
{
    private:
    Node<T>* head;
    int n;

    public:
    Stack(T value)
    {
        head=new Node<T>(value,NULL);
        n=0;
    }

    int GetCount()
    {
        return n;
    }

    void Push(T value)
    {
        Node<T>* another;
        another=new Node<T>(value, head);
        head=another;
    }

    T Pop()
    {
        T tmp=head->GetValue();
        head=head->GetNext();
        return tmp;
    }

    T Peek()
    {
        return head->GetValue();
    }
};


template<class T> void Swap(T* first, T* second, int n)
{
    //TODO: Swap elements function.
    for(int i=0;i<n;i++)
    {
        T tmp=*first;
        *first=*second;
        *second=tmp;
        first++;
        second++;
    }
}

template<class T> T Mul(T* first, T* second, int n, int i=0, T sum=0)
{
    //TODO: Mul two data.
    while(i<n)
    {
        sum+=*first+*second;
        first++;
        second++;
        i++;
    }
    return sum;
}

template<class T> T Sum(T* data, int n, int sum=0)
{
    //TODO: Sum element from the list.
    for(int i=0;i<n;i++)
    {
        sum+=*data;
        data++;
    }
    return sum;
}

void Test()
{
    //TODO: Test operations.
    srand(time(0));
    std::cout<<"\nEnter size: "<<std::endl;
    int n;
    std::cin>>n;
    int* first;
    first=new int[n];
    int* second;
    second=new int[n];
    for(int i=0;i<n;i++)
    {
        *first=rand()%1000;
        first++;
        *second=rand()%1000;
        second++;
    }
    first-=n;
    second-=n;
    std::cout<<"\nBefore first: "<<first[0]<<", "<<first[1]<<std::endl;
    std::cout<<"\nBefore second: "<<second[0]<<", "<<second[1]<<std::endl;
    Swap(first, second, n);
    std::cout<<"\nAfter first: "<<first[0]<<", "<<first[1]<<std::endl;
    std::cout<<"\nAfter second: "<<second[0]<<", "<<second[1]<<std::endl;
}

int main(void)
{
    //TODO: Perform operations.
    Test();
    return 0;
}