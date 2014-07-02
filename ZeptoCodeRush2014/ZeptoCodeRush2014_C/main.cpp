#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int n, m, k, w;
char level[1009][19][19];
int delta[1009][1009];

void ReadData()
{
  scanf("%d %d %d %d%*c", &n, &m, &k, &w);
  for(int i = 0; i < k; i++)
  {
    for(int j = 0; j < n; j++)
    {
      scanf("%s%*c", level[i][j]);
    }
  }
}

std::pair<int, int> st[1009];
bool avaible[1009];
int answer;
std::pair<int, int> answerp[1009];

void Solve()
{
  for(int l1 = 0; l1 < k; l1++)
  {
    st[l1] = std::make_pair(n * m, -1);
    delta[l1][l1] = INT_MAX;
    for(int l2 = l1 + 1; l2 < k; l2++)
    {
      int current = 0;
      for(int row = 0; row < n; row++)
      {
        for(int column = 0; column < m; column++)
        {
          if(level[l1][row][column] != level[l2][row][column])
          {
            current++;
          }
        }
      }
      delta[l1][l2] = current * w;
      delta[l2][l1] = current * w;
    }
  }
  answer = n * m;
  int currentLevel = 0;
  memset(avaible, 1, sizeof(avaible));
  answerp[0].first = currentLevel;
  answerp[0].second = -1;
  for(int i = 1; i < k; i++)
  {
    avaible[currentLevel] = false;
    int idx = -1, current = INT_MAX;
    for(int j = 0; j < k; j++)
    {
      if(avaible[j])
      {
        if(delta[currentLevel][j] < st[j].first)
        {
          st[j].first = delta[currentLevel][j];
          st[j].second = currentLevel;
        }
        if(st[j].first < current)
        {
          current = st[j].first;
          idx = j;
        }
      }
    }
    answer += current;
    answerp[i].first = idx;
    answerp[i].second = st[idx].second;
    currentLevel = idx;
  }
}

void WriteData()
{
  printf("%d\n", answer);
  for(int i = 0; i < k; i++)
  {
    printf("%d %d\n", answerp[i].first + 1, answerp[i].second + 1);
  }
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