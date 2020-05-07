#include "iostream"
using namespace std;

/*
����һ������vehicle,��˽�г�Աmaxspeed��weight�����г�Աrun()��stop(),�Լ����������������
*/
class vehicle
{
private:
    int maxspeed;
    int weight;

public:
    vehicle();
    vehicle(int m, int w);
    void run();
    void stop();
    ~vehicle();
};
vehicle::vehicle()
{
    cout<<"vehicle default constuctor."<<endl;
}
vehicle::vehicle(int a,int b)
{
    maxspeed = a;
    weight = b;
    cout<<"vehicle constructor called. maxspeed:"<<maxspeed<<"; weight"<<weight<<endl;
}
void vehicle::run()
{
    cout<<"vehicle run"<<endl;
}
void vehicle::stop()
{
    cout<<"vehicle stop"<<endl;
}
vehicle::~vehicle()
{
    cout<<"vehicle destructor called. maxspeed:"<<maxspeed<<"; weight"<<weight<<endl;
}
//��vehicle����bicycle��motorcar, bicycle��˽�г�Աheight�� motorcar��˽�г�Աseatnum,�Լ����ԵĹ��캯��������������
class bicycle : virtual public vehicle
{
private:
    int height;

public:
    bicycle();
    bicycle(int a,int b,int c);//h->a,maxspeed->b,weight->c
    ~bicycle();
}; 
bicycle::bicycle()
{
    cout<<"bicycle default constuctor called"<<endl;
}
bicycle::bicycle(int a,int b,int c):vehicle(b,c)
{
    height = a;
    cout<<"bicycle constructor called. height:"<<height<<endl;
}
bicycle::~bicycle()
{
    cout<<"bicycle destructor called. height:"<<height<<endl;
}
class motorcar:virtual public vehicle{
    private :
    int seatnum;
    public :
    motorcar();
    motorcar(int a,int b,int c);//seatnum->a,maxspeed->b,weight->c
    ~motorcar();
};
motorcar::motorcar()
{
    cout<<"motorcar default constuctor called"<<endl;
}
motorcar::motorcar(int a,int b,int c):vehicle(b,c)
{
    seatnum = a;
    cout<<"motorcar constructor called. seatnum:"<<seatnum<<endl;
}
motorcar::~motorcar()
{
    cout<<"motorcar destructor called. seatnum:"<<seatnum<<endl;
}
//��bicycle��motorcar������motorcycle���۲������Լ̳е�Ӱ�졣
class motorcycle:public bicycle,public motorcar{
    public :
    motorcycle();
    motorcycle(int a,int b,int c,int d);//1��ʾheight��2��ʾsetnum��3��ʾmaxspeed��4��ʾweight
    ~motorcycle();
};
motorcycle::motorcycle(){
    cout<<"motorcycle default constructor called"<<endl;
}
motorcycle::motorcycle(int a,int b,int c,int d):vehicle(c,d),bicycle(a,c,d),motorcar(b,c,d)
{
    cout<<"motorcycle constructor called"<<endl;
}
motorcycle::~motorcycle()
{
    cout<<"motorcycle destructor called"<<endl;
}
int main(int argc, char *argv[])
{
    motorcycle m(1, 2, 3, 4); //1��ʾheight��2��ʾsetnum��3��ʾmaxspeed��4��ʾweight
    m.run();
    m.stop();
    return 0;
}