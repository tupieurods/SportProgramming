#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
char str1[100009], str2[100009];

void ReadData()
{
  scanf("%s%*c", str1);
  scanf("%s%*c", str2);
  n = strlen(str1);
}

inline int min(int v1, int v2)
{
  return v1 < v2 ? v1 : v2;
}

int answer;

void Solve()
{
  answer = 0;
  int a = 0, b = 0;
  for(int i = 0; i < n; i++)
  {
    if(str1[i] != str2[i])
    {
      if(str2[i] == '4')
      {
        a++;
      }
      else
      {
        b++;
      }
    }
  }
  int delta = min(a, b);
  answer = delta;
  a -= delta;
  b -= delta;
  answer += a + b;
}

void WriteData()
{
  printf("%d\n", answer);
}

int main()
{
  int QWE = 1;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d%*c", &QWE);
  #endif
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}