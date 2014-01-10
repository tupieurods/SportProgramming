#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

using namespace std;

int n;
bool matrix[109][109];
//int matrix2[109][109];
//int rows[109], cols[109];

void ReadData()
{
  char str[109];
  scanf("%d%*c", &n);
  for(int i = 0; i < n; i++)
  {
    scanf("%s%*c", str);
    for(int j = 0; j < n; j++)
    {
      matrix[i][j] = str[j] == '.';
    }
    //rows[i] = 0;
    //cols[i] = 0;
  }
}

vector<pair<int, int>> answer;

void Solve()
{
  /*memset(matrix2, 0, sizeof(matrix2));
  for(int i = 0; i < n; i++)
  {
  for(int j = 0; j < n; j++)
  {
  if(matrix[i][j])
  {
  for(int k = 0; k < n; k++)
  {
  matrix2[i][k]++;
  matrix2[k][j]++;
  }
  matrix2[i][j]--;
  rows[i]++;
  cols[j]++;
  }
  }
  } */
  answer.clear();
  /*for(int i = 0; i < n; i++)
  {
  if(rows[i] == 0 || cols[i] == 0)
  return;
  }  */
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      if(matrix[i][j])
      {
        answer.push_back(make_pair(i, j));
        break;
      }
    }
  }
  if(answer.size() != n)
  {
    answer.clear();
    for(int j = 0; j < n; j++)
    {
      for(int i = 0; i < n; i++)
      {
        if(matrix[i][j])
        {
          answer.push_back(make_pair(i, j));
          break;
        }
      }
    }
    if(answer.size() != n)
    {
      answer.clear();
    }
  }
}

void WriteData()
{
  if(answer.size() == 0)
  {
    printf("-1\n\n");
    return;
  }
  for(vector<pair<int, int>>::iterator it = answer.begin(); it != answer.end(); it++)
  {
    printf("%d %d\n", it->first + 1, it->second + 1);
  }
  printf("\n");
}

int main()
{
  int QWE;
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