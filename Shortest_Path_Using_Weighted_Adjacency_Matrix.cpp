#include <iostream>

/*
    Set the graph using adjacency matrix and analize it using Dijkstra's algorithm for the shortest paths.
    by JL
    25.02.2021
*/

void Draw_Graph_Matrix(int graph[5][5],int N)
{
    //TODO: Print graph.
    std::cout<<"\n<-----------------------CONNECTIONS------------------------>\n \n"<<" ";
    for(int i=0;i<=N;i++)
    {
        if(i!=0)
        {
            std::cout<<static_cast<char>(65+i-1)<<" ";
        }
        else
        {
            std::cout<<"  ";
        }
    }
    std::cout<<std::endl;
    for(int i=0;i<=N;i++)
    {
        if(i!=0)
        {
            std::cout<<"--";
        }
        else
        {
            std::cout<<"  ";
        }
    }
    std::cout<<std::endl;
    for(int i=0;i<N;i++)
    {
        std::cout<<(static_cast<char>(65+i))<<"| ";
        for(int j=0;j<N;j++)
        {
            std::cout<<graph[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<"\n<---------------------------------------------------------->\n \n";
}

int IsAllVisited(int* data, int n)
{
    //TODO: Check if all vertexes are visited.
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

int IsVisited(int vertex)
{
    //TODO: Check if vertex is visted.
    return vertex;
}

void Print_Result_Of_Analizing_Graph(int* distances, int* via, int n)
{
    //TODO: Printing the result of analizing graph: route + distances.
    std::cout<<"\n<----------------SHORTEST PATHS AND ROUTES----------------->\n\n";
    int d = 65, v = 65, i = 0;
    std::cout<<"From A to other vertexes:"<<std::endl;
    while(i<n)
    {
        std::cout<<static_cast<char>(d)<<": shortest path is "<<distances[i]<<" via "<<static_cast<char>(v+via[i])<<std::endl;
        i++;
        d++;
    }
    std::cout<<"\n<---------------------------------------------------------->\n";
}

const int N=5; // Size of graph.
const int INF=1000000; // "Infinity".

void Analize_Graph(int graph[N][N])
{
    //TODO: Analize the graph, get the shortest path to vertexes and info about path to them.
    // Setting start configuration.
    int visitedVertexes[N]={0,0,0,0,0}; // Setting all vertexes to be not visited ~ 0 means not visited.
    int route[N]={0,0,0,0,0}; // Setting array for routes, change number will mean character~ static_cast<char>(rout[x]);
    int distancesToVertexes[N]={INF,INF,INF,INF,INF}; // Setting start distances to vertexes to be infinity.
    int passedDistance=0; // Setting passed distance, start ~ 0.
    int currentVertex=0;  // Setting the first vertex, our start.
    distancesToVertexes[currentVertex]=0; // Setting the first vertex to be visited.

    while(IsAllVisited(visitedVertexes,N)==0)
    {
        //1. Setting the current vertex to be visited.
        visitedVertexes[currentVertex]=1;

        //2.Finding connections and updating the distances to vertexes.
        for(int otherVertex=0;otherVertex<N;otherVertex++)
        {
            int distance=graph[currentVertex][otherVertex]; // Getting the connection.
            int totalDistance=passedDistance + distance;    // Suming passed distance and distance to vertex.
            if(distance>0 && totalDistance<distancesToVertexes[otherVertex]) 
            {
                // If there is connection to vertex, and if total distance is smaller than the previous one
                // update the distances to vertex ~ current distance to other vertex.
                distancesToVertexes[otherVertex]=totalDistance;
                route[otherVertex]=currentVertex;
            }
        }

        //3. Finding the minimum edge to another vertex and getting this vertex as future next.
        int minDistanceToVertex=INF, nextVertex=INF;
        for(int otherVertex=0;otherVertex<N;otherVertex++)
        {
            int distance=graph[currentVertex][otherVertex];
            if(distance>0 && visitedVertexes[otherVertex]==0 && minDistanceToVertex>distance)
            {
                // If theres is a connection to vertex, it is not visited and distance is smaller than previous one.
                minDistanceToVertex=distance;
                nextVertex=otherVertex;
            }
        }

        //4. Setting the new current vertex ~ "Going to another vertex", and updating passed distance.
        currentVertex=nextVertex;
        passedDistance+=minDistanceToVertex;
    }

    Draw_Graph_Matrix(graph, N); // Drawing the graph.
    Print_Result_Of_Analizing_Graph(distancesToVertexes, route, N); // Printing the results
}

void Test_Graph()
{        
    //TODO: Test graph.       
    int graph[N][N]={//A B C D E
                      {0,4,3,0,0}, // A        Our graph/ data to explore.
                      {4,0,2,5,10}, // B
                      {3,2,0,5,1}, // C
                      {0,5,5,0,4}, // D
                      {0,10,1,4,0}  // E
                     }; 
    std::cout<<"\n------\nTITLE: Creating the graph using weighted adjacency matrix and analizing it using Dijkstra's algorithm for the shortest path.\n\n";
    Analize_Graph(graph); 
}

int main(void)
{
    //TODO: Perform operations.
    Test_Graph();
    return 0;
}