#include <iostream>

template <class T> class List
{
private:
    T* data;
    int n;
    int size;

public:
    List(int size)
    {
        this->size = size;
        data = new T[size];
        n = 0;
    }

    int GetCount()
    {
        return n;
    }

    int Contains(T item)
    {
        int i = 0;
        while (i < n)
        {
            if (data[i] == item)
            {
                return 1;
            }
            i++;
        }
        return 0;
    }

    int GetIndex(T item)
    {
        int i = 0;
        while (i < n)
        {
            if (data[i] == item)
            {
                return i;
            }
            i++;
        }
        return -1;
    }

    void Resize()
    {
        T* other;
        other = new T[size * 2];
        int i = 0;
        while (i < n)
        {
            other[i] = data[i];
            i++;
        }
        data = other;
    }

    void Add(T item)
    {
        if (n > size)
        {
            Resize();
        }

        data[n] = item;
        n++;
    }

    void Remove(T item)
    {
        int res = GetIndex(item);
        if (res != -1)
        {
            for (int i = res; i + 1 < n; i++)
            {
                data[i] = data[i + 1];
            }
        }
        n--;
    }

    void Print()
    {
        for (int i = 0; i < n; i++)
        {
            std::cout << std::endl << data[i] << std::endl;
        }
    }
};

class Edge;
class Vertex;

class Edge
{
private:
    Vertex* connected;
    int weight;

public:
    Edge(Vertex* connected, int weight)
    {
        this->connected = connected;
        this->weight = weight;
    }

    Edge()
    {

    }

    int GetWeight()
    {
        return weight;
    }

    Vertex* GetConnectedTo()
    {
        return connected;
    }
};


class Vertex
{
private:
    int ID;
    List<Edge>* list;

public:
    Vertex(int ID)
    {
        this->ID;
        list = new List<Edge>(10);
    }

    void AddEdge(Vertex* vertex, int weight)
    {
        Edge ed(vertex, weight);
        list->Add(ed);
    }

    void RemoveEdge(Edge edge)
    {
    }
};




int main(void)
{
    return 0;
}