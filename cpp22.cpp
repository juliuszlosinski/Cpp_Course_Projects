#include <iostream>

class Box
{
    private:
    int width;
    int height;

    public:
    Box(int width, int height):width(width),height(height){}
};

class Node
{
    private:
    int value;
    Node* next;

    public:
    Node(int value,Node* next):value(value),next(next){}

    int GetValue()
    {
        return value;
    }

    void SetValue(int value)
    {
        this->value=value;
    }

    Node* GetNext()
    {
        return next;
    }

    void SetNext(Node* next)
    {
        this->next=next;
    }
};

class Stack
{
    private:
    Node* head;
    int n;

    public:
    Stack():head(NULL), n(0){}

    void Push(int value)
    {
        head=new Node(value, head);
        n++;
    }

    int Pop()
    {
        if(n==0)
        {
            return -1;
        }
        int value=head->GetValue();
        head=head->GetNext();
        n--;
        return value;
    }

    int Peek()
    {
        return head->GetValue();
    }


    void Print()
    {
        Node* tmp=head->GetNext();
        while(tmp!=nullptr)
        {
            std::cout<<static_cast<char>(tmp->GetValue()+65)<<", ";
            tmp=tmp->GetNext();
        }
    }

    int Contains(int value)
    {
        if(n==0)
        {
            return 0;
        }
        Node* tmp=head;
        while(tmp!=NULL)
        {
            if(tmp->GetValue()==value)
            {
                return 1;
            }
            tmp=tmp->GetNext();
        }
        return 0;
    }

    ~Stack()
    {
        delete head;
    }
};



void Test_Dynamic_Allocation()
{
    int v=5;       // A B C D E
    int graph[5][5]={{0,0,0,1,0}, // A
                     {0,0,1,1,0}, // B
                     {0,1,0,1,0}, // C
                     {0,1,1,0,1}, // D
                     {0,0,0,0,0}, // E
                     };
    Stack openSet; // Set for not visited vertexes.
    Stack closedSet; // Set for visited vertexes.
    int currentVertex=0; // Setting the current vertex to be A ~ start point.
    while(1)
    {
        //1. Adding current vertex to the closed set.
        closedSet.Push(currentVertex);

        //2. Finding the connections and adding them to the open set.
        for(int otherVertex=0;otherVertex<v;otherVertex++)
        {
            if(graph[currentVertex][otherVertex]==1 && !closedSet.Contains(otherVertex))
            {
                // If there is connection and closed doesn't have that edge add to the open set.
                openSet.Push(otherVertex);
            }
        }

        //3. Pop an vertex from the open set and as a current vertex "Going to another vertex".
        currentVertex=openSet.Pop();

        //4. End the algorithm when there is no node to consider in the open set.
        if(currentVertex==-1)break; 
    }
    closedSet.Print(); // Printing the reachable vertexes from A.
}

int main(void)
{
    Test_Dynamic_Allocation();
    return 0;
}