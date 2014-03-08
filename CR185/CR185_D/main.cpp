#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

#pragma warning(disable: 4996)

//#define INF 1LL << 60

int n, m, p;
int h[100009];
__int64 sums[100009];
int a[100009];

__int64 getSum(int l, int r)
{
  return sums[r] - sums[l - 1];
}

void ReadData()
{
  scanf("%d %d %d", &n, &m, &p);
  memset(h, 0, sizeof(h));
  memset(sums, 0, sizeof(sums));
  for(int i = 1; i < n; i++)
  {
    int value;
    scanf("%d", &value);
    h[i + 1] = h[i] + value;
  }
  for(int i = 0; i < m; i++)
  {
    int hVal, tVal;
    scanf("%d %d", &hVal, &tVal);
    a[i + 1] = tVal - h[hVal];
  }
}

__int64 dp[2][100009];
int ch[100009];
int CURRENT = 1;
int PREV = 0;

inline double getIntersect(int p, int q, int cats)
{
  return (double)((1.0 * dp[PREV][q] - getSum(q + 1, cats)) - (dp[PREV][p] - getSum(p + 1, cats))) / (1.0 * q - p);
}

void Solve()
{
  sort(a + 1, a + 1 + m);
  for(int i = 1; i <= m; i++)
  {
    sums[i] = sums[i - 1] + a[i];
    dp[PREV][i] = i * 1LL * a[i] - sums[i];
  }
  //printf("Stage 1 finished\n");
  for(int i = 2; i <= p; i++)
  {
    int l = 0, r = 1;
    ch[0] = 0, ch[1] = 0;
    for(int j = 1; j <= m; j++)
    {
      while(l + 1 < r && getIntersect(ch[l], ch[l + 1], j) < a[j])
      {
        l++;
      }
      dp[CURRENT][j] = dp[PREV][ch[l]] + (j - ch[l]) * 1LL * (a[j]) - getSum(ch[l] + 1, j);
      while(l + 1 < r && getIntersect(ch[r - 2], ch[r - 1], j) > getIntersect(ch[r - 1], j, j))
      {
        r--;
      }
      ch[r] = j;
      r++;
    }
    swap(PREV, CURRENT);
  }
}

void WriteData()
{
  printf("%I64d\n", dp[PREV][m]);
}

int main()
{
  int QWE = 1;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d", &QWE);
#endif
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}