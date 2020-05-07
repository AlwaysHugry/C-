#include<iostream>
#include<cmath>
using namespace std;
bool isPrime(unsigned short a)
{
	if (a <= 1)return 0;
	else if (a == 2)return 1;
	else {
		for (int i = 2; i <= sqrt(a); i++)
		{
			if (a % i == 0)return 0;
		}
		return 1;
	}
}
int main()
{
	unsigned short a;
	cin >> a;
	if (isPrime(a))
		cout << "Y" << endl;
	else
		cout << "N" << endl;
}