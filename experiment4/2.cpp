#include<iostream>
#include<stdio.h>
using namespace std;
void f(double a,double b,double c,double d)
{
    double s=a-c,t=b-d;
    printf("%.2f %.2f",s,t);
}
int main(){
    double a,b,c,d;
    cin>>a>>b>>c>>d;
    f(a,b,c,d);
}