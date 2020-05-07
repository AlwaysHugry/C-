//类的使用
#include"Point.cpp"//需要导入实现文件
#include<iostream>
using namespace std;

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