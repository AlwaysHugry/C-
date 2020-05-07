//point定义
#include<iostream>
using namespace std;
class Point{
    public :
       Point(int x=0,int y=0):x(x),y(y){//初始化
           count++;//所有对象维护一个成员
       }
       Point(const Point &p);//copy构造函数
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
       static int count;//声明静态数据成员
};