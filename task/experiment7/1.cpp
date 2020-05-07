#include  <iostream>
#include<iomanip>
#include  <cmath>
using  namespace  std;

const  double  PI=3.1415926;
//���ڴ˴�����������
class Cylinder{
    public :
        Cylinder(double a,double b);
        double getvolumn(); 
        double getarea();
        ~Cylinder()
        {
            cout<<"析构函数被调用"<<endl;
        }
    private :
        double r;
        double h;
};
Cylinder::Cylinder(double a,double b)
{
    h = a;
    r = b;
    cout<<"构造函数被调用"<<endl;
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
        Cylinder can(h,d/2);
        cout<<fixed<<setprecision(6);
        cout<<"油桶的容积是"<<can.getvolumn()<<"  "<<endl;
        cout<<"铁皮的面积是"<<can.getarea()<<endl;
}