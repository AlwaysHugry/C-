#include<iostream>
using namespace std;
int main()
{
    int n;
    int t=2;
    cin>>n;
    while(n!=1)
    {
        while(n%t==0)
        {
            cout<<t<<" ";
            n/=t;
        }
        t++;
    }
}

