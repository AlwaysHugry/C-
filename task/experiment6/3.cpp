/*
有个银行需要开发一个用户管理程序，功能要求如下：

1、记录用户的账号、姓名、性别、年龄、现有金额

2、可以动态管理用户的金额

（1）当用户存钱时将金额添加到现有金额内

  (2）当用户取钱时，从现有账户中扣除

  (3)  如果取钱金额超过现有金额，则拒绝取钱操作。

  (4) 如果录入为100.897元，即为无效输入，应该拒绝操作。原因：录入的数据是以“元”为单位，金额的最小单位是分。请同学们考虑一下，如果能有效应对这类问题。



请根据给定的main函数设计一个Account类实现上述功能。
*/
#include  <iostream>
#include  <iomanip>
using  namespace  std;
//请在此处补充Account类的定义
int check(double n)
{
    int s=0;
    do{
        n*=10;
        s++;
    }while(n!=int(n));
    return s;
}
class Account{
    public :
        void init(string id1,string name1,string sex1,int age1,double money1)
        {
            id = id1;
            name =name1;
            sex = sex1;
            age = age1;
            if(check(money1)>2)
            {
                cout<<"您输入的金额不合法"<<endl;
                money = 0.0;
            }
            else money = money1;
        }
        void printmoney()
        {
            cout<<name<<"的存款为";
            printf("%.2lf",money);
            cout<<endl;
        }    
        void deposit(double add)
        {
            if(check(add)>2)
            {
                cout<<"您输入的金额不合法"<<endl;
            }
            else money+=add;
        }
        void withdraw(double s)
        {
            if(check(s)>2)
            {
                cout<<"您输入的金额不合法"<<endl;
                return ;
            }
            else if(money<s)
            {
                cout<<"您的存款金额不足"<<endl;
                return ;
            }
            else money-=s;
        }
    private :
        string  id;
        string name;
        string sex;
        int age;
        double money;
};

int  main()
{
        Account  tom;
        tom.init("32020320011001876X",  "Tom  Black",  "男",  19,  2000.89);
        tom.printmoney();//输出：Tom  Black的金额为2000.89
        tom.deposit(89.471);//输出：您输入的金额不合法
        tom.printmoney();//输出：Tom  Black的金额为2000.89
        tom.deposit(10000);
        tom.printmoney();//输出：Tom  Black的金额为12000.89
        tom.withdraw(10001);
        tom.printmoney();//输出：Tom  Black的金额为1999.89
        tom.withdraw(10000.123);//输出：您输入的金额不合法
        tom.printmoney();//输出：Tom  Black的金额为1999.89
        tom.withdraw(10000.9);//输出：您的金额金额不足
        tom.printmoney();//输出：Tom  Black的金额为1999.89
        Account  jerry;
        jerry.init("320203200910116569",  "Jerry  Black",  "女",  11,  100.956);//输出：您输入的金额不合法
        jerry.printmoney();//输出：Jerry  Black的金额为0.00
}