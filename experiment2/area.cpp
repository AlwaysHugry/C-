#include<iostream>
using namespace std;
int main()
{
    int type;
    cin>>type;
    switch(type)
    {
        case 1:
        float r;
        cin>>r;
        cout<<3.1416*r*r<<endl;
        break;
        case 2:
        double a,b;
        cin>>a>>b;
        cout<<a*b;
        break;
        case 3:
        double k;
        cin>>k;
        cout<<k*k;
        break;
        case 4:
        double u,v,w;
        cin>>u>>v>>w;
        cout<<(u+v)*w/2.0;
        break;
    }
    return 0;
    
}