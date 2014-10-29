#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

const __int64 MOD = 2017;

__int64 n, k;

void ReadData()
{
	scanf("%I64d %I64d", &n, &k);
}

__int64 answer;

void Solve()
{
	if(k > n || k > 10)
	{
		//wtf???
		throw;
	}
	if(n == k || k == 1)
	{
		answer = 1;
		return;
	}
	answer = 1;
	if(n >= k * 3)
	{
		answer = n;
		int total = (n / 2) + (n % 2);
		__int64 tail = 0;
		int idx = 0;
		for(int i = total; i <= n; i++)
		{
			tail = ((n - idx) * 1LL * (n - idx - 1)) % MOD;
		}
		tail /= 2;
		answer = (answer + tail) % MOD;
	}
	else
	{
		for(__int64 mul = n - k + 2; mul <= n; mul++)
		{
			answer = (answer * mul) % MOD;
			if(answer < 0)
			{
				answer += MOD;
			}
		}
		answer = (answer * (n - k)) % MOD;
		if(answer < 0)
		{
			answer += MOD;
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
	freopen("KOHINOOR.IN", "r", stdin);
	scanf("%d", &QWE);
	for(int T = 0; T < QWE; T++)
	{
		ReadData();
		Solve();
		WriteData();
	}
	return 0;
}