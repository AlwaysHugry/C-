/*
����Boat��Car�����࣬���߶���˽�г�Աweight���ԣ��������ߵ�һ����Ա����totalweight(),����������Ķ���������͡�

����ݸ�����main������totalweight()�����Ķ��壬����Boat��Car�����ࡣ
*/
#include  <iostream>
using  namespace  std;
//�������ﲹ����Boat��Car�Ķ���
class Boat{
    public :
       Boat(int w)
       {
           weight = w;
       }
       int weight ;
};
class Car{
    public :
       Car(int w)
       {
           weight = w;
       }
       int weight ;
};
int  totalweight(Boat&  b,Car&  c)
{
        return  b.weight+c.weight;
}
int  main()
{
        Boat  b(100);
        Car  c(200);
        cout<<totalweight(  b,  c)<<endl;
        return  0;
}