/*
Ҫ��

1������˽�г�Ա�ꡢ�¡��ա�Сʱ���֡��롣

2����ʹ�ù��캯��ʵ�ֵ���ĳ�ʼ�����������ж����ں�ʱ�����Ч�ԡ�������ʱ����Ӧ������ȷ�ķ�Χ�ڡ���������ʱ����·ݵ������ʱ��ĸ�ʽ��xx:xx:xx,Сʱ���ǳ���23�����Ӻ��벻�ܳ���59��

      1�����������Ч������� ��date error! ��  �����ꡢ�¡��ա�Сʱ���֡�����Ϊ0��

      2�����ʱ����Ч������� ��time error! ��  �����ꡢ�¡��ա�Сʱ���֡�����Ϊ0��

      3��������ں�ʱ�䶼��Ч������ݴ��ݵĲ�����ʼ���ꡢ�¡��ա�Сʱ���֡��롣

      4�����캯��������������Сʱ���֡��� ���ΪĬ���γɣ���Ĭ��ֵΪ0��

      5)  ���"���캯��������"

3�������һ���������캯����ʵ�ֽ�������ֵȫ�����ݸ���ǰ����ͬʱ������������캯�������á�

4�������һ������������ͬʱ������������������á�

5�����һ����Ա����  int dayDiff(CTime t) �����ڼ��㵱ǰ�������β�t֮��������������ע���������Ϊ���ڵ���0����������ע����������⡣

6�����һ����Ա���� showTime()��������ʾ���ڣ���ʾ��ʽΪ��2020/3/12 11:50:20



��ʾ�������ϴ�Ҫ��ĳ�Ա�����⣬��������������Ҫ�ĳ�Ա������

main�����Ѿ��������벹ȫ�������롣
*/
#include<iostream>
#include<cstdlib>
using namespace std;
class CTime{
    public :
        CTime(int y,int m,int d,int h=0,int minute=0,int s=0);//���캯��
        CTime(CTime &T){
            year = T.year;
            month = T.month;
            day = T.day;
            hour = T.hour;
            minute = T.minute ;
            second = T.second;
            cout<<"�������캯��������"<<endl;
        }
        void showTime();//��ʾ��ʽΪ��2020/3/12 11:50:20
        int dayDiff(CTime t);//�����������
        bool isvalid();//����Ƿ�Ϸ�
        ~CTime()
        {
            cout<<"��������������"<<endl;
        }
    private :
        int year,month,day,hour,minute,second;
        int isValid1=1,isValid2=1;//�ֱ��¼������ʱ��Ĵ������;
};
CTime::CTime(int y,int m,int d,int h,int min,int s)
{
    year = y;
    month = m;
    day = d;
    hour = h;
    minute = min ;
    second = s ;
    if(month>12||month<1){//�·ݲ��Ϸ�
        isValid1 = 0;//���ڴ���
    }
    if(month == 2)//�����������
    {
        if(((year%4==0&&year%100!=0)||year%400==0)||year%400==0)//����,4�ı���,����100�ı���
        {
            if(day<0||day>29)//1-29�źϷ�
            {
                isValid1 = 0;
            }
        }
        else if(day<0||day>28)//������
        {
            isValid1 = 0;
        }
    }
    else if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)//31����·�
    {
        if(day<0||day>31)
        isValid1=0;
    }
    else{
        if(day<0||day>30)
        isValid1 = 0;
    }
    //����ʱ��
    if(hour>=24||hour<0)
    isValid2 = 0;
    if(minute < 0||minute > 59)
    isValid2 = 0;
    if(second < 0||second > 59)
    isValid2 = 0;
    //���
    if(!isValid1&&isValid2)//date error!
    {
        cout<<"date error!"<<endl ;
        year = 0;
        month = 0;
        day = 0;
        hour = 0;
        minute = 0;
        second = 0;
    }
    if(!isValid2&&isValid1)
    {
        cout<<"time error!"<<endl;
        year = 0;
        month = 0;
        day = 0;
        hour = 0;
        minute = 0;
        second = 0;
    }
    if(!isValid1&&!isValid2)
    {
        cout<<"date and time error!"<<endl;
        year = 0;
        month = 0;
        day = 0;
        hour = 0;
        minute = 0;
        second = 0;
    }
    cout<<"���캯��������"<<endl;
}
void CTime::showTime()//��ʾ��ʽΪ��2020/3/12 11:50:20
{
    cout<<year<<'/'<<month<<'/'<<day<<" "<<hour<<":"<<minute<<":"<<second<<endl;
}
int CTime::dayDiff(CTime t)//�����������
{
    int days=0;
    if(year>t.year)
    {
        for(int y=t.year+1;y<year;y++)
        {
            if((y%4==0&&y%100!=0)||y%400==0)
            {
                days+=366;
            }
            else days+=365;
        }
        //��ֹ���������
        for(int i=1;i<month;i++)
        {
            if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)
            {
                days+=31;
            }
            else if(i==2)
            {
                if(((year%4==0&&year%100!=0)||year%400==0)||year%400==0)
                days+=29;
                else days+=29;
            }
            else days+=30;
        }
        days+=day;
        //��ʼ���������
        if((t.year%4==0&&t.year%100!=0)||t.year%400==0)//����
        {
            days+=366;
        }
        else
        {
            days+=365;
        }
        for(int i=1;i<t.month;i++)
        {
            if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)
            {
                days-=31;
            }
            else if(i==2)
            {
                if((t.year%4==0&&t.year%100!=0)||t.year%400==0)
                days-=29;
                else days-=29;
            }
            else days-=30;
        }
        days-=t.day;
    }
    else if(year<t.year)
    {
        for(int y=year+1;y<t.year;y++)
        {
            if((y%4==0&&y%100!=0)||y%400==0)
            {
                days+=366;
            }
            else days+=365;
        }
        //��ֹ���������
        for(int i=1;i<t.month;i++)
        {
            if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)
            {
                days+=31;
            }
            else if(i==2)
            {
                if((t.year%4==0&&t.year%100!=0)||t.year%400==0)
                days+=29;
                else days+=28;
            }
            else days+=30;
        }
        days+=t.day;
        //��ʼ���������
        if(((year%4==0&&year%100!=0)||year%400==0)||year%400==0)//����
        {
            days+=366;
        }
        else
        {
            days+=365;
        }
        for(int i=1;i<month;i++)
        {
            if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)
            {
                days-=31;
            }
            else if(i==2)
            {
                if(((year%4==0&&year%100!=0)||year%400==0)||year%400==0)
                days-=29;
                else days-=29;
            }
            else days-=30;
        }
        days-=day;
    }
    else{//ͬһ���
        if(month<t.month)
        {
            for(int i=month+1;i<t.month;i++)
            {
                if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)
                {
                    days+=31;
                }
                else if(i==2)
                {
                    if(((year%4==0&&year%100!=0)||year%400==0)||year%400==0)
                    days+=29;
                    else days+=28;
                }
                else days+=30;
            }
            //��ʼ�·�
            if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
            days+=31-day;
            else if(month==2)
            {
                if(((year%4==0&&year%100!=0)||year%400==0)||year%400==0)
                {
                    days+=29-day;
                }
                else days+=28-day;
            }
            else days+=30-day;
            //��ֹ�·�
            days+=t.day;
        }//end month<t.month
        if(month==t.month)
        {
            days+=(int)abs(day-t.day);
        }
        if(month>t.month)
        {
            for(int i=t.month+1;i<month;i++)
            {
                if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)
                {
                    days+=31;
                }
                else if(i==2)
                {
                    if((year%4==0&&year%100!=0)||year%400==0)
                    days+=29;
                    else days+=28;
                }
                else days+=30;
            }
            //��ʼ�·�
            if(t.month==1||t.month==3||t.month==5||t.month==7||t.month==8||t.month==10||t.month==12)
            days+=31-t.day;
            else if(t.month==2)
            {
                if((year%4==0&&year%100!=0)||year%400==0)
                {
                    days+=29-t.day;
                }
                else days+=28-t.day;
            }
            else days+=30-t.day;
            //��ֹ�·�
            days+=day;
        }
    }//ͬһ���
    return days;
}
bool CTime::isvalid()//����Ƿ�Ϸ�
{
    if(isValid1&&isValid2)
    return 1;
    else return 0;
}
int  main()
{
        int  year,  month,  day,  hour,  minute,  second;
        cin  >>  year  >>  month  >>  day  >>  hour  >>  minute  >>  second;
        CTime  t1(year,  month,  day,  hour,  minute,  second);
        t1.showTime();
        CTime  t2(2000,  1,  1);  //����Ĭ���βν�ʱ���ʼ��Ϊ00:00:00
        if  (t1.isvalid())          //������ں�ʱ��Ϸ������������
        {
                int  days=0;
                days=t1.dayDiff(t2);
                cout  <<  "������֮�������"  <<  days  <<  "��"  <<  endl;
                days=t2.dayDiff(t1);
                cout  <<  "������֮�������"  <<  days  <<  "��"  <<  endl;
        }
}