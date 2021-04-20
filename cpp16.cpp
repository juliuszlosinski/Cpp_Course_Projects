#include <iostream>
#include <ctime>
#include <cstdlib>

/*
    Implement the graph using adjecny lists and analize it using Dijkstra's algorithm for shortest path.
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

int IsAllVisited(int* data, int n)
{
    // Check if all vertexes are visited.
    int res=1;
    for(int i=0;i<n;i++)
    {
        if(data[i]==0)
        {
            res=0;
        }
    }
    return res;
}

void Print_Analize_Of_Graph(int* distancesToVertexes, int* route, int n)
{
    // Print the analize of graph.
    std::cout<<"\n<---------------------------SHORTEST PATHS AND ROUTES---------------------------->\n \n";
    std::cout<<"From A to another vertexes: \n";
    int c=65, sum;
    for(int i=0;i<n;i++)
    {
        std::cout<<static_cast<char>(c+i)<<": shortest path is "<<distancesToVertexes[i]<<" via "<< static_cast<char>(route[i]+c)<<std::endl;
        sum+=distancesToVertexes[i];
    }
    std::cout<<"\nAverage: "<<(static_cast<float>(sum))/n<<std::endl; 
    std::cout<<"\n<-------------------------------------------------------------------------------->\n \n";
}

const int N=5; // Size of graph.
const int INF=1000; // "Infinity" value.

void Analize_Graph(Graph graph, int N)
{
    // TODO: Analize the graph: get lengths of shortest paths and routes.
    // Setting the start configuration.
    int visitedVertexes[N]={0,0,0,0,0}; // Setting visited vertexes, not visted ~ 0, visted ~ 1.
    int distancesToVertexes[N]={INF,INF,INF,INF,INF}; // Setting start distances to all vertex to be visited.
    int route[N]={0,0,0,0,0}; // Setting the backtracking ~ path.
    int passedDistance=0; // Setting start distanc to zero.
    int currentVertex=0; // Setting current vertex to be A, START ~ A.
    distancesToVertexes[currentVertex]=0; // Setting the distance to A from A, equals 0.

    while(IsAllVisited(visitedVertexes,N)==0) // Do until all vertexes would be visited.
    {
        // 1. Set the current vertex to be visited.
        visitedVertexes[currentVertex]=1;

        // 2. Find the connection to other vertex and update the distances to vertexes.
        for(int i=0;i<N;i++)
        {
            int distance=graph.GetEdge(currentVertex, i); // Geting the connection.
            int totalDistance=passedDistance+distance; // Calculating the new length of the new to vertex.
            if(distance>0 && totalDistance<distancesToVertexes[i])
            {
                // If there is connection with other vertex, and the calculated total distance is smaller than previous one.
                distancesToVertexes[i]=totalDistance;
                route[i]=currentVertex; // Updating the route path to vertex "by what".
            }
        }

        // 3. Finding the minimum edge to vertex and setting that vertex to be the next vertex to visit.
        int minEdgeToVertex=INF, nextVertex=INF; // Setting start length of edge and next vertex to inifity.
        for(int i=0;i<N;i++)
        {
            int edgeToVertex=graph.GetEdge(currentVertex, i); // Getting the edge to another vertex.
            if(edgeToVertex>0 && edgeToVertex<minEdgeToVertex && visitedVertexes[i]==0)
            {
                // If there is connection (edgeToVertex must be greater than 0), that edge is smaller than
                // the previous one and that vertex is not visited.
                minEdgeToVertex=edgeToVertex;
                nextVertex=i;
            }
        }

        // 4. Setting the new current vertex "Going to another vertex" and updating the passed distance.
        passedDistance+=minEdgeToVertex;
        currentVertex=nextVertex;
    }

    Print_Analize_Of_Graph(distancesToVertexes,route,N); // Printing the results.
}

void Test_Graph()
{
    //TODO: Set the graph and analize it.
    // Setting the graph.
    //A: 0
    //B: 1
    //C: 2
    //D: 3
    //E: 4
    Graph graph(N);
    srand(time(0));
    for(int i=0;i<20;i++)
    {
        graph.AddEdge(rand()%5,rand()%4,rand()%10);  
    }
    std::cout<<"\n------\nTITLE: Setting the graph using weighted adjency lists and analizing it using Dijkstra's algorithm for the shortest path.\n\n";
    graph.PrintEdges();
    Analize_Graph(graph, N);
}

int main(void)
{
    //TODO: Perform operations.
    Test_Graph();
    return 0;
}
