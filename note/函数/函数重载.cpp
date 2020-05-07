#include<iostream>
using namespace std;
int sumSquare(int a,int b)
{
    return a*a+b*b;
}
float sumSquare(float a,float b){
    return a*a+b*b;
}
int main()
{
    int a,b;
    cout<<"Enter a = ";
    cin>>a;
    cout<<"b = ";
    cin>>b;
    cout<<sumSquare(a,b)<<endl;
    float u,v;
    cout<<"Enter u = ";
    cin>>u;
    cout<<"v = ";
    cin>>v;
    cout<<sumSquare(u,v);
}
 