#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;
int a[30],b[30];//分别用来存储大写字母与小写字母
int num1=0,num2=0;
int main()
{
    char str1[100],str2[100];
    cin>>str1>>str2;
    for(int i=0;i<strlen(str1);i++)
    {
        int k=str1[i];
        if(k>='a'&&k<='z')
        {
            a[num1++]=k-'a';
        }
        else{
            a[num1++]=k-'A';
        }
    }
    for(int i=0;i<strlen(str2);i++)
    {
        int k=str2[i];
        if(k>='a'&&k<='z')
        {
            b[num2++]=k-'a';
        }
        else{
            b[num2++]=k-'A';
        }
    }
    int min=abs(a[0]-b[0]);
    for(int i=0;i<num1;i++)
    {
        for(int j=0;j<num2;j++)
        {
            if(min>abs(a[i]-b[j]))
            {
                min=abs(a[i]-b[j]);
            }
        }
    }
    cout<<min;
}