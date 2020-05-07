#include<iostream>
using namespace std;
double getSize(double width=1.2,double height=5.0,int length=3.5);
int main()
{
    double w,l,h;
    cin>>w>>l>>h;
    cout<<getSize(w,h,l)<<endl;
    cout<<"Ä¬ÈÏÖµ:"<<getSize();
    return 0;
}
double getSize(double width/*=1.2*/,double height/*=5.0*/,int length/*=3.5*/)
{
    return width*length*height;
}