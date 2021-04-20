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
            node->SetNext(new Node<T>(value, NULL));
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

    int Contains(Node<T>* node, T value)
    {
        if(node==NULL)
        {
            return 0;
        }
        else if(node->GetValue()==value)
        {
            return 1;
        }
        else
        {
            Contains(node->GetNext());
        }
    }

    void Print(Node<T>* node)
    {
        if(node!=NULL)
        {
            std::cout<<"\nVal: "<<node->GetValue()<<std::endl;
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

    int Contains(T value)
    {
        Contains(head, value);
    }

    void Print()
    {
        Print(head);
    }
};

template<class T> class Stack
{
    private:
    Node<T>* head;
    int n;

    public:
    Stack(T value)
    {
        head=new Node<T>(value, NULL);
        n=0;
    }

    int GetCount()
    {
        return n;
    }

    void Push(T value)
    {
        //TODO: Push an element on the stack.
        Node<T>* another;
        another=new Node<T>(value, head);
        head=another;
        n++;
    }

    T Pop()
    {
        //TODO: Pop an element from the stack.
        T tmp=head->GetValue();
        head=head->GetNext();
        n--;
        return tmp;
    }

    T Peek()
    {
        //TODO: Return value from the stack.
        return head->GetValue();
    }
    
    void Print()
    {
        //TODO: Print stack.
        Node<T>* tmp;
        tmp=head;
        while(tmp!=NULL)
        {
            std::cout<<"\nVal: "<<tmp->GetValue()<<std::endl;
            tmp=tmp->GetNext();
        }
    }
};

template<class T> class NodeTree
{
    private:
    T value;
    NodeTree<T>* left;
    NodeTree<T>* right;

    public:
    NodeTree(T value, NodeTree<T>* left, NodeTree<T>* right)
    {
        this->value=value;
        this->left=left;
        this->right=right;
    }

    T GetValue()
    {
        return value;
    }

    void SetValue(T value)
    {
        this->value=value;
    }

    NodeTree<T>* GetLeft()
    {
        return left;
    }

    void SetLeft(NodeTree<T>* left)
    {
        this->left=left;
    }

    NodeTree<T>* GetRight()
    {
        return right;
    }

    void SetRight(NodeTree<T>* right)
    {
        this->right=right;
    }
};

template <class T> class Tree
{
    private:
    NodeTree<T>* root;
    int n;

    public:
    Tree(T value)
    {
        root=new NodeTree<T>(value, NULL, NULL);
        n=0;
    }

    int GetCount()
    {
        return n;
    }

    void Add(NodeTree<T>* node, T value)
    {
        //TODO: Add element to the tree.
        if(node->GetValue()>value)
        {
            if(node->GetLeft()==NULL)
            {
                node->SetLeft(new NodeTree<T>(value, NULL, NULL));
                n++;
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
                node->SetRight(new NodeTree<T>(value, NULL, NULL));
                n++;
            }
            else
            {
                Add(node->GetRight(), value);
            }
        }
    }

    void Print(NodeTree<T>* node)
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

    T GetMax(NodeTree<T>* node)
    {
        //TODO: Get maximum value.
        if(node->GetRight()==NULL)
        {
            return node->GetValue();
        }
        else
        {
            return GetMax(node->GetRight());
        }
    }

    T GetMin(NodeTree<T>* node)
    {
        //TODO: Get minimum value.
        if(node->GetLeft()==NULL)
        {
            return node->GetValue();
        }
        else
        {
            return GetMin(node->GetLeft());
        }
    }

    void Add(T value)
    {
        //TODO: Add element to the tree.
        Add(root, value);
    }

    void Print()
    {
        //TODO: Print the tree.
        Print(root);
    }

    T GetMax()
    {
        //TODO: Get maximum value of the tree.
        return GetMax(root);
    }

    T GetMin()
    {
        //TODO: Get minimum value of the tree.
        return GetMin(root);
    }
};

void Test()
{
    //TODO: Test tree ADT.
    srand(time(0));
    int n;
    std::cout<<"\nEnter times: "<<std::endl;
    std::cin>>n;
    int value;
    std::cout<<"\nEnter values: "<<std::endl;
    Tree<int> tree(value);
    n--;
    for(int i=0;i<n;i++)
    {
        std::cin>>value;
        tree.Add(value);
    }
    std::cout<<"\nResults: "<<std::endl;
    tree.Print();
    std::cout<<"\nMAX: "<<tree.GetMax()<<"\n"<<"\nMIN: "<<tree.GetMin()<<std::endl;
}

int main(void)
{
    //TODO: Perform operations.
    Test();
    return 0;
}