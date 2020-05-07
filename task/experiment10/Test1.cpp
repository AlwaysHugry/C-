#include <iostream>
using namespace std;
const float pi = 3.14159;
/*
 *shape�������³�Ա

 *1��˽�г�Աm_ID

 *2������getter��setter

 *3�������������getArea()������0;

 *4����������������
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
Circle���shape��̳У����������³�Ա

1��˽�г�Աr

2������getter��setter

3�������������getArea()�����ؼ������;

4����������������
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
Rectangle���shape��̳У����������³�Ա

1��˽�г�Աh,w

2������getter��setter

3�������������getArea()�����ؼ������;

4����������������
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
    Shape s(1);           //1��ʾID
    Circle c(4, 2);       //4��ʾ�뾶��2��ʾID
    Rectangle r(4, 5, 3); //4��5��ʾ���Ϳ�3��ʾID
    cout << "Shape�����" << s.getArea() << endl;
    cout << "Circle�����" << c.getArea() << endl;
    cout << "Rectangle�����" << r.getArea() << endl;
}