//���ʹ��
#include"Point.cpp"//��Ҫ����ʵ���ļ�
#include<iostream>
using namespace std;

int  main()
{
    Point A(4,5);
    cout<<"Point A:"<<A.getX()<<","<<A.getY();
    A.showCount();

    Point B(A);
    cout<<"Point A:"<<A.getX()<<","<<A.getY();
    Point::showCount();//���þ�̬������Ա

    return 0;
}