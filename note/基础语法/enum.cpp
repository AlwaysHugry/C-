#include<iostream>
using namespace std;
enum GameResult{WIN,LOSE,TIE,CANCLE};//����enum����ʽ,����ʼ��,�Һ������ɸ���;
/*
   �˴�δ��ֵ,��Ĭ�ϵ�һ��ֵΪ0,֮���ֵ���μ�һ;
   ��{WIN=3,LOSE=3,TIE,CANCLE},δ��ֵ��Ԫ����ǰһ��Ԫ�ؼ�һ;
*/
int main()
{
    GameResult result;//����GameResult���͵ı���,�������ֻ��ȡ�涨��ֵ
    enum GameResult omit =CANCLE;//Ҳ������ǰ�����enum;

    for(int count=WIN;count<=CANCLE;count++)//enum������������ת��Ϊint
   {
       result = GameResult(count);//��ֵ����֮һ
       if(result==omit)
       cout<<"The game was cancled"<<endl;
       else{
           cout<<"The game was played ";
           if(result==WIN)
           cout<<"and win!";
           if(result==LOSE)
           cout<<"and lose!";
           cout<<endl;
       }
   }
   return 0;
}