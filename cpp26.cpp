#include <iostream>
#include <cmath>

class Vector
{
    private:
    float posX;
    float posY;
    float magnitude;

    public:
    Vector(float posX, float posY):posX(posX),posY(posY)
    {
        magnitude=sqrt(posX*posX+posY*posY);
    }

    Vector operator* (float scalar) const;
    Vector operator/ (float scalar) const;
    Vector operator+ (Vector& vec) const;
    Vector operator- (Vector& vec) const;

    Vector Normalized() const;

    int getLength()
    {
        return magnitude;
    }

    int getLengthSqrt()
    {
        return magnitude*magnitude;
    }

    int getX()
    {
        return posX;
    }

    int getY()
    {
        return posY;
    }
};

Vector Vector::operator+(Vector& vec) const
{
    float X=vec.getX()+posX;
    float Y=vec.getY()+posY;
    return Vector(X,Y);
}

Vector Vector::operator-(Vector& vec) const
{
    float X=posX-vec.getX();
    float Y=posY-vec.getY();
    return Vector(X,Y);
}

Vector Vector::Normalized() const
{
        float length=sqrt(posX*posX+posY*posY);
        float X=posX/length, Y=posY/length;
        return Vector(X,Y);
}

Vector Vector::operator* (float scalar) const
{
    int X=posX*scalar;
    int Y=posY*scalar;
    return Vector(X,Y);
}

Vector Vector::operator/ (float scalar) const
{
    int X=posX/scalar;
    int Y=posY/scalar;
    return Vector(X,Y);
}

class Point
{
    private:
    int posX;
    int posY;

    public:
    Point(int posX,int posY):posX(posX),posY(posY){}
    Point AddVector(Vector v);

    int getX()
    {
        return posX;
    }

    int getY()
    {
        return posY;
    }
};

Point Point::AddVector(Vector v)
{
    int pX=(this->posX+=v.getX());
    int pY=(this->posY+=v.getY());
    return Point(pX,pY);
}

Vector operator- (Point A, Point B)
{
    return Vector(B.getX()-A.getX(),B.getY()-A.getY());
}

std::ostream& operator<<(std::ostream& out, Vector& vec)
{
    out << "X: "<<vec.getX()<<", Y: "<<vec.getY();
    return out;
}

int main(void)
{
    Vector C(5,10), D(10,15);
    return 0;
}