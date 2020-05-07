#include<iostream>
using namespace std;
class Point{
    public :
       Point(int x=0,int y=0):x(x),y(y){//初始化
           count++;//所有对象维护一个成员
       }
       Point(Point &p):x(p.x),y(p.y)//copy构造函数
       {
           count++;
       }
       ~Point(){
           count--;
       }//析构函数
       int getX()
       {
           return x;
       }
       int getY()
       {
           return y;
       }
       static void showCount()//静态函数成员
       {
           cout<<"Object count="<<count<<endl;
           //访问动态数据成员,必须通过对象
       }

    private :
       int x,y;
       static int count;//生命讲台数据成员
};
int Point::count = 0;//定义并初始化
int  main()
{
    Point A(4,5);
    cout<<"Point A:"<<A.getX()<<","<<A.getY();
    A.showCount();

    Point B(A);
    cout<<"Point A:"<<A.getX()<<","<<A.getY();
    Point::showCount();//调用静态函数成员

    return 0;
}