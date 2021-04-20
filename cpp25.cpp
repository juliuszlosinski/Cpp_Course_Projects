#include <iostream>

template <class T> class Graph
{
    private:
    int** connections;
    T** weight;
    int v;
    int e;

    public:
    Graph(int v)
    {
        connections=new int*[v];
        weight=new T*[v];
        for(int i=0;i<v;i++)
        {
            connections[i]=new int[v];
            weight[i]=new T[v];
        }
        this->v=v;
        e=0;
    }

    void AddEdge(int first, int second, T weight)
    {
        connections[second][first]=connections[first][second]=1;
        weight[first][second]=weight[second][first]=weight;
    }

    void RemoveEdge(int first, int second)
    {
        connections[second][first]=connections[first][second]=0;
        weight[first][second]=weight[second][first]=0;
    }
};

int main(void)
{
    std::cout<<"Hello!";
    Graph<int> graph(10);
    int a=15;
    int* p = new int(5);
    p=&a;
    *p=25;
    std::cout<<"ADR: "<<p<<"\nVAL: "<<a<<std::endl;
    return 0;
}