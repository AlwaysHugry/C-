/*
设计一个CRectangle类，其中包括CPoint类的两个对象成员，表示左上角和右下角的两个点。要求求解矩形的面积。

注意，每个类的构造函数、拷贝构造函数需要输出“*** is called”,具体的请根据输出进行分析。
*/
#include  <iostream>
using  namespace  std;
//请在这里补充CPoint，CRectangle类的定义
class CPoint{
    public :
       CPoint(int xx,int yy)
       {
           x = xx;
           y = yy;
           cout<<"	CPoint contstructor with default value(0,0) is called."<<endl;
       }
       CPoint(){
           cout<<"	CPoint contstructor with default value(0,0) is called."<<endl;
       }
       CPoint(CPoint &t)
       {
           x = t.x;
           y = t.y;
           cout<<"CPoint copy contstructor is called."<<endl;
       }
       int getX()
       {
           return x;
       }
       int getY()
       {
           return  y;
       }
    private :
       int x=0,y=0;
};
class CRectangle{
    public :
       CRectangle(CPoint c,CPoint d):a(c),b(d)
       {
           cout<<"CRectangle contstructor with (CPoint,CPoint) is called."<<endl;
       }
       CRectangle():a(),b()
       {
           cout<<"CRectangle default contstructor is called."<<endl;
       }
       CRectangle(int x1,int y1,int x2,int y2):a(x1,y1),b(x2,y2)
       {
           cout<<"CRectangle contstructor with (int,int,int,int) is called."<<endl;
       }
       CRectangle(CRectangle &t):a(t.a),b(t.b)
       {
           cout<<"CRectangle copy contstructor is called."<<endl;
       }
       int GetArea()
       {
           return abs(a.getX()-b.getX())*abs(a.getY()-b.getY());
       }
       private :
       CPoint a,b;
};

int  main()
{
        int  a=1,  b=1,  c=6,  d=11;
        cout<<"#  Define  p1  ######"<<endl;
        CPoint  p1;
        cout<<"#  Define  p2  ######"<<endl;
        CPoint  p2(10,20);
        cout<<"#  Define  rect1  ######"<<endl;
        CRectangle  rect1;
        cout<<"#  Define  rect2  ######"<<endl;
        CRectangle  rect2(p1,  p2);
        cout<<"#  Define  rect3  ######"<<endl;
        CRectangle  rect3(a,  b,  c,  d);
        cout<<"#  Define  rect4  ######"<<endl;
        CRectangle  rect4(rect2);
        cout<<"#  Calculate  area  ######"<<endl;
        cout  <<  "rect1面积为"  <<  rect1.GetArea()  <<  endl;
        cout  <<  "rect2面积为"  <<  rect2.GetArea()  <<  endl;
        cout  <<  "rect3面积为"  <<  rect3.GetArea()  <<  endl;
        cout  <<  "rect4面积为"  <<  rect4.GetArea()  <<  endl;
        system("pause");
        return  0;
}