#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
int t = 0;
char s[10];
bool check(int a, int b)//һ�μ�����в�ͬ�е�λ���Ƿ����Ҫ��
{
	for (int i = 0; i < 8; i++)
	{
		if (abs(a - i - 1) == abs(b - (int)(s[i]-'0')))
		{
			return 0;
			break;
		}
	}
	return 1;
}
int main()
{
	bool vis[10];//���ڴ洢����Ϣ
	memset(vis, 0, 10);
	int result_column,result_row;//����λ�õ�������
	cin >> s;
	for (int i = 0; i < 8; i++)
	{
		if (s[i] == '*')//�ҳ�����ʺ����
		{
			result_column = i + 1;
		}
		else {//���ʺ��λ�����δ洢��ȥ
			int k = (int)(s[i] - '0');
			vis[k] = 1;
		}
	}
	for (int i = 1; i <= 8; i++)
	{
		if (!vis[i]) {
			result_row = i;//���ܵ���
		}
	}
	if (check(result_column, result_row)) {
		cout << result_row;
	}
	else cout << "No Answer";
}