#include <iostream>

class Box
{
private:
    int width;
    int height;

public:
    Box(int width, int height) :width(width), height(height) {}

    int GetWidth()
    {
        return width;
    }

    void SetWidth(int width)
    {
        this->width = width;
    }

    int GetHeight()
    {
        return height;
    }

    void SetHeight(int height)
    {
        this->height = height;
    }
};

std::ostream& operator<<(std::ostream& out, Box box)
{
    out << "Width: " << box.GetWidth() << "\nHeight: " << box.GetHeight();
    return out;
}

template<class T> class Node
{
private:
    T value;
    Node<T>* next;

public:
    Node(T value, Node* next) :value(value), next(next) {}

    T GetValue()
    {
        return value;
    }

    void SetValue(T value)
    {
        this->value = value;
    }

    Node* GetNext()
    {
        return next;
    }

    void SetNext(Node* next)
    {
        this->next = next;
    }
};

int operator== (Box first, Box second)
{
    if (first.GetWidth() == second.GetWidth() && first.GetHeight() == second.GetHeight())
    {
        return 1;
    }
    return 0;
}

template<class T> class LinkedList
{
private:
    Node<T>* head;
    int n;

public:
    LinkedList() :head(nullptr), n(0) {}

    int GetCount()
    {
        return n;
    }

private:
    void AddToBack(Node<T>* node, T value)
    {
        //TODO: HELPER_Adding to back of the list.
        if (node->GetNext() == nullptr)
        {
            node->SetNext(new Node<T>(value, nullptr));
        }
        else
        {
            AddToBack(node->GetNext(), value);
        }
    }

    void Remove(Node<T>* node, T value)
    {
        //TODO: HELPER_Removing the element.
        if (node->GetNext()->GetValue() == value)
        {
            node->SetNext(node->GetNext()->GetNext());
        }
        else
        {
            Remove(node->GetNext(), value);
        }
    }

    void Print(Node<T>* node)
    {
        //TODO: HELPER_Print the linked list.
        if (node != NULL)
        {
            std::cout <<"\n"<<node->GetValue() <<"\n";
            Print(node->GetNext());
        }
    }

public:
    void Add(T value)
    {
        //TODO: Defualt add to the list.
        AddToBack(value);
    }

    void AddToFront(T value)
    {
        //TODO: Adding to front of the list.
        head = new Node<T>(value, head);
    }

    void AddToBack(T value)
    {
        //TODO: Adding to back of the list.
        if (head == nullptr)
        {
            AddToFront(value);
        }
        else
        {
            AddToBack(head, value);
        }
    }

    void Remove(T value)
    {
        //TODO: Removing element from the list.
        Remove(head, value);
    }

    void Print()
    {
        //TODO: Print the linked list.
        Print(head);
    }
};

void Test()
{
    LinkedList<Box> boxes;
    boxes.Add(Box(15,20));
    boxes.Add(Box(32,50));
    boxes.Add(Box(50,60));
    boxes.Remove(Box(32,50));
    boxes.Print();
}

int main(void)
{
    Test();
    return 0;
}
