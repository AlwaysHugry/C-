#include<iostream>
using namespace std;
int main()
{
    int year,month;
    cin>>year>>month;
    if((year>=0&&year<=10000)&&(month>=1&&month<=12))
    {
        if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
        {
            cout<<31;
        }
        else if(month==2)
        {
            if(year%4||(year%100==0&&year%400!=0))
            {
                cout<<28;
            }
            else{
                cout<<29;
            }
        }
        else{
            cout<<30;
        }
    }
    else cout<<"Error!";
}