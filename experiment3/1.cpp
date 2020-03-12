#include<iostream>
using namespace std;


int main()
{ 
    struct time
   {
    int year,month,day,hour,minute,second;
    bool data,time_1;
    };
    time s;
    cin>>s.year>>s.month>>s.day>>s.hour>>s.minute>>s.second;

     if(s.year>0) s.data=1;
    else s.data=0;
    if(s.month>=1&&s.month<=12) s.data=1;
    else s.data=0;
    if(s.data==1){
        if(s.month==1||s.month==3||s.month==5||s.month==7||s.month==8||s.month==10||s.month==12)
        {
            if(s.day>=1&&s.day<=31)
            s.data=1;
            else s.data=0;
        }
        else if(s.month==2)
        {
            if(s.year%4||(s.year%100==0&&s.year%400!=0))
            {
                if(s.day>=1&&s.day<=28)
                s.data=1;
                else s.data=0;
            }
            else{
                if(s.day>=1&&s.day<=29)
                s.data=1;
                else s.data=0;
            }
        }
        else{
            if(s.day>=1&&s.day<=30)
            s.data=1;
            else s.data=0;
        }
    }
    s.time_1=0;
    if(s.hour>=0&&s.hour<24) 
    if(s.minute>=0&&s.minute<=59) 
    if(s.second>=0&&s.second<=59)
    {
        s.time_1=1;
    }
    if(s.data&&s.time_1)
    {
        cout<<s.year<<'/'<<s.month<<'/'<<s.day<<" "<<s.hour<<":";
        if(s.minute<10)
        cout<<"0";
        cout<<s.minute<<":"<<s.second;
        }
    else if(s.data==1&&s.time_1==0)
    cout<<"time error!";
    else if(s.data==0&&s.time_1==1)
    cout<<"date error!";
    else cout<<"date and time error!";
}
