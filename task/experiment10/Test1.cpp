#include <iostream>
using namespace std;
const float pi = 3.14159;
/*
 *shape类有以下成员

 *1）私有成员m_ID

 *2）公有getter和setter

 *3）计算面积函数getArea()，返回0;

 *4）构造与析构函数
*/
class Shape
{
private:
    int m_ID;

public:
    Shape(int n);
    Shape() {cout<<"Shape default constructor called."<<endl;}
    void SetId(int id);
    int GetId();
    double getArea()
    {
        return 0;
    }
    ~Shape(){
        cout<<"Shape destructor called:"<<m_ID<<endl;
    };
};
Shape::Shape(int n)
{
    m_ID = n;
    cout<<"Shape constructor called:"<<n<<endl;
}
void Shape::SetId(int id)
{
    m_ID = id;
}
int Shape::GetId()
{
    return m_ID;
}
/*
Circle类从shape类继承，并派生以下成员

1）私有成员r

2）公有getter和setter

3）计算面积函数getArea()，返回计算面积;

4）构造与析构函数
*/
class Circle : public Shape
{
private:
    int r;

public:
    Circle();
    Circle(int a, int b);
    void SetR(int r);
    int GetR();
    double getArea();
    ~Circle();
};
Circle::Circle():Shape()
{
    cout<<"Circle default constructor called."<<endl;
}
Circle::Circle(int a,int b):Shape(b)
{
    r = a;
    cout<<"Circle constructor called:"<<b<<endl;
}
void Circle::SetR(int r){
    this->r = r;
}
int Circle::GetR()
{
    return r;
}
double Circle::getArea()
{
    return pi*r*r;
}
Circle::~Circle()
{
    cout<<"Circle destructor called:"<<GetId()<<endl;
}
/*
Rectangle类从shape类继承，并派生以下成员

1）私有成员h,w

2）公有getter和setter

3）计算面积函数getArea()，返回计算面积;

4）构造与析构函数
*/
class Rectangle:public Shape{
    private :
    int h,w;
    public :
    Rectangle();
    Rectangle(int a,int b,int c);//a->h,b->w,c->r
    void SetH(int h);
    void SetW(int w);
    int GetH();
    int GetW();
    double getArea();
    ~Rectangle();
};
Rectangle::Rectangle()
{
    cout<<"Rectangle default constructor called."<<endl;
}
Rectangle::Rectangle(int a,int b,int c):Shape(c)
{
    SetH(a);
    SetW(b);
    cout<<"Rectangle constructor called:"<<c<<endl;
}
void Rectangle::SetH(int h)
{
    this->h = h;
}
void Rectangle::SetW(int w)
{
    this->w  = w;
}
int Rectangle::GetH()
{
    return h;
}
int Rectangle::GetW()
{
    return w;
}
double Rectangle::getArea()
{
    return h*w;
}
Rectangle::~Rectangle()
{
    cout<<"Rectangle destructor called:"<<GetId()<<endl;
}
int main()
{
    Shape s(1);           //1表示ID
    Circle c(4, 2);       //4表示半径，2表示ID
    Rectangle r(4, 5, 3); //4和5表示长和宽，3表示ID
    cout << "Shape的面积" << s.getArea() << endl;
    cout << "Circle的面积" << c.getArea() << endl;
    cout << "Rectangle的面积" << r.getArea() << endl;
}