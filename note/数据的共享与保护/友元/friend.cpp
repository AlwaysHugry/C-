#include<iostream>
#include<math.h>
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
    friend float distance(Point &a,Point &b);//声明
    friend class Line;//声明Line是Point的友元
    private :
      int x,y;
};
class Line{
    public :
    Line(Point &a,Point &b):a(a),b(b){}
    float showDistance()
    {
        double x = a.x -b.x;//可以访问Point类的private成员
        double y = a.y - b.y;
        return (float)sqrt(x*x+y*y);
    }
    private :
    Point a,b;
};
float distance(Point &a,Point &b){//友元函数
    double x = a.x -b.x;//可以访问Point类的private成员
    double y = a.y - b.y;
    return (float)sqrt(x*x+y*y);
}
int main()
{
    Point a(1,2);
    Point b(3,4);
    cout<<distance(a,b)<<endl;
    Line t(a,b);
    cout<<t.showDistance();
}
