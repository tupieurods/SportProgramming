#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

using namespace std;

int n, m, k, answer;
int matrix[15][15], sums[15][16];
const int MINUS_INF = -1;

int sum(int a, int b)
{
  if(a <= MINUS_INF || b <= MINUS_INF)
    return MINUS_INF;
  return a + b;
}

void ReadData()
{
  scanf("%d %d %d", &n, &m, &k);
  memset(matrix, 0, sizeof(matrix));
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < m; j++)
    {
      scanf("%d", &matrix[i][j]);
      //matrix[i][j]++;
    }
  }
}

int dp[15][225][15][15][2][2];
pair<int, int> p[15][225][15][15][2][2];

int getSum(int h, int l, int r)
{
  //if(l <=0) throw "sgk";
  return sums[h][r] - sums[h][l - 1];
}

int f(int h, int freeToUse, int start, int len, int l, int r)
{
  if(freeToUse == 0)
  {
    return 0;
  }
  if(h >= n /*&& freeToUse != 0*/)
  {
    return MINUS_INF;
  }
  if(dp[h][freeToUse][start][len][l][r] != 0x7F7F7F7F)
  {
    return dp[h][freeToUse][start][len][l][r];
  }
  int result = MINUS_INF;
  int right = start + len - 1;
  if(len == 0)
  {
    /*if(freeToUse != k)
      throw "bad";*/
    result = f(h + 1, freeToUse, 0, 0, 1, 1);
    p[h][freeToUse][start][len][l][r].first = 0;
    p[h][freeToUse][start][len][l][r].second = 0;
  }
  for(int newLen = 1; newLen <= m; newLen++)
  {
    if(newLen > freeToUse)
      break;
    for(int newStart = 0; newStart <= m - newLen; newStart++)
    {
      int newRight = newStart + newLen - 1;
      //if(newRight >= m) throw "Wtf";
      if((l == 1 && r == 1 && (len == 0 || (newStart <= right && newRight >= start)))
        || (l == 0 && r == 0 && newStart >= start && newRight <= right)
        || (l == 0 && r == 1 && newStart >= start && newStart <= right)
        || (l == 1 && r == 0 && /*newStart <= right && */newRight <= right && newRight >= start))
      {
        int newL = l, newR = r;
        if(newL == 1 && len != 0 && newStart > start)
        {
          newL = 0;
        }
        if(newR == 1 && len != 0 && newRight < right)
        {
          newR = 0;
        }
        int t = sum(f(h + 1, freeToUse - newLen, newStart, newLen, newL, newR),
            getSum(h, newStart + 1, newRight + 1));
        if(t > result)
        {
          result = t;
          p[h][freeToUse][start][len][l][r].first = newStart;
          p[h][freeToUse][start][len][l][r].second = newLen;
        }
      }
    }
  }
  dp[h][freeToUse][start][len][l][r] = result;
  return result;
}

void Solve()
{
  memset(dp, 0x7F, sizeof(dp));
  memset(sums, 0, sizeof(sums));
  for(int i = 0; i < n; i++)
  {
    int s = 0;
    for(int j = 0; j <= m; j++)
    {
      sums[i][j] = s;
      if(j != m)
        s += matrix[i][j];
    }
  }
  answer = f(0, k, 0, 0, 1, 1);
  /*if(answer < 0 || answer > 2250000)
    throw;*/
}

//int test;

void g(int h, int freeToUse, int start, int len, int l, int r)
{
  if(freeToUse == 0)
    return;
  //if(h >= n || dp[h][freeToUse][start][len][l][r] == 0x7F7F7F7F)
  //  throw;
  //printf("%d %d %d %d %d %d\n", h, freeToUse, start, len, l, r);
  int newH = h + 1, newFreeToUse = freeToUse - p[h][freeToUse][start][len][l][r].second,
    newStart = p[h][freeToUse][start][len][l][r].first,
    newLen = p[h][freeToUse][start][len][l][r].second,
    newL = l, newR = r;
  for(int i = 0; i < newLen; i++)
  {
    printf("%d %d\n", h + 1, newStart + i + 1);
    //test += matrix[h][newStart + i];
  }
  if(newL == 1 && len != 0 && newStart > start)
  {
    newL = 0;
  }
  if(newR == 1 && len != 0 && newStart + newLen - 1 < start + len - 1)
  {
    newR = 0;
  }
  /*if(len == 0 && (newL != 1 || newR != 1))
    throw;*/
  g(newH, newFreeToUse, newStart, newLen, newL, newR);
}

void WriteData()
{
  printf("Oil : %d\n", answer);
  //test = 0;
  g(0, k, 0, 0, 1, 1);
  //if(test != answer)
    //printf("Test failed. Showed answer: %d, current test: %d\n", answer, test);
    //throw "Fail";
}

int main()
{
  int QWE;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d", &QWE);
#else
  QWE = 1;
#endif
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}