#include <iostream>
#include <cstdlib>
#include <ctime>

class Node
{
    private:
    int value;
    Node* next;

    public:
    Node(int value, Node* next)
    {
        this->value=value;
        this->next=next;
    }

    int GetValue()
    {
        return value;
    }

    void SetValue(int value)
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

class LinkedList
{
    private:
    Node* head;
    int n;

    public:
    LinkedList(int value)
    {
        head=new Node(value,NULL);
        n=0;
    }

    int GetCount()
    {
        return n;
    }

    private:
    void Add(Node* node, int value)
    {
        if(node->GetNext()==NULL)
        {
            node->SetNext(new Node(value, NULL));
        }
        else
        {
            Add(node->GetNext(), value);
        }
    }

    void Remove(Node* node, int value)
    {
        if(node->GetNext()->GetValue()==value)
        {
            node->SetNext(node->GetNext()->GetNext());
        }
        else
        {
            Remove(node->GetNext(), value);
        }
    }

    void Print(Node* node)
    {
        while(node!=NULL)
        {
            std::cout<<"\nVAL: "<<node->GetValue()<<std::endl;
            node=node->GetNext();
        }
    }

    public:
    void Add(int value)
    {
        Add(head, value);
    }

    void Remove(int value)
    {
        Remove(head, value);
    }

    void Print()
    {
        Print(head);
    }
};

const int N=20;
inline int valueR(){return rand()%1000;}

void Test()
{
    int n;
    std::cin>>n;
    int* data=(int*)malloc(sizeof(int)*n);
}

int main(void)
{
    Test();
    return 0;
}