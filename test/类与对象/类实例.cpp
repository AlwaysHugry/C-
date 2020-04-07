#include<iostream>
using namespace std;
class Clock{
    public://外界可以访问这两个接口
        void setTime(int newH,int newM,int newS);
        void setTime();
        void showTime();
    private://私有数据,不允许外界访问
        int hour,minute,second;
};
void Clock::setTime(int newH,int newM,int newS)
{
    hour = newH;
    minute = newM;
    second = newS;
}
inline void Clock::setTime()
{
    hour = 0;
    minute = 0;
    second = 0;
} 
inline void Clock::showTime()
{
    cout<<hour<<":"<<minute<<":"<<second<<endl;
}
int main()
{
    Clock myclock;
    myclock.setTime();
    myclock.showTime();
    myclock.setTime(15,4,12);
    myclock.showTime();
    Clock s = Clock(myclock);//隐含的复制构造函数
    s.showTime();
    return 0;
}