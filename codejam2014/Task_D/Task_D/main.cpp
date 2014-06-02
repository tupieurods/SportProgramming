#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <set>

int n;
double v1[1009], v2[1009];
std::set<double> s1, s2;

void ReadData()
{
  scanf("%d", &n);
  s1.clear();
  s2.clear();
  for(int i = 0; i < n; i++)
  {
    scanf("%lf", &v1[i]);
    s1.insert(v1[i]);
  }
  for(int i = 0; i < n; i++)
  {
    scanf("%lf", &v2[i]);
    s2.insert(v2[i]);
  }
}

int a1, a2;

void Solve()
{
  std::sort(v1, v1 + n);
  std::sort(v2, v2 + n);
  a1 = a2 = 0;
  std::set<double>::iterator it;
  for(int i = 0; i < n; i++)
  {
    it = s2.upper_bound(v1[i]);
    if(it == s2.end())
    {
      it--;
    }
    if(v1[i] > *it)
    {
      a2++;
    }
    s2.erase(it);
  }
  int l = 0, r = n - 1;
  for(int i = 0; i < n; i++)
  {
    if(v1[i] < v2[l])
    {
      r--;
    }
    else
    {
      l++;
      a1++;
    }
  }
  /*printf("\n");
  for(int i = 0; i < n; i++)
  {
    printf("%.3lf ", v1[i]);
  }
  printf("\n");
  for(int i = 0; i < n; i++)
  {
    printf("%.3lf ", v2[i]);
  }
  printf("\n");*/
}

void WriteData()
{
  printf("%d %d\n", a1, a2);
}

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int QWE;
  scanf("%d", &QWE);
  for(int T = 0; T < QWE; T++)
  {
    printf("Case #%d: ", T + 1);
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}