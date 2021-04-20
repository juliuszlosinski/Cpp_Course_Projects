#include <iostream>
#include <cstdlib>
#include <ctime>

enum Names{Jack, Back, Rack, Frack};


Names operator++ (Names& name)
{
    name=static_cast<Names>((name+1)%4);
    return name;
}

template<class T> class Point
{
    private:
    T posX;
    T posY;

    public:
    Point(T posX,T posY)
    {
        this->posX=posX;
        this->posY=posY;
    }

    void SetPosX(T posX)
    {
        this->posX=posX;
    }

    void SetPosY(T posY)
    {
        this->posY=posY;
    }

    T GetPosX()
    {
        return posX;
    }
};

template<class T> operator++ (Point<T>& point)
{
    point.SetPosX(point.GetPosX()+1);
}

template<class T> T operator+ (Point<T>& first, Point<T>& second)
{
    return first.GetPosX()+second.GetPosX();
}

template<class T>  operator<< (std::ostream& out, Point<T> point)
{
    out<<point.GetPosX();
}

void Test()
{
    //TODO: Test dynamic allocations.
    srand(time(0));
    Point<int> first(15,10);
    Point<int> second(25,10);
    std::cout<<first+second;
}

int main(void)
{
    //TODO: Perform operations.
    Test();
    return 0;
}