#include <iostream>
#include <time.h>
#include <stdlib.h>

class Node
{
private:
    int value;
    Node* next;
    Node* previous;

public:
    Node(int value, Node* next, Node* previous)
    {
        this->value=value;
        this->next=next;
        this->previous=previous;
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

    Node* GetPrevious()
    {
        return previous;
    }

    void SetPrevious(Node* previous)
    {
        this->previous=previous;
    }
};

class LinkedList
{
private:
    Node* head;
    Node* tail;

public:
    LinkedList(int value)
    {
        tail=new Node(0,NULL,NULL);
        head=new Node(value,tail,NULL);
    }

    void Add(int value)
    {
        Node* tmp = head;
        while(tmp->GetNext()!=NULL)
        {
            tmp=tmp->GetNext();
        }
        tmp->SetNext(new Node(value,NULL,NULL));
    }

    void Print()
    {
        Print(head);
    }

    void Del(Node* node)
    {
        node=NULL;
    }

private:
    void Print(Node* node)
    {
        if(node!=NULL)
        {
            std::cout<<"\nV: "<<node->GetValue()<<std::endl;
            Print(node->GetNext());
        }
    }
};

void Test_Tree()
{
    //TODO: Test tree structure.
    srand(time(0));
    LinkedList list(5);
    Node* node;
    node=new Node(25,NULL,NULL);
    list.Del(node);
    std::cout<<"|VV: "<<node->GetValue()<<std::endl;
    for(int i=0;i<25;i++)
    {
        list.Add(rand()%1000);
    }
    list.Print();
}

int main(void)
{   
    //TODO: Perform operations.
    Test_Tree();
	return 0;
}