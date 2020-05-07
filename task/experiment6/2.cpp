/*
某工厂使用一种圆柱形的铁桶来运输色拉油，但是关于该油桶的容量已经模糊，现在工人们测得了油桶直径和高（由键盘输入），请帮工人们计算一下油桶容量和制造该油桶需要的铁皮面积。

注意这个油桶是有盖的。铁皮的厚度忽略不计。

请设计一个类cylinder，该类具有私有成员 r和h，r表示半径，h表示高。该类还有3个公有成员，请根据给出的代码部分，分析并设计公有函数。
*/
#include  <iostream>
#include<iomanip>
#include  <cmath>
using  namespace  std;

const  double  PI=3.1415926;
//请在此处完善类的设计
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
        cout<<"油桶的容积是"<<can.getvolumn()<<"  "<<endl;
        cout<<"铁皮的面积是"<<can.getarea()<<endl;
}