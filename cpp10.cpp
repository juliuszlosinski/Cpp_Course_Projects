#include <iostream>

void Draw_Graph_Matrix(int graph[5][5],int N)
{
    std::cout<<std::endl<<" ";
    for(int i=0;i<=N;i++)
    {
        if(i!=0)
        {
            std::cout<<i<<" ";
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
        std::cout<<(i+1)<<"| ";
        for(int j=0;j<N;j++)
        {
            std::cout<<graph[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}

int IsAllVisited(int* data, int n)
{
    //TODO: Check if all vertexes all checked.
    int res=0;
    for(int i=0;i<n;i++)
    {
        if(data[i]==1)
        {
            res=1;
        }
        else
        {
            res=0;
        }
    }
    return res;
}

int IsVertexVisited(int* data,int pos)
{
    return data[pos];
}

void Test()
{
    int N=5;
    int graph[5][5]={{0,3,4,5,0},
                     {3,0,0,0,4},
                     {4,0,0,0,3},
                     {5,0,0,0,2},
                     {0,4,3,2,0}};
    Draw_Graph_Matrix(graph, N);

   int visited[5]={0,0,0,0,0}; // Set all vertex be not visited.
   int distances[5]={1000,1000,1000,1000,1000}; // Set all distances to vertex to infinity ~ maximum value.
   int currentVertex=0, passedDistance=0, previousVertex=0; // Set the start vertex which is A ~ 0, and passed distance equals 0.

   while(IsAllVisited(visited,N)==0)
   {
       visited[currentVertex]=1; // Set the current vertex to be visited.
       if(passedDistance<distances[currentVertex]) // Check if current passed distance to node is smaller than the setten one.
       {
           // Set the newest distance.
           distances[currentVertex]=passedDistance;
       }
       int selectedMinDistance=10000, nextVertex=1000; // Set the start minimum distance, and next vertex to basic configuration.
       for(int vertex=0;vertex<N;vertex++) // Check the connections between current vertex an others.
       {
           int connection=graph[currentVertex][vertex]; // Get the connection.
           if(connection!=0) // If the connection is MUST BE 1!.
           {
               if((passedDistance+connection)<distances[vertex]) // Check if the newest passed distance + distance to another vertex(connection) is smaller than the settn one.
               {
                   distances[vertex]=passedDistance+connection; // Set the newest distance.
               }
               if(visited[vertex]==0) // If vertex wasn't before visited check if it has the smallest distance, find it.
               {    
                    if(connection<selectedMinDistance) // Check if it's smaller.
                    {
                        selectedMinDistance=connection; // Set the smallest distance.
                        nextVertex=vertex; // Set the vertex that will be chosen for the next.
                    }
               }
           }
       }
       previousVertex=currentVertex; // Set the previous vertex.
       currentVertex=nextVertex; // Set next vertex, "go to another vertex".
       passedDistance+=selectedMinDistance; // Add to passed distance new distance (path) that will be followed.
   }
   
    std::cout<<std::endl;

   for(int i=0;i<N;i++)
   {
       std::cout<<distances[i]<<" ";
   }
}

int main(void)
{
    Test();
    return 0;
}