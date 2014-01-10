#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dfsVisit(int current);

int n;
int points[100][2];

void ReadData()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    scanf("%d %d", &points[i][0], &points[i][1]);
  }
}

int answer;
bool visited[100];

void Solve()
{
  answer = 0;
  memset(visited, 0, sizeof(visited));

  for(int i = 0; i < n; i++)
  {
    if(!visited[i])
    {
      answer++;
      dfsVisit(i);
    }
  }
}

void dfsVisit(int current)
{
  visited[current] = true;

  for(int i = 0; i < n ; i++)
  {
    if(!visited[i]
        && (points[current][0] == points[i][0]
              || points[current][1] == points[i][1]))
    {
      dfsVisit(i);
    }
  }
}

void WriteData()
{
  printf("%d\n", answer - 1);
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