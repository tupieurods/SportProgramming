#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, m;
char table[509][509];
int sum[509][509];

int getSum(int x, int y)
{
  if(y >= 0 && y < n && x >= 0 && x < m)
    return sum[y][x];
  return 0;
}

void ReadData()
{
  memset(sum, 0, sizeof(sum));
  scanf("%d %d%*c", &n, &m);
  char str[509];
  for(int i = 0; i < n; i++)
  {
    scanf("%s%*c", &str);
    for(int j = 0; j < m; j++)
    {
      table[i][j] = (char)(str[j] == '*');
      sum[i][j] = table[i][j] + getSum(j - 1, i)
        + getSum(j, i - 1) - getSum(j - 1, i - 1);
    }
  }
}

int min(int v1, int v2)
{
  return v1 < v2 ? v1 : v2;
}

int getSum(int x1, int y1, int x2, int y2)
{
  return sum[y2][x2] - getSum(x1 - 1, y2)
    - getSum(x2, y1 - 1) + getSum(x1 - 1, y1 - 1);
}

bool isBitOn(int val, int number)
{
  return ((val >> number) & 1) == 1;
}

int move[4][4] = 
{
  {0, 0, 1, 1},
  {1, 0, 2, 1},
  {0, 1, 1, 2},
  {1, 1, 2, 2},
};
char dp[505][505][10][16];
int answer;

int f(int x, int y, int level, int mask)
{
  if(x >= m - 1 || y >= n - 1) throw;
  if(level < 1) throw;
  if(dp[x][y][level][mask] != -1)
    return dp[x][y][level][mask];
  char result = 0;
  if(level == 1)//Проверим что соответсвуем маске
  {
    int checker = table[y][x] | (table[y][x + 1] << 1)
      | (table[y + 1][x] << 2) | (table[y + 1][x + 1] << 3);
    if(checker == mask)
      result = 1;
    goto finish;
  }
  //Если уровень больше чем 1
  int delta = 1 << (level - 1);
  for(int i = 0; i < 4; i++)
  {
    if(isBitOn(mask, i))
    {
      //result += f(x + move[i][0] * delta, y + move[i][1] * delta, level - 1, 15);
      result += (int)(getSum(x + move[i][0] * delta, y + move[i][1] * delta,
                    x + move[i][2] * delta - 1, y + move[i][3] * delta - 1) == delta * delta);
    }
    else
    {
      result += f(x + move[i][0] * delta, y + move[i][1] * delta, level - 1, mask);
    }
  }
  result = (char)(result == 4);
  finish: dp[x][y][level][mask] = result;
  return result;
}

void Solve()
{
  //printf("%d\n", getSum(2, 1, 6, 2));
  answer = 0;
  memset(dp, 0xFF, sizeof(dp));
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < m; j++)
    {
      int distance = min(m - j, n - i);
      for(int level = 2; level < 9; level++)
      {
        if((1 << level) > distance)
          break;
        for(int mask = 0; mask < 16; mask++)
          answer += f(j, i, level, mask);
      }
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