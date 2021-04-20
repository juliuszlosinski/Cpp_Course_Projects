#include <iostream>
#include <cstdlib>
#include <ctime>

class Point
{
    private:
    int posX;
    int posY;

    public:
    Point(int posX, int posY)
    {
        this->posX=posX;
        this->posY=posY;
    }

    int GetPosX()
    {
        return posX;
    }

    void SetPosX(int posX)
    {
        this->posX=posX;
    }

    int GetPosY()
    {
        return posY;
    }

    void SetPosY(int posY)
    {
        this->posY=posY;
    }
};

int operator++ (Point& point)
{
    point.SetPosX(point.GetPosX()+1);
    point.SetPosY(point.GetPosY()+1);
    return point.GetPosX();
}

Point operator+ (Point& first, Point& second)
{
    return Point(first.GetPosX()+second.GetPosX(),first.GetPosY()+second.GetPosY());
}

Point operator- (Point& first, Point& second)
{
    return Point(first.GetPosX()-second.GetPosX(), first.GetPosY()-second.GetPosY());
}

std::ostream operator<<(std::ostream& out, Point point)
{
    out<<"X: "<<point.GetPosX()<<", Y: "<<point.GetPosY();
}

void Test_Point()
{
    //TODO: Test point using overloading operators.
    int first=100;
    int *data=new int[100];
    for(int i=0;i<100;i++)
    {
        data[i]=i+2;
    }
}

int main(void)
{
    Test_Point();
    return 0;
}