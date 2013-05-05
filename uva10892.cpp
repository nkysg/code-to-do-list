#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;


int p[100];
int num[100];

int mypow(int x,int y)
{
  int mul = 1;
	for (int i = 0; i < y; ++i)
		mul *= x;
	return mul;
}
void add(int p[], int num[],int n,int index, int mul,vector<int>& ivec)
{
	if (index == n)
	{
		ivec.push_back(mul);
		return;
	}
	for (int i = 0; i <= num[index]; ++i)
		add(p,num,n,index+1,mul * mypow(p[index],i),ivec);
}

int gcd(int m, int n)
{
	while (n)
	{
		int t = m % n;
		m = n;
		n = t;
	}
	return m;
}
int lcm(int m,int n)
{
	return m/gcd(m,n) * n;
}

int main()
{
	int n;
	#ifndef ONLINE_JUDGE 
	freopen("1.txt","r",stdin);
	#endif
	while (scanf("%d",&n) && n)
	{
		if (n == 1) { printf("1 1\n"); continue; }
		int len = 0;
		int tempn = n;
		for (int i = 2; i * i <= n; ++i)
		{
			if (n % i == 0)
			{
				int cnt = 0;
				while (n % i == 0) { cnt++; n /= i; }
				p[len] = i; num[len++] = cnt;
			}
		}
		if (n > 1) { p[len] = n; num[len++] = 1; }
		vector<int> ivec;
		add(p,num,len,0,1,ivec);
		sort(ivec.begin(),ivec.end());

		int total = 0;
		int start = 0;
		for (int i = 0; i < ivec.size(); ++i)
			if (ivec[i] * ivec[i] > tempn) { start = i ; break; }
			
		for (; start+1 < ivec.size(); start++)
			for (int i = 1; i < start; i++)
				if (lcm(ivec[i],ivec[start]) == tempn) total++;
				
		int mul = 1;
		for (int i = 0; i < len; ++i)
			mul *= (num[i] + 1);
		total += mul;
		printf("%d %d\n",tempn,total);
	}
}
