#include<iostream>
using namespace std;
enum GameResult{WIN,LOSE,TIE,CANCLE};//声明enum的形式,并初始化,且后续不可更改;
/*
   此处未赋值,则默认第一个值为0,之后的值依次加一;
   若{WIN=3,LOSE=3,TIE,CANCLE},未赋值的元素有前一个元素加一;
*/
int main()
{
    GameResult result;//声明GameResult类型的变量,这个变量只能取规定的值
    enum GameResult omit =CANCLE;//也可以在前面添加enum;

    for(int count=WIN;count<=CANCLE;count++)//enum可以向上隐形转换为int
   {
       result = GameResult(count);//赋值方法之一
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