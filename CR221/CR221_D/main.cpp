#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

int n, m;
char matrix[5009][5009];
int right[5009][5009];

void ReadData()
{
  scanf("%d %d%*c", &n, &m);
  memset(right, 0, sizeof(right));
  for(int row = 0; row < n; row++)
  {
    scanf("%s%*c", matrix[row]);
    for(int column = m - 1; column >= 0; column--)
    {
      right[column][row] = matrix[row][column] == '1' ? right[column + 1][row] + 1 : 0;
    }
  }
}

int answer;

void Solve()
{
  answer = 0;
  for(int column = 0; column < m; column++)
  {
    sort(right[column], right[column] + n);
    for(int row = 0; row < n; row++)
    {
      answer = max(answer, right[column][row] * (n - row));
    }
  }
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