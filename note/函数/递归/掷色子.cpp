#include<iostream>
using namespace std;
enum GameStatus{win,lose,more};
int roll()//掷色子
{
    int point1 = rand() % 6 + 1;
    int point2 = rand() % 6 + 1;
    return point1 + point2;
}
int main()
{
    GameStatus result;//游戏结果
    int sum;
    
    unsigned int seed;
    cout<<"please a unsinged number to get rand number:";
    cin>>seed;//输入随机种子;
    srand(seed);

    int count=0;//回合数
    while(++count){
        cout<<"第"<<count<<"回合结果是:";
        int rollSum=roll();
        switch(rollSum){
            case 7:
            case 11:{
                result = win;
                break;//结果为7,11,胜利
            }
            case 2:
            case 3:
            case 12:{
                result = lose;
                break;//结果是2,3,12,失败
            }
            default:{
                result = more;
                break;//其余结果为平局
            }
        }
        cout<<rollSum<<"  ";
        if(result != more)
        {
            cout<< result<<endl;
            break;
        }
        else cout<<"平局"<<endl;
    }
}