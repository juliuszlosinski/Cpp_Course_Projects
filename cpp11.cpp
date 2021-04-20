#include <iostream>

void Draw_Graph_Matrix(int graph[5][5],int N)
{
    //TODO: Print matrix
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

int IsVisited(int first)
{
    return first;
}

void Print_Distances(int* data, int n)
{
    int c=65;
    for(int i=0;i<n;i++)
    {
        std::cout<<static_cast<char>(c)<<": "<<data[i]<<std::endl;
        c++;
    }
}

void Print_Path(int* dist, int* route, int n)
{
    int c=65, d=65;
    for(int i=0;i<n;i++)
    {
        std::cout<<static_cast<char>(c)<<": "<<dist[i]<<" via "<<static_cast<char>(d+route[i])<<std::endl;
        c++;
    }
}

void Test()
{
    const int N=5; // A B C D E
    int graph[N][N]={{0,4,3,0,0}, //A
                     {4,0,2,5,10}, //B
                     {3,2,0,5,1}, //C
                     {0,5,5,0,4}, //D
                     {0,10,1,4,0}, //E 
                    };
    
    Draw_Graph_Matrix(graph, N);

    // Setting the start configurations.
    int visited[N]={0,0,0,0,0};
    int route[N]={0,0,0,0,0};
    int distances[N]={1000,1000,1000,1000,1000};
    int passedDistance=0, currentVertex=0;
    distances[currentVertex]=0;

    while(IsAllVisited(visited,N)==0)
    {
        //1. Start: Set the current vertex to be visited.
        visited[currentVertex]=1;

        //2. Find connections and update the distances.
        for(int otherVertex=0;otherVertex<N;otherVertex++)
        {
            int distance=graph[currentVertex][otherVertex]; // Distance to next vertex.
            int totalDistance=distance+passedDistance; // Total distance: distance to vertex + passed length of path.

            //TODO: Set the newest distance if it is connected and total distance is smaller than previous one.
            if(distance>0 && totalDistance<distances[otherVertex]) 
            {
                distances[otherVertex]=totalDistance;
                route[otherVertex]=currentVertex; 
            }
        }

        //3. Find the minimum path from the current vertex to next.
        int minDistance =1000, nextVertex=1000;
        for(int otherVertex=0;otherVertex<N;otherVertex++)
        {
            int distance=graph[currentVertex][otherVertex]; // Distance to next vertex.
            // Check if it is connected, and it is not visited node, find min.
            if(distance>0 && visited[otherVertex]==0 && minDistance>distance)
            {
                minDistance=distance;
                nextVertex=otherVertex;
            }
        }

        //4. Set the new current vertex "Go to vertex!" and update distance.
        currentVertex=nextVertex;
        passedDistance+=minDistance;
    }
    Print_Path(distances,route,N);
}

int main(void)
{
    Test();
    return 0;
}