#include<iostream>
using namespace std;
int ans=0;
void hanoi(int n,int a,int b,int c)//将n个盘子从a移到c,b做辅助
{
    ans++;
    if(n==1)
    {
        a=0;
        c++;
    }
    else{
        hanoi(n-1,a,c,b);
        a=0;
        c++;
        hanoi(n-1,b,a,c);
    }
}
int main()
{
    int n;
    cin>>n;
    hanoi(n,n,0,0);
    cout<<ans;
}