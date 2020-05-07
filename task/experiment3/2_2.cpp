#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    char s[100];//存放输入的字符串
    int n;//输出次数
    int t=0;
    int w[100];//存放AscII值
    cin>>n;
    cin>>s;
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        w[t++]=s[i];
        if(s[i]>='a'&&s[i]<='z')
        w[t++]=s[i]+'A'-'a';
        if(s[i]>='A'&&s[i]<='Z')
        w[t++]=s[i]+'a'-'A';
    }
    sort(w,w+t);
    for(int i=0;i<n;i++)
    for(int j=t-1;j>=0;j--)
    {
        if(j!=t-1&&w[j]!=w[j+1])
        cout<<(char)w[j];
        else if(j==t-1)
        cout<<(char)w[j];
    }
}