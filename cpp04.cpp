#include <iostream>
#include <time.h>
#include <stdlib.h>

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
        this->head=new Node(value,NULL);
        n=0;
    }

    int GetCount()
    {
        return n;
    }

    private:
    void Add(Node* node, int value)
    {
        //TODO: Add element to the linked list.
        if(node->GetNext()==NULL)
        {
            node->SetNext(new Node(value,NULL));
            n++;
        }
        else
        {
            Add(node->GetNext(),value);
        }
    }

    void Remove(Node* node,int value)
    {
        //TODO: Remove element from the linked list.
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

    void Print(Node* node)
    {
        //TODO: Print linked list.
        if(node!=NULL)
        {
            std::cout<<"\nVAL: "<<node->GetValue()<<std::endl;
            Print(node->GetNext());
        }
    }

    public:
    void Add(int value)
    {
        //TODO: Add element to linked list.
        Add(head, value);
    }

    void Remove(int value)
    {
        //TODO: Remove element from the linked list.
        Remove(head, value);
    }

    void Print()
    {
        //TODO: Print linked list.
        Print(head);
    }
};

class Stack
{
    private:
    Node* head;
    int n;

    public:
    Stack(int value)
    {
        head=new Node(value,NULL);
        n=0;
    }

    int GetCount()
    {
        return n;
    }

    void Push(int value)
    {
        //TODO: Push element on the stack.
        Node* other=new Node(value,head);
        head=other;
        n++;
    }

    int Pop()
    {
        //TODO: Pop element from the stack.
        n--;
        int value=head->GetValue();
        head=head->GetNext();
        return value;
    }

    int Peek()
    {
        //TODO: Return value of the current element on the stack.
        return head->GetValue();
    }
};

class Queue
{
    private:
    Node* head;
    int n;

    public:
    Queue(int value)
    {
        head=new Node(value,NULL);
        n=0;
    }

    int GetCount()
    {
        return n;
    }

    private:
    void Enqueue(Node* node, int value)
    {
        //TODO: Add element to the queue.
        if(node->GetNext()==NULL)
        {
            node->SetNext(new Node(value,NULL));
        }
        else
        {
            Enqueue(node->GetNext(), value);
        }
    }

    void Print(Node* node)
    {
        //TODO: Print queue.
        if(node!=NULL)
        {
            std::cout<<"\nVAL: "<<node->GetValue()<<std::endl;
            Print(node->GetNext());
        }
    }

    public:
    void Enqueue(int value)
    {
        //TODO: Add element to the queue.
        Enqueue(head, value);
    }

    int Dequeue()
    {
        //TODO: Remove element from the queue.
        int value=head->GetValue();
        head=head->GetNext();
        return value;
    }

    void Print()
    {
        //TODO: Print queue.
        Print(head);
    }
};

class NodeTree
{
    private:
    int value;
    NodeTree* left;
    NodeTree* right;

    public:
    NodeTree(int value, NodeTree* left, NodeTree* right)
    {
        this->value=value;
        this->left=left;
        this->right=right;
    }

    int GetValue()
    {
        return value;
    }

    void SetValue(int value)
    {
        this->value=value;
    }

    NodeTree* GetLeft()
    {
        return left;
    }

    void SetLeft(NodeTree* left)
    {
        this->left=left;
    }

    NodeTree* GetRight()
    {
        return right;
    }

    void SetRight(NodeTree* right)
    {
        this->right=right;
    }
};

class Tree
{
    private:
    NodeTree* root;
    int n;

    public:
    Tree(int value)
    {
        root=new NodeTree(value,NULL,NULL);
        n=0;
    }

    private:
    void Add(NodeTree* node, int value)
    {
        //TODO: Add element to the tree.
        if(node->GetValue()>value)
        {
            if(node->GetLeft()==NULL)
            {
                node->SetLeft(new NodeTree(value,NULL,NULL));
            }
            else
            {
                Add(node->GetLeft(), value);
            }
        }
        else if(node->GetValue()<value)
        {
            if(node->GetRight()==NULL)
            {
                node->SetRight(new NodeTree(value,NULL,NULL));
            }
            else
            {
                Add(node->GetRight(), value);
            }
        }
    }

    void Print(NodeTree* node)
    {
        //TODO: Print the tree.
        if(node!=NULL)
        {
            if(node->GetLeft()!=NULL)
            {
                Print(node->GetLeft());
            }

            std::cout<<"\nVAL: "<<node->GetValue()<<std::endl;

            if(node->GetRight()!=NULL)
            {
                Print(node->GetRight());
            }
        }
    }

    public:
    void Add(int value)
    {
        //TODO: Add element to the tree.
        Add(root, value);
    }

    void Print()
    {
        //TODO: Print the tree.
        Print(root);
    }
};

class List
{
    private:
    int* data;
    int size;
    int n;

    public:
    List(int size)
    {
        data=(int*)malloc(size*sizeof(int));
        this->size=size;
        n=0;
    }

    
    private:
    void Resize()
    {
        //TODO: Resize list.
        int* other;
        int newSize=size*2;
        other=(int*)malloc(sizeof(int)*newSize);
        for(int i=0;i<n;i++)
        {
            other[i]=data[i];
        }
        this->size=newSize;
        data=other;
    }

    public:
    void Add(int value)
    {
        //TODO: Add element to the list.
        if(n>size)
        {
            Resize();
        }

        data[n]=value;
        n++;
    }

    void Print()
    {
        //TODO: Print the list.
        for(int i=0;i<n;i++)
        {
            std::cout<<"\nVAL: "<<data[i]<<std::endl;
        }
    }
};

void Test()
{
    //TODO: Test operations on data structures.
    srand(time(0));
    List list(20);
    for(int i=0;i<35;i++)
    {
        list.Add(rand()%1000);
    }
    list.Print();
}

int main(void)
{
    //TODO: Do program.
    Test();
    return 0;
}