/*
�и�������Ҫ����һ���û�������򣬹���Ҫ�����£�

1����¼�û����˺š��������Ա����䡢���н��

2�����Զ�̬�����û��Ľ��

��1�����û���Ǯʱ�������ӵ����н����

  (2�����û�ȡǮʱ���������˻��п۳�

  (3)  ���ȡǮ�������н���ܾ�ȡǮ������

  (4) ���¼��Ϊ100.897Ԫ����Ϊ��Ч���룬Ӧ�þܾ�������ԭ��¼����������ԡ�Ԫ��Ϊ��λ��������С��λ�Ƿ֡���ͬѧ�ǿ���һ�£��������ЧӦ���������⡣



����ݸ�����main�������һ��Account��ʵ���������ܡ�
*/
#include  <iostream>
#include  <iomanip>
using  namespace  std;
//���ڴ˴�����Account��Ķ���
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
                cout<<"������Ľ��Ϸ�"<<endl;
                money = 0.0;
            }
            else money = money1;
        }
        void printmoney()
        {
            cout<<name<<"�Ĵ��Ϊ";
            printf("%.2lf",money);
            cout<<endl;
        }    
        void deposit(double add)
        {
            if(check(add)>2)
            {
                cout<<"������Ľ��Ϸ�"<<endl;
            }
            else money+=add;
        }
        void withdraw(double s)
        {
            if(check(s)>2)
            {
                cout<<"������Ľ��Ϸ�"<<endl;
                return ;
            }
            else if(money<s)
            {
                cout<<"���Ĵ�����"<<endl;
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
        tom.init("32020320011001876X",  "Tom  Black",  "��",  19,  2000.89);
        tom.printmoney();//�����Tom  Black�Ľ��Ϊ2000.89
        tom.deposit(89.471);//�����������Ľ��Ϸ�
        tom.printmoney();//�����Tom  Black�Ľ��Ϊ2000.89
        tom.deposit(10000);
        tom.printmoney();//�����Tom  Black�Ľ��Ϊ12000.89
        tom.withdraw(10001);
        tom.printmoney();//�����Tom  Black�Ľ��Ϊ1999.89
        tom.withdraw(10000.123);//�����������Ľ��Ϸ�
        tom.printmoney();//�����Tom  Black�Ľ��Ϊ1999.89
        tom.withdraw(10000.9);//��������Ľ�����
        tom.printmoney();//�����Tom  Black�Ľ��Ϊ1999.89
        Account  jerry;
        jerry.init("320203200910116569",  "Jerry  Black",  "Ů",  11,  100.956);//�����������Ľ��Ϸ�
        jerry.printmoney();//�����Jerry  Black�Ľ��Ϊ0.00
}