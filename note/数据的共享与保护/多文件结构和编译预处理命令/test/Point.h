//point����
#include<iostream>
using namespace std;
class Point{
    public :
       Point(int x=0,int y=0):x(x),y(y){//��ʼ��
           count++;//���ж���ά��һ����Ա
       }
       Point(const Point &p);//copy���캯��
       ~Point(){
           count--;
       }//��������
       int getX()
       {
           return x;
       }
       int getY()
       {
           return y;
       }
       static void showCount()//��̬������Ա
       {
           cout<<"Object count="<<count<<endl;
           //���ʶ�̬���ݳ�Ա,����ͨ������
       }

    private :
       int x,y;
       static int count;//������̬���ݳ�Ա
};