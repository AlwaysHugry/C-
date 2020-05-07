/*
ĳ����ʹ��һ��Բ���ε���Ͱ������ɫ���ͣ����ǹ��ڸ���Ͱ�������Ѿ�ģ�������ڹ����ǲ������Ͱֱ���͸ߣ��ɼ������룩����﹤���Ǽ���һ����Ͱ�������������Ͱ��Ҫ����Ƥ�����

ע�������Ͱ���иǵġ���Ƥ�ĺ�Ⱥ��Բ��ơ�

�����һ����cylinder���������˽�г�Ա r��h��r��ʾ�뾶��h��ʾ�ߡ����໹��3�����г�Ա������ݸ����Ĵ��벿�֣���������ƹ��к�����
*/
#include  <iostream>
#include<iomanip>
#include  <cmath>
using  namespace  std;

const  double  PI=3.1415926;
//���ڴ˴�����������
class Cylinder{
    public :
        void init(double a,double b);
        double getvolumn();
        double getarea();
    private :
        double r;
        double h;
};
void Cylinder::init(double a,double b)
{
    h = a;
    r = b;
}
double Cylinder::getvolumn()
{
    return r*r*PI*h;
}
double Cylinder::getarea()
{
    return 2*PI*r*(r+h);
}

int  main()
{
        double  d,h;
        cin>>d>>h;
        Cylinder can;
        can.init(h,d/2);
        cout<<fixed<<setprecision(6);
        cout<<"��Ͱ���ݻ���"<<can.getvolumn()<<"  "<<endl;
        cout<<"��Ƥ�������"<<can.getarea()<<endl;
}