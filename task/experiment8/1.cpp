/*
  ��дCStudent�࣬�������������飬��������Ĵ������ͷŹ����й��캯�������������ĵ��á�

����Ҫ��

1��CStudent���������˽�г�Ա������������

2��CStudent�����һ����̬���ݳ�Աcount���ڶ��󱻴���ʱ�Զ���1���ڶ����ͷ�ʱ�Զ���1

3���ڹ��캯�������"*** is contructing", �����������������*** is destructing��

4�������main���������������ܣ������CStudent������

5���������������Ķ��󴴽����ͷŵ�ԭ��
*/
#include  <iostream>
#include  <string>
using  namespace  std;

class  CStudent
{
    public :
       CStudent(){
           count ++;
           cout<<name<<" is contructing"<<endl;
       }
       CStudent(string h,int m):name(h),age(m){
           count ++;
           cout<<name<<" is contructing"<<endl;
       }
       ~CStudent(){
           count--;
           cout<<name<<" is destructing"<<endl;
       }
       void printname(){
           cout<<"name:"<<name<<endl;
       }
       static int getcount()
       {
           return count;
       }
    private :
       string name = "noname";
       int age;
       static int count;
};
//���������ʼ��̬��Ա����
int CStudent::count = 0;

int  main()
{
        cout  <<  "������ѧ��"  <<  CStudent::getcount()  <<  endl;
        {
                CStudent  stuB[5];
                stuB[4].printname();
                cout  <<  "������ѧ��"  <<  CStudent::getcount()  <<  endl;
        }
        cout  <<  "������ѧ��"  <<  CStudent::getcount()  <<  endl;
        {
                CStudent  stuA[2]  =  {CStudent("Tom",  3),  CStudent("Jerry",  2)};
                for  (int  i  =  0;  i  <  2;  i++)
                {
                        stuA[i].printname();
                }
                cout  <<  "������ѧ��"  <<  CStudent::getcount()  <<  endl;
        }
        cout  <<  "������ѧ��"  <<  CStudent::getcount()  <<  endl;

        return  0;
}