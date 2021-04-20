#include <iostream>
#include <fstream>

/*
    Calculate the MST using Prim's algorithm :)
    Graph is based on adjacency lists.
    by JL
    25.02.2021
*/

class Graph
{
    private:
    int** edges;
    int v, e;

    public:
    Graph(int v)
    {
        //TODO: Create the graph.
        this->v=v;
        edges=new int*[v];
        for(int i=0;i<v;i++)
        {
            edges[i]=new int[v];
            for(int j=0;j<v;j++)
            {
                edges[i][j]=0;
            }
        }
        e=0;
    }

    int GetNumberOfVertexes()
    {
        return v;
    }

    int GetNumberOfEdges()
    {
        return e;
    }

    int GetEdge(int first, int otherVertex)
    {
        //TODO: Get weight of connection between two vertexes ~ 0 means no connection.
        return edges[first][otherVertex];
    }

    void AddEdge(int first, int second, int weight)
    {
        //TODO: Add the weighted connection between two vertexes.
        edges[first][second]=weight;
        edges[second][first]=weight;
        e++;
    }

    void RemoveEdge(int first, int second)
    {
        //TODO: Remove the weighted connection between two vertexes.
        edges[first][second]=0;
        edges[second][first]=0;
        e--;
    }

    void PrintEdges()
    {
        //TODO: Print the weighted connections between edges.
        std::cout<<std::endl<<"<----------------------------------CONNECTIONS----------------------------------->"<<std::endl<<std::endl;
        int c=65;
        for(int i=0;i<v;i++)
        {
            std::cout<<static_cast<char>(c+i)<<": ";
            for(int j=0;j<v;j++)
            {
                int connection=edges[i][j];
                if(connection!=0)
                {
                    std::cout<<static_cast<char>(c+j)<<" with weight: "<<connection<<", ";
                }
            }
            std::cout<<std::endl;
        }
        std::cout<<std::endl<<"<-------------------------------------------------------------------------------->"<<std::endl;
    }
};

class Edge
{
    private:
    int from;
    int to;
    int weight;

    public:
    Edge(int from, int to, int weight)
    {
        this->from=from;
        this->to=to;
        this->weight=weight;
    }

    Edge()
    {

    }

    int GetFromVertex()
    {
        return from;
    }

    void SetFromVertex(int from)
    {
        this->from=from;
    }

    int GetToVertex()
    {
        return to;
    }

    void SetToVertex(int to)
    {
        this->to=to;
    }

    int GetWeight()
    {
        return weight;
    }
    
    void SetWeight(int weight)
    {
        this->weight=weight;
    }
};

class PriorityListWithEdges
{
    private:
    int size;
    int n;
    Edge* data;

    public:
    PriorityListWithEdges(int size)
    {
        //TODO: Create list.
        data=new Edge[size];
        this->size=size;
        n=0;
    }

    PriorityListWithEdges()
    {
        //TODO: Create list.
        this->size=30;
        data=new Edge[size];
        n=0;
    }

    int GetCount()
    {
        //TODO: Get total number of edges.
        return n;
    }

    void AddEdge(int from, int to, int weight)
    {
        //TODO: Add edge to an array.
        if(n>size)
        {
            Resize();
        }
        data[n]=Edge(from, to, weight);
        n++;
        Sort();
    }

    void RemoveEdge(int from, int to, int weight)
    {
        //TODO: Remove the edge.
        int index=GetIndex(from, to, weight);
        if(index!=-1)
        {
            for(int i=index;i+1<n;i++)
            {
                data[i]=data[i+1];
            }
            n--;
        }
        Sort();
    }

