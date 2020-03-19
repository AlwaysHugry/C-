#include<iostream>
using namespace std;

int main()
{
    double x=1/5.0;
    double sqr=x*x;
    double e=x;
    double r=0;
    int i=1;
    while(e/i>1e-15)
    {
        double f=e/i;
        r=(i%4==1)?r+f:r-f;
        e=e*sqr;
        i+=2;
    }
    cout<<i;
}