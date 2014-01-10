#include <stdio.h>
#include <algorithm>

using namespace std;

int display[105][105];

int main()
{
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      scanf("%d", &display[i][j]);
    }
  }
  int cnt = 1, start = 0;
  int diags = n * 2 - 1;
  for(int i = 0; i < diags; i++)
  {
    int line = min(i, n - 1);
    int column = start;
    for(int j = 0; j < cnt; j++)
    {
      printf("%d ", display[line][column]);
      line--;
      column++;
    }
    if(i >= n - 1)
    {
      start++;
      cnt--;
    }
    else
    {
      cnt++;
    }
  }
}