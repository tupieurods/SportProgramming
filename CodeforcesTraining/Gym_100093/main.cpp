#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

int n, m;
int M[1009][12], a[1009];
int logs[20];

void ReadData()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    int val;
    scanf("%d", &a[i]);
  }
  scanf("%d", &m);
}

int getLog(int val)
{
  for(int i = 0; i < 20; i++)
  {
    if(logs[i] == val)
    {
      return i;
    }
    else if(logs[i] > val)
    {
      return i - 1;
    }
  }
}

int getMin(int l, int r)
{
  int k = getLog(r - l + 1);
  if(a[M[l][k]] <= a[M[r - (1 << k) + 1][k]])
  {
    return M[l][k];
  }
  else
  {
    return M[r - (1 << k) + 1][k];
  }
}

void Solve()
{
  memset(M, 0xFF, sizeof(M));
  for(int i = 0; i < n; i++)
  {
    M[i][0] = i;
  }
  //1 << j - длина полуинтервала
  for(int j = 1; (1 << j) <= n; j++)
  {
    //i-1+(1<<j) - индекс последнего элемента в полуинтервале
    for(int i = 0; (i - 1 + (1 << j)) < n; i++)
    {
      if(a[M[i][j - 1]] <= a[M[i + (1 << (j - 1))][j - 1]])
      {
        M[i][j] = M[i][j - 1];
      }
      else
      {
        M[i][j] = M[i + (1 << (j - 1))][j - 1];
      }
    }
  }
  for(int i = 0; i < m; i++)
  {
    int l, r;
    scanf("%d %d", &l, &r);
    printf("%d\n", a[getMin(l - 1, r - 1)]);
  }
}

void WriteData()
{
  printf("\n");
}

int main()
{
  int QWE = 1;
  freopen("stupid_rmq.in", "r", stdin);
  freopen("stupid_rmq.out", "w", stdout);
  #ifndef ONLINE_JUDGE
  scanf("%d", &QWE);
  #endif
  for(int i = 0; i < 20; i++)
  {
    logs[i] = 1 << i;
  }
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <algorithm>
//
//using namespace std;
//
//int n, m;
//int leftMin[1030], rightMin[1030], a[1030];
//
//void updateTree(int pos, int val)
//{
//  a[pos - 1] = val;
//  int i = pos;
//  while(i <= 1024)
//  {
//    leftMin[i] = min(val, leftMin[i]);
//    i += i & -i;
//  }
//  i = pos;
//  while(i > 0)
//  {
//    rightMin[i] = min(val, rightMin[i]);
//    i -= i & -i;
//  }
//}
//
//int getMin(int l, int r)
//{
//  int result = 1000000009;
//  int i = l;
//  while(i + (i & -i) <= r)
//  {
//    result = min(result, rightMin[i]);
//    i += (i & -i);
//  }
//  result = min(result, a[i - 1]);
//  i = r;
//  while(i - (i & -i) >= l)
//  {
//    result = min(result, leftMin[i]);
//    i -= (i & -i);
//  }
//  return result;
//}
//
//void ReadData()
//{
//  scanf("%d", &n);
//  /*memset(leftMin, 0, sizeof(leftMin));
//  memset(rightMin, 0, sizeof(rightMin));*/
//  for(int i = 0; i < 1030; i++)
//  {
//    leftMin[i] = 1000000009;
//    rightMin[i] = 1000000009;
//    a[i] = 1000000009;
//  }
//  for(int i = 0; i < n; i++)
//  {
//    int val;
//    scanf("%d", &val);
//    updateTree(i + 1, val);
//  }
//  scanf("%d", &m);
//}
//
//void Solve()
//{
//  for(int i = 0; i < m; i++)
//  {
//    int l, r;
//    scanf("%d %d", &l, &r);
//    printf("%d\n", getMin(l, r));
//  }
//}
//
//void WriteData()
//{
//  printf("\n");
//}
//
//int main()
//{
//  int QWE = 1;
//  freopen("stupid_rmq.in", "r", stdin);
//  freopen("stupid_rmq.out", "w", stdout);
//  #ifndef ONLINE_JUDGE
//  scanf("%d", &QWE);
//  #endif
//  for(int T = 0; T < QWE; T++)
//  {
//    ReadData();
//    Solve();
//    WriteData();
//  }
//  return 0;
//}