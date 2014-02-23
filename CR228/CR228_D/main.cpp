#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int k;

void ReadData()
{
  scanf("%d", &k);

}

int n;
bool answer[1009][1009];
int levels[39][39];

void add(int row, int column)
{
  answer[row][column] = true;
  answer[column][row] = true;
}

void Solve()
{
  n = 500;
  memset(answer, 0, sizeof(answer));
  memset(levels, 0, sizeof(levels));
  levels[1][0] = 1;
  levels[1][1] = 1;
  add(1, 3);
  add(1, 4);
  int l = 3, r = 4;
  for(int i = 2; i <= 30; i++)
  {
    int nl = r + 1, nr = ((r - l + 1) + 1) + r;
    int prevLevel = l;
    int ind = 0;
    int sum = 0;
    for(int j = nl; j < nr; j++)
    {
      add(prevLevel, j);
      add(prevLevel, nr);
      levels[i][ind] = levels[i - 1][ind];
      sum += levels[i - 1][ind];
      prevLevel++;
      ind++;
    }
    levels[i][ind] = sum;
    l = nl;
    r = nr;
  }
  for(int i = 0; i <= 31; i++)
  {
    if((1 << i) & k)
    {
      add(2, l + 1 +i);
    }
  }
}

void WriteData()
{
  printf("%d\n", n);
  for(int i = 1; i <= n; i++)
  {
    for(int j = 1; j <= n; j++)
    {
      printf("%c", answer[i][j] ? 'Y' : 'N');
    }
    printf("\n");
  }
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