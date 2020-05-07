#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
int t = 0;
char s[10];
bool check(int a, int b)//一次检验该列不同行的位置是否符合要求
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
	bool vis[10];//用于存储行信息
	memset(vis, 0, 10);
	int result_column,result_row;//所求位置的列与行
	cin >> s;
	for (int i = 0; i < 8; i++)
	{
		if (s[i] == '*')//找出所求皇后的列
		{
			result_column = i + 1;
		}
		else {//将皇后的位置依次存储进去
			int k = (int)(s[i] - '0');
			vis[k] = 1;
		}
	}
	for (int i = 1; i <= 8; i++)
	{
		if (!vis[i]) {
			result_row = i;//可能的行
		}
	}
	if (check(result_column, result_row)) {
		cout << result_row;
	}
	else cout << "No Answer";
}