#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, k, p;
__int64 rowSum[1009], colSum[1009];
__int64 rowSumAns[1000009], colSumAns[1000009];

void ReadData()
{
  scanf("%d %d %d %d", &n, &m, &k, &p);
  memset(rowSum, 0, sizeof(rowSum));
  memset(colSum, 0, sizeof(colSum));
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < m; j++)
    {
      int val;
      scanf("%d", &val);
      rowSum[i] += val;
      colSum[j] += val;
    }
  }
}

__int64 answer;

void Solve()
{
  memset(rowSumAns, 0, sizeof(rowSumAns));
  memset(colSumAns, 0, sizeof(colSumAns));
  answer = _I64_MIN;
  priority_queue<__int64> rows(rowSum, rowSum + n), cols(colSum, colSum + m);
  __int64 rowMinus = p * 1LL * m;
  __int64 colMinus = p * 1LL * n;
  for(int i = 0; i < k; i++)
  {
    __int64 rowTop = rows.top();
    __int64 colTop = cols.top();
    rows.pop();
    cols.pop();
    rowSumAns[i + 1] = rowSumAns[i] + rowTop;
    colSumAns[i + 1] = colSumAns[i] + colTop;
    rows.push(rowTop - rowMinus);
    cols.push(colTop - colMinus);
  }
  for(int i = 0; i <= k; i++)
  {
    answer = max(answer, rowSumAns[i] + colSumAns[k - i] - p * 1LL * i * (k - i));
  }
}

void WriteData()
{
  printf("%I64d\n", answer);
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