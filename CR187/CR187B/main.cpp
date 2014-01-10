#include <stdio.h>
#include <string.h>

__int64 a[100005], b[100005];
int n, m;

void ReadData()
{
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= n; i++)
  {
    scanf("%I64d", &a[i]);
  }
  memset(b, 0, sizeof(b));
}

void Solve()
{
  __int64 globalSum = 0;
  for(int i = 0; i < m; i++)
  {
    int t;
    scanf("%d", &t);
    switch(t)
    {
      case 1:
        int v;
        __int64 x;
        scanf("%d %I64d", &v, &x);
        b[v] = globalSum;
        a[v] = x;
        break;
      case 2:
        __int64 val;
        scanf("%I64d", &val);
        globalSum += val;
        break;
      case 3:
        int index;
        scanf("%d", &index);
        printf("%I64d\n", globalSum - b[index] + a[index]);
        break;
    }
  }
}

/*void WriteData()
{
}*/

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
    //WriteData();
  }
  return 0;
}