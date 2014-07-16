#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

void ReadData()
{
}

void Solve()
{
  int current = 1, prev = 0;
  char str[109];
  int n, m;
  scanf("%d %d%*c", &n, &m);
  for(int row = 0; row < n; row++)
  {
    scanf("%s%*c", str);
    for(int column = 0; column < m; column++)
    {
      if(str[column] == '.')
      {
        if(column % 2 == 0)
        {
          str[column] = row % 2 == 0 ? 'W' : 'B';
        }
        else
        {
          str[column] = row % 2 == 0 ? 'B' : 'W';
        }
      }
    }
    printf("%s\n", str);
    //std::swap(current, prev);
  }
}

void WriteData()
{
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
    //ReadData();
    Solve();
    //WriteData();
  }
  return 0;
}