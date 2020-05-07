#include  <iostream>
#include  <cmath>
using  namespace  std;

//判断是否为素数
int  isPrime(long  num)
{
    if (num <= 1)return 0;
	else if (num == 2)return 1;
	else {
		for (int i = 2; i <= sqrt(num); i++)
		{
			if (num % i == 0)return 0;
		}
		return 1;
	}
}

//计算质因素分解，
void  factorization(long  n,long *factor,int &t)
{
    if(isPrime(n))
    {
        factor[t++]=n;
        return ; 
    }
    else
    for(int i=2;n!=1;i++)
    {
        while(n%i==0)
        {
            factor[t++]=i;
            n/=i;
        }
    }
    return;
}
int  main()
{
        long  n;
        long  factor[100];
        int  numofFactor  =  0;
        cin  >>  n;
        factorization(n,  factor,  numofFactor);
        for  (int  i  =  0;  i  <  numofFactor;  i++)
        {
                cout  <<  factor[i]  <<  "  ";
        }
        cout  <<  endl;
        return  0;
}