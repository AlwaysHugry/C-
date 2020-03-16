#include<iostream>
#include<string.h>
using namespace std;
int len=0;// 记录回文序列的长度
char s[10005];//用以记录输入的字符串
int f(int t)//第一种回文情况,acca,t为c的位置
{
    int num=0;
    while(s[t-num]==s[t+num+1]&&t-num>=0&&s[t+num+1]!='\0'){
        num++;
    }
    return num;
}
int p(int t)
{
    int num=0;
    while(s[t-num]==s[t+num]&&t-num>=0&&s[t+num]!='\0'){
        num++;
    }
    return num-1;
}
int main()
{
    int begin=0,end=0;
    cin>>s;
    for(int i=0;i<strlen(s);i++){
        if(s[i]==s[i+1])
        {
           int k=f(i);
           if(2*k>len)
           {
               len=k*2;
               begin=i-k+1;
               end=i+k;
           }
        }
        if(s[i-1]==s[i+1])
        {
            int k=p(i);
           if(2*k>len)
           {
               len=k*2+1;
               begin=i-k;
               end=i+k;
           }
        }
    }
    if(len==0)cout<<len;
    else {
        cout<<len<<endl;
        for(int i=begin;i<=end;i++)
        cout<<s[i];
    }
}
