#include<iostream>
using namespace std;
int ans=0;//��¼�ܹ����ƿ��
void buy(int money,int number1,int number2)//ʣ���Ǯ,ƿ����,ƿ����
{
    int add=0;
    add+=money;
    add+=number1/3;
    number1=number1%3;
    add+=number2/2;
    number2%=2;
    number1+=add;
    number2+=add;
    ans+=add;
    if(number1>=3||number2>=2)
    buy(0,number1,number2);
}
int main()
{
    int money;
    cin>>money;
    buy(money,0,0);
    cout<<ans;
}