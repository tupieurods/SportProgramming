#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

int n;
int opinion[2][109];
int linksCnt[109];
pair<int, int> links[109][109];

void ReadData()
{
  memset(opinion, 0, sizeof(opinion));
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &opinion[0][i]);
    opinion[0][i] *= 10000;
  }
  for(int i = 0; i < n; i++)
  {
    linksCnt[i] = 0;
    scanf("%d", &linksCnt[i]);
    if(linksCnt[i] == 0)//WTF
    {
      continue;
    }
    for(int j = 0; j < linksCnt[i]; j++)
    {
      scanf("%d", &links[i][j].first);
    }
    for(int j = 0; j < linksCnt[i]; j++)
    {
      scanf("%d", &links[i][j].second);
      //links[i][j].second *= 1000;
    }
  }
}

int answer[109];

void Solve()
{
  for(int i = 0; i < 49; i++)
  {
    for(int j = 0; j < n; j++)
    {
      if(linksCnt[j] == 0)
      {
        opinion[1][j] = opinion[0][j];
        continue;
      }
      __int64 current = 0;
      for(int k = 0; k < linksCnt[j]; k++)
      {
        current += opinion[0][links[j][k].first - 1] * links[j][k].second;
      }
      opinion[1][j] = ((current / linksCnt[j]) + opinion[0][j]) / 2;
    }
    //swap(opinion[0], opinion[1]);
    for(int j = 0; j < n; j++)
    {
      opinion[0][j] = opinion[1][j];
    }
  }
  for(int i = 0; i < n; i++)
  {
    if(opinion[0][i] <= -5000)
    {
      answer[i] = -1;
    }
    else if(opinion[0][i] >= 5000)
    {
      answer[i] = 1;
    }
    else
    {
      answer[i] = 0;
    }
  }
}

void WriteData()
{
  for(int i = 0; i < n; i++)
  {
    printf("%d\n", answer[i]);
  }
}

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  ReadData();
  Solve();
  WriteData();
  return 0;
}