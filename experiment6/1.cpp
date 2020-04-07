/*
要求：

1、包括私有成员年、月、日、小时、分、秒。

2、请使用构造函数实现的类的初始化工作，并判断日期和时间的有效性。年月日时分秒应该在正确的范围内。考虑闰年时候二月份的情况。时间的格式是xx:xx:xx,小时不是超过23，分钟和秒不能超过59。

      1）如果日期无效，则输出 “date error! ”  并将年、月、日、小时、分、秒置为0。

      2）如果时间无效，则输出 “time error! ”  并将年、月、日、小时、分、秒置为0。

      3）如果日期和时间都有效，则根据传递的参数初始化年、月、日、小时、分、秒。

      4）构造函数的三个参数：小时、分、秒 设计为默认形成，其默认值为0。

      5)  输出"构造函数被调用"

3、请设计一个拷贝构造函数，实现将参数的值全部传递给当前对象，同时输出“拷贝构造函数被调用”

4、请设计一个析构函数，同时输出“析构函数被调用”

5、设计一个成员函数  int dayDiff(CTime t) ，用于计算当前对象与形参t之间的相隔的天数，注意相隔天数为大于等于0的正整数。注意闰年的问题。

6、设计一个成员函数 showTime()，用于显示日期，显示格式为：2020/3/12 11:50:20



提示：除了上传要求的成员函数外，你可以自由添加需要的成员函数。

main函数已经给定，请补全其他代码。
*/
#include<iostream>
#include<cstdlib>
using namespace std;
class CTime{
    public :
        CTime(int y,int m,int d,int h=0,int minute=0,int s=0);//构造函数
        CTime(CTime &T){
            year = T.year;
            month = T.month;
            day = T.day;
            hour = T.hour;
            minute = T.minute ;
            second = T.second;
            cout<<"拷贝构造函数被调用"<<endl;
        }
        void showTime();//显示格式为：2020/3/12 11:50:20
        int dayDiff(CTime t);//返回相隔天数
        bool isvalid();//检测是否合法
        ~CTime()
        {
            cout<<"析构函数被调用"<<endl;
        }
    private :
        int year,month,day,hour,minute,second;
        int isValid1=1,isValid2=1;//分别记录日期与时间的错误与否;
};
CTime::CTime(int y,int m,int d,int h,int min,int s)
{
    year = y;
    month = m;
    day = d;
    hour = h;
    minute = min ;
    second = s ;
    if(month>12||month<1){//月份不合法
        isValid1 = 0;//日期错误
    }
    if(month == 2)//考虑特殊二月
    {
        if(((year%4==0&&year%100!=0)||year%400==0)||year%400==0)//闰年,4的倍数,不是100的倍数
        {
            if(day<0||day>29)//1-29号合法
            {
                isValid1 = 0;
            }
        }
        else if(day<0||day>28)//非闰年
        {
            isValid1 = 0;
        }
    }
    else if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)//31天的月份
    {
        if(day<0||day>31)
        isValid1=0;
    }
    else{
        if(day<0||day>30)
        isValid1 = 0;
    }
    //考虑时间
    if(hour>=24||hour<0)
    isValid2 = 0;
    if(minute < 0||minute > 59)
    isValid2 = 0;
    if(second < 0||second > 59)
    isValid2 = 0;
    //检查
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
    cout<<"构造函数被调用"<<endl;
}
void CTime::showTime()//显示格式为：2020/3/12 11:50:20
{
    cout<<year<<'/'<<month<<'/'<<day<<" "<<hour<<":"<<minute<<":"<<second<<endl;
}
int CTime::dayDiff(CTime t)//返回相隔天数
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
        //终止年过的天数
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
        //起始年过的日子
        if((t.year%4==0&&t.year%100!=0)||t.year%400==0)//闰年
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
        //终止年过的天数
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
        //起始年过的日子
        if(((year%4==0&&year%100!=0)||year%400==0)||year%400==0)//闰年
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
    else{//同一年份
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
            //起始月份
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
            //终止月份
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
            //起始月份
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
            //终止月份
            days+=day;
        }
    }//同一年分
    return days;
}
bool CTime::isvalid()//检测是否合法
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
        CTime  t2(2000,  1,  1);  //利用默认形参将时间初始化为00:00:00
        if  (t1.isvalid())          //如果日期和时间合法，则计算天数
        {
                int  days=0;
                days=t1.dayDiff(t2);
                cout  <<  "这两天之间相隔了"  <<  days  <<  "天"  <<  endl;
                days=t2.dayDiff(t1);
                cout  <<  "这两天之间相隔了"  <<  days  <<  "天"  <<  endl;
        }
}