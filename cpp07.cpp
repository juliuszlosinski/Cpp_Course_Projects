#include <iostream>
#include <cstdlib>
#include <ctime>

template <class T> class NodeTree
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
        root=new NodeTree<T>(value,NULL,NULL);
        n=0;
    }

    int GetCount()
    {
        return n;
    }

    private:
    void Add(NodeTree<T>* node, T value)
    {
        if(node->GetValue()>value)
        {
            if(node->GetLeft()==NULL)
            {
                node->SetLeft(new NodeTree<T>(value,NULL,NULL));
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
                node->SetRight(new NodeTree<T>(value,NULL,NULL));
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
    void Add(T value)
    {
        Add(root, value);
    }

    void Print()
    {
        Print(root);
    }
};


void Test_Tree()
{
    //TODO: Test tree structure (ADT).
    int n;
    srand(time(0));
    std::cout<<"\nEnter size:"<<std::endl;
    std::cin>>n;
    int x;
    std::cout<<"\nEnter value: "<<std::endl;
    std::cin>>x;
    Tree<int> tree(x);
    if(n>1)
    {
        for(int i=0;i<n-1;i++)
        {
            std::cout<<"\nEnter value: "<<std::endl;
            std::cin>>x;
            tree.Add(x);
        }
        std::cout<<"\nResults: "<<std::endl;
    }
    tree.Print();
}

template<class T> T Sum(const T* data, int n, T sum=0)
{
    //TODO: Calculate the sum of elements from generic data.
    int i=0;
    while(i<n)
    {
        sum+=*data;
        data++;
        i++;
    }
    return sum;
}

template<class T> void Print_Array(const T* data, int n, int i=0)
{
    //TODO: Print the array.
    data+=i;
    while(i<n)
    {
        std::cout<<"\nVAL: "<<*data<<std::endl;
        data++;
        i++;
    }
}

template<class T, class Y> void Simple(T first, Y second)
{
    //TODO: Print two variables.
    std::cout<<"\nFirst: "<<first<<std::endl;
    std::cout<<"\nSecond: "<<second<<std::endl;
}

template<class T> T Sub(const T* data, int n, T sub=124)
{
    //TODO: Sub elements from element.
    for(int i=0;i<n;i++)
    {
        sub-=*data;
        data++;
    }
    return sub;
}

void Test_Sum()
{
    //TODO: Test sum.
    srand(time(0));
    int n;
    std::cout<<"\nEnter size: "<<std::endl;
    std::cin>>n;
    int* first=new int[n];
    int* second=new int[n];
    int* third=new int[n];
    for(int i=0;i<n;i++)
    {
        first[i]=rand()%10000+10;
        second[i]=rand()%100-10;
        third[i]=rand()%100+30;
    }
    Print_Array(first, n);
    int sub=Sub(first, n);
    std::cout<<"\nSum of three arrays: "<< Sum(third, n, (second, n, (first, n)))<<std::endl;
}

int main(void)
{
    //TODO: Perform operations.
    //Test_Tree();
    Test_Sum();
    return 0;
}