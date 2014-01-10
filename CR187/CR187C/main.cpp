#include <stdio.h>

int n;
__int64 k;
__int64 *a;

void ReadData()
{
  scanf("%d %I64d", &n, &k);
  a = new __int64[n];
  for(int i = 0; i < n; i++)
  {
    scanf("%I64d", &a[i]);
  }
}

/*__int64 calc(int index)
{
  __int64 result = 0;
  for(int i = 1; i < index; i++)
  {
    result += a[i - 1] * (i - 1) - (n - index) * a[index - 1];
  }
  return result;
}*/

void Solve()
{
  __int64 d = 0;
  __int64 additional = 0;
  __int64 removed = 0;
  /*for(int i = 0; i < n; i++)
  {
    printf("%I64d\t", calc(i + 1));
  }
  printf("\n");*/
  for(int i = 0; i < n; i++)
  {
    //printf("rating: %I64d\n", d - additional);
    if(d - additional < k)
    {
      removed++;
      printf("%d\n", i + 1);
      if(i == n - 1)
        break;
      //d -= a[i - 1] * (i - 1);
      //d += a[i] * i;
      additional = a[i + 1] * (i + 1 - removed) * (n - (i + 2));
    }
    else
    {
      if(i == n - 1)
        break;
      d += a[i] * (i - removed);
      additional = a[i + 1] * (i + 1 - removed) * (n - (i + 2));
    }
  }
}

void WriteData()
{
  printf("\n\n");
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
    //WriteData();
  }
  return 0;
}