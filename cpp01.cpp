#include <iostream>

class Node
{
    private:
    int value;
    Node* next;

    public:
    Node(int value,Node* next)
    {
        this->value=value;
        this->next=next;
    }

    int GetValue()
    {
        return value;
    }

    int SetValue(int value)
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

class Stack
{
    private:
    Node* head;

    public:
    Stack(int value)
    {
        head=new Node(value,NULL);
    }

    private:
    void Add(Node*ptr, int value)
    {
        if(ptr->GetNext()==NULL)
        {
            ptr->SetNext(new Node(value,NULL));
        }
        else
        {
            Add(ptr->GetNext(),value);
        }
    }

    public:
    void Add(int value)
    {
        Add(head, value);
    }

    private:
    void Print(Node* ptr)
    {
        if(ptr!=NULL)
        {
            std::cout<<"\n"<<ptr->GetValue()<<"\n";
            Print(ptr->GetNext());
        }
    }

    public:
    void Print()
    {
        Print(head);
    }
};


int main(void)
{   
    Stack stack(10);

    stack.Add(25);
    stack.Add(10);
    stack.Add(12);
    stack.Print();

    return 0;
}