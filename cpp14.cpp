#include <iostream>

class ListWithEdges;
class Vertex;
class Edge;

class Edge
{
    private:
    Vertex* connected;
    int weight;

    public:
    Edge(Vertex* connected, int weight)
    {
        this->connected=connected;
        this->weight=weight;
    }

    Edge()
    {

    }

    Vertex* GetConnectedTo()
    {
        return connected;
    }

    int GetWeight()
    {
        return weight;
    }
};

class ListWithEdges
{
    private:
    Edge* edges;
    int n, size;

    public:
    ListWithEdges(int size)
    {
        this->size=size;
        edges=(Edge*)malloc(sizeof(Edge)*size);
        n=0;
    }

    void Add(Edge edge)
    {
        if(n>size)
        {
            Resize();
        }

        edges[n]=edge;
        n++;
    }

    void GetIndex(int value)
    {
        int index=-1;
        for(int i=0;i<n;i++)
        {
            if((edges[i])->GetConnectedTo->GetValue==value)
            {

            }
        }
    }

    void Remove(int value)
    {
        
    }

    void Resize()
    {
        Edge* other=new Edge[size*2];
        for(int i=0;i<n;i++)
        {
            other[i]=edges[i];
        }
        edges=other;
    }
};

class Vertex
{
    private:
    int value;
    ListWithEdges* list;

    public:
    Vertex(int value)
    {
        this->value=value;
        list=new ListWithEdges(15);
    }

    int GetValue()
    {
        return value;
    }

    ListWidthEdges* GetConnections()
    {
        return list;
    }

    void AddEdge(Vertex* vertex, int weight)
    {
        Edge edge(vertex, weight);
        list->Add(edge);
    }
};


int main(void)
{
    return 0;
}