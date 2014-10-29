#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <set>

using namespace std;

const __int64 MOD = 1000000000;

int n, m;
int k;
int a[109];
int s;
int b[109];

void ReadData()
{
	scanf("%d %d", &n, &m);
	scanf("%d", &k);
	set<int> se;
	for(int i = 0; i < k; i++)
	{
		scanf("%d", &a[i]);
		se.insert(a[i]);
	}
	k = se.size();
	int idx = 0;
	for(set<int>::iterator it = se.begin(); it != se.end(); it++)
	{
		a[idx] = *it;
		idx++;
	}
	se.clear();
	scanf("%d", &s);
	for(int i = 0; i < s; i++)
	{
		scanf("%d", &b[i]);
		se.insert(b[i]);
	}

	s = se.size();
	idx = 0;
	for(set<int>::iterator it = se.begin(); it != se.end(); it++)
	{
		b[idx] = *it;
		idx++;
	}
}

__int64 dp[100009];
__int64 answer;

void add(__int64 &addTo, __int64 val)
{
	addTo = (addTo + val) % MOD;
	if(addTo < 0)
	{
		addTo += MOD;
	}
}

__int64 f(int val)
{
	if(val == n)
	{
		return 1;
	}
	if(dp[val] != -1)
	{
		return dp[val];
	}
	dp[val] = 0;
	for(int i = 0; i < k; i++)
	{
		if(val - a[i] >= n)
		{
			add(dp[val], f(val - a[i]));
		}
	}
	for(int i = 0; i < s; i++)
	{
		if(val % b[i] == 0 && (val / b[i]) >= n)
		{
			add(dp[val], f(val / b[i]));
		}
	}
	return dp[val];
}

void Solve()
{
	memset(dp, 0xFF, sizeof(dp));
	answer = 0;
	for(int i = 0; i < s; i++)
	{
		if(m % b[i] == 0)
		{
			add(answer, f(m / b[i]));
		}
	}
}

void WriteData()
{
	printf("%I64d\n", answer);
}

int main()
{
	int QWE = 1;
	freopen("EQUALIZER.IN", "r", stdin);
	scanf("%d", &QWE);
	for(int T = 0; T < QWE; T++)
	{
		ReadData();
		Solve();
		WriteData();
	}
	return 0;
}