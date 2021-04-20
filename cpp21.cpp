#include <iostream>
#include <cstdlib>
#include <ctime>

class Box
{
    private:
    int width;
    int height;

    public:
    Box(int width, int height)
    {
        this->width=width;
        this->height=height;
    }

    Box()
    {
        width=0;
        height=0;
    }

    int GetWidth()
    {
        return width;
    }

    void SetWidth(int width)
    {
        this->width=width;
    }

    int GetHeight()
    {
        return height;
    }

    void SetHeight(int height)
    {
        this->height=height;
    }
};

Box operator++ (Box& box)
{
    box.SetHeight(box.GetHeight()+1);
    box.SetWidth(box.GetWidth()+1);
    return box;
}

Box operator+ (Box& first, Box& second)
{
    Box box(first.GetWidth()+second.GetWidth(), first.GetHeight()+second.GetHeight());
    return box;
}

operator<<(std::ostream& out, Box box)
{
    out<<"Width: "<<box.GetWidth()<<"\nHeight: "<<box.GetHeight();
}

void Test_Box()
{
    srand(time(0));
    int size;
    std::cout<<"Enter size: "<<std::endl;
    std::cin>>size;
    Box** boxes=new Box*[size];
    for(int i=0;i<size;i++)
    {
        int length=rand()%20;
        boxes[i]=new Box[length];
        std::cout<<static_cast<char>(65+i)<<": "<<std::endl;
        for(int j=0;j<length;j++)
        {
            std::cout<<(boxes[i][j]=Box(rand()%100, rand()%100));
            std::cout<<"\n\n";
        }
        std::cout<<std::endl;
    }
}

int main(void)
{
    Test_Box();
    return 0;
}