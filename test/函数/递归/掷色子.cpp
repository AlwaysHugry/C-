#include<iostream>
using namespace std;
enum GameStatus{win,lose,more};
int roll()//��ɫ��
{
    int point1 = rand() % 6 + 1;
    int point2 = rand() % 6 + 1;
    return point1 + point2;
}
int main()
{
    GameStatus result;//��Ϸ���
    int sum;
    
    unsigned int seed;
    cout<<"please a unsinged number to get rand number:";
    cin>>seed;//�����������;
    srand(seed);

    int count=0;//�غ���
    while(++count){
        cout<<"��"<<count<<"�غϽ����:";
        int rollSum=roll();
        switch(rollSum){
            case 7:
            case 11:{
                result = win;
                break;//���Ϊ7,11,ʤ��
            }
            case 2:
            case 3:
            case 12:{
                result = lose;
                break;//�����2,3,12,ʧ��
            }
            default:{
                result = more;
                break;//������Ϊƽ��
            }
        }
        cout<<rollSum<<"  ";
        if(result != more)
        {
            cout<< result<<endl;
            break;
        }
        else cout<<"ƽ��"<<endl;
    }
}