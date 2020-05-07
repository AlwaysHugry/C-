#include<iostream>
using namespace std;
int C(int n,int k)//从n中选出k个的方案
{
    if(n>=k){
        if(k==1) return n;
        else 
        return C(n-1,k-1)+C(n-1,k);
    }
    else return 0;
}
int main()
{
    int n,k;
    cout<<"select ";
    cin>>k;
    cout<<"from ";
    cin>>n;
    cout<<"种数有:"<<C(n,k);
}