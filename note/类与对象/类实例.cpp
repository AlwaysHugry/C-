#include<iostream>
using namespace std;
class Clock{
    public://�����Է����������ӿ�
        void setTime(int newH,int newM,int newS);
        void setTime();
        void showTime();
    private://˽������,������������
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
    Clock s = Clock(myclock);//�����ĸ��ƹ��캯��
    s.showTime();
    return 0;
}