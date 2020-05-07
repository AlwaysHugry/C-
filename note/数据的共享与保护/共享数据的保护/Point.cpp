#include<iostream>
#include<cmath>
using namespace std;
class Point{
    public :
      Point(int x=0,int y=0):x(x),y(y){}
      int getX()
      {
        return x;
      }
      int getY()
      {
        return y;
      }
      friend float distance(const Point &a,const Point &b); 
    private :
      int x,y;
};
float distance(const Point &a,const Point &b)
{
    double x = a.x -b.x;//可以访问Point类的常函数成员
    double y = a.y - b.y;
    return (float)sqrt(x*x+y*y);
}
int main()
{
    Point a(1,2);
    Point b(3,4);
    cout<<distance(a,b)<<endl;
}