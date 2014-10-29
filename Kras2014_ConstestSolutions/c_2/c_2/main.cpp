#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int n;
int p[100009];
//int sums[100009];

void ReadData()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &p[i]);
	}
}

int tree[100009];
int answer[100009];

void setVal(int idx)
{
	while(idx <= 100009)
	{
		tree[idx]++;
		idx += (idx & -idx);
	}
}

int getVal(int idx)
{
	int result = 0;
	while(idx > 0)
	{
		result += tree[idx];
		idx -= idx & -idx;
	}
	return result;
}

void Solve()
{
	memset(tree, 0, sizeof(tree));
	for(int i = n - 1; i >= 0; i--)
	{
		answer[i] = getVal(p[i]);
		setVal(p[i]);
	}
}

void WriteData()
{
	for(int i = 0; i < n; i++)
	{
		printf("%d ", answer[i]);
	}
	printf("\n");
}

int main()
{
	int QWE = 1;
	freopen("CODE.IN", "r", stdin);
	scanf("%d", &QWE);
	for(int T = 0; T < QWE; T++)
	{
		ReadData();
		Solve();
		WriteData();
	}
	return 0;
}