    void Sort()
    {
        //TODO: Sort the data.
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(data[j-1].GetWeight()>data[j].GetWeight())
                {
                    int tmpFrom = data[j].GetFromVertex();
                    int tmpTo = data[j].GetToVertex();
                    int tmpWeight = data[j].GetWeight();
                    data[j].SetFromVertex(data[j-1].GetFromVertex());
                    data[j].SetToVertex(data[j-1].GetToVertex());
                    data[j].SetWeight(data[j-1].GetWeight());
                    data[j-1].SetFromVertex(tmpFrom);
                    data[j-1].SetToVertex(tmpTo);
                    data[j-1].SetWeight(tmpWeight);
                }
            }
        }
    }

    int Cointains(int from, int to, int weight)
    {
        //TODO: Check if data with edges contains that edge.
        return (GetIndex(from, to, weight)!=-1)? 1:0; 
    }

    Edge Get_And_Remove_First()
    {
        //TODO: Pop first element.
        Edge edge=data[0];
        RemoveEdge(data[0].GetFromVertex(),data[0].GetToVertex(),data[0].GetWeight());
        return edge;
    }

    int GetIndex(int from, int to, int weight)
    {
        //TODO: Get index of an item from the data.
        int i=0;
        while(i<size)
        {
            if(data[i].GetFromVertex()==from && data[i].GetToVertex()==to && data[i].GetWeight()==weight)
            {
                return i;
            }
            i++;
        }
        return -1;
    }

    void Resize(int delta=2)
    {
        //TODO: Make the current data two times bigger.
        Edge* other=new Edge[1000];
        for(int i=0;i<n;i++)
        {
            other[i]=data[i];
        }
        data=other;
    }

    void Print()
    {
        //TODO: Print the data.
        std::cout<<std::endl;
        for(int i=0;i<n;i++)
        {
            std::cout<<"From "<<static_cast<char>(data[i].GetFromVertex()+65)<<" to "<<static_cast<char>(data[i].GetToVertex()+65)<<" is "<<data[i].GetWeight()<<std::endl;
        }
    }
};

int v=20; // Number of vertexes.

void MST_Analize(Graph graph)
{
    //TODO: Analize graph using Prim's algorithm for finding MST.
    int visitedVertexes[v]={0,0,0,0,0,0}; // Setting the array with visted vertexes.
    PriorityListWithEdges edgesToVertexes(100); // Setting the priority list with all edges.
    PriorityListWithEdges selectedEdges(100);   // Selected edges "previous one".
    int currentVertex=0; // Starting vertex ~ A.

    int noChange=1; // 0 ~ means break, 1 ~ do it.
    while(noChange==1)
    {
        //1. Setting the current vertex to be visited.
        visitedVertexes[currentVertex]=1;

        //2. Finding and adding the connections to edges to vertexes. (WARNING: "DO NOT ADD PATH TO VISITED VERTEX ~ CAN BE LOOP"!)
        int stop=0; // Set the condition, if no edge has been added it means 0 so exit the program to eliminate potential loop.
        for(int i=0;i<v;i++)
        {
            int connection=graph.GetEdge(currentVertex, i); // Getting the connection.
            if(visitedVertexes[i]==0 && connection>0)
            {
                // If there is connection and other vertex is not visited add edge to priority list with edges.
                edgesToVertexes.AddEdge(currentVertex, i, connection);
                stop=1; // Added age.
            }
        }
        noChange=stop;

        //3. Sellecting the next vertex with edge ~ "getting and removing first element from the priority list with edges and adding to selectedEdges."
        Edge edgeToNextVertex=edgesToVertexes.Get_And_Remove_First();
        selectedEdges.AddEdge(edgeToNextVertex.GetFromVertex(), edgeToNextVertex.GetToVertex(), edgeToNextVertex.GetWeight());
        currentVertex=edgeToNextVertex.GetToVertex();
    }

    std::cout<<"\nMap of edges that create MST: \n";
    selectedEdges.Print(); 
}


void Test_Graph()
{
    //TODO: Test operations on graph.
    // A: 0
    // B: 1
    // C: 2
    // D: 3
    // E: 4
    // F: 5
    // ...
    // Setting the graph.
    std::ifstream fdata("SampleTestData.txt");
    fdata>>v;
    Graph graph(v);
    int first, second, third;
    while(fdata>>first>>second>>third)
    {
        graph.AddEdge(first,second,third);
    }
    fdata.close();
    graph.PrintEdges();
    MST_Analize(graph);
}

int main(void)
{
    //TODO: Perform operations.
    Test_Graph();
    return 0;
}