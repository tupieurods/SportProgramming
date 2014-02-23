#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int n;
char field[109][109];

void ReadData()
{
  scanf("%d%*c", &n);
  for(int i = 0; i < n; i++)
  {
    scanf("%s%*c", field[i]);
  }
}

bool answer;
bool visited[109][109];

void Solve()
{
  memset(visited, 0, sizeof(visited));
  answer = true;
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      if(visited[i][j] == false && field[i][j] == '#')
      {
        if(i + 1 < n && i + 2 < n && j + 1 < n && j - 1 >= 0)
        {
          if(field[i + 2][j] != '#' || visited[i + 2][j]
            || field[i + 1][j] != '#' || visited[i + 1][j]
            || field[i + 1][j - 1] != '#' || visited[i + 1][j - 1]
            || field[i + 1][j + 1] != '#' || visited[i + 1][j + 1])
          {
            answer = false;
            break;
          }
          else
          {
            visited[i][j] = true;
            visited[i + 1][j] = true;
            visited[i + 1][j - 1] = true;
            visited[i + 1][j + 1] = true;
            visited[i + 2][j] = true;
          }
        }
        else
        {
          answer = false;
          break;
        }
      }
    }
  }
}

void WriteData()
{
  if(answer)
  {
    printf("YES\n");
  }
  else
  {
    printf("NO\n");
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
