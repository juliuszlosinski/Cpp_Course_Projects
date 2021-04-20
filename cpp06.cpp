#include <iostream>
#include <ctime>
#include <cstdlib>

template<class T> class Node
{
    private:
    T value;
    Node<T>* next;

    public:
    Node(T value, Node* next)
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

    Node* GetNext()
    {
        return next;
    }

    void SetNext(Node* next)
    {
        this->next=next;
    }
};

template<class T> class LinkedList
{
    private:
    Node<T>* head;
    int n;

    public:
    LinkedList(T value)
    {
        head=new Node<T>(value, NULL);
        n=0;
    }

    int GetCount()
    {
        return n;
    }

    private:
    void Add(Node<T>* node, T value)
    {
        if(node->GetNext()==NULL)
        {
            node->SetNext(new Node<T>(value,NULL));
            n++;
        }
        else
        {
            Add(node->GetNext(), value);
        }
    }

    void Remove(Node<T>* node, T value)
    {
        if(node->GetNext()->GetValue()==value)
        {
            node->SetNext(node->GetNext()->GetNext());
            n--;
        }
        else
        {
            Remove(node->GetNext(), value);
        }
    }

    void Print(Node<T>* node)
    {
        if(node!=NULL)
        {
            std::cout<<"\nVAL: "<<node->GetValue()<<std::endl;
            Print(node->GetNext());
        }
    }

    public:
    void Add(T value)
    {
        Add(head, value);
    }

    void Remove(T value)
    {
        Remove(head, value);
    }

    void Print()
    {
        Print(head);
    }
};

template <class T> inline void Swap_Array(T* first, T* second, int n)
{
    //TODO: Swap arrays.
    int i=0;
    while(i<n)
    {
        int tmp=*first;
        *first=*second;
        *second=tmp;
        first++;
        second++;
        i++;
    }
}

void Test_Array_Swapping()
{
    //TODO: Test array swapping function called by reference.
    srand(time(0));
    int n;
    std::cin>>n;
    n=(n==0)? rand()%1000:n;
    int* first=new int[n];
    int* second=new int[n];
    for(int i=0;i<n;i++)
    {
        first[i]=i;
        second[i]=rand()%100;
    }
    std::cout<<"BEF FIRST: "<<first[0] << ", "<<first[1]<<std::endl;
    std::cout<<"BEF SECOND: "<<second[0]<<", "<<second[1]<<std::endl;
    Swap_Array(first,second,n);
    std::cout<<"AFT FIRST: "<<first[0]<<", "<<first[1]<<std::endl;
    std::cout<<"AFT SECOND: "<<second[0]<<", "<<second[1]<<std::endl;
}

const int N=15;

void Test()
{
    //TODO: Test operations.
    srand(time(0));
    LinkedList<float> list(5.5f);
    int i=0;
    while(i<N)
    {
        list.Add(rand()%1000);
        i++;
    }
    std::cout<<"\nRESULTS: "<<std::endl;
    list.Print();
}

int main(void)
{   
    //TODO: Perform operations.
    Test();
    return 0;
}