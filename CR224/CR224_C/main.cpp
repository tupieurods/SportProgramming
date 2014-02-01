#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int n;
int a[100009];

void ReadData()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
}

int answerSize;
int answer[3];

void Solve()
{
  answerSize = 0;
  answer[0] = INT_MAX;
  answer[1] = INT_MAX;
  answer[2] = INT_MAX;
  std::sort(a, a + n);
  int d[2] = {INT_MAX, INT_MAX};
  int counter[2] = {0, 0};
  int pos[2] = {-1, -1};
  if(n == 1)
  {
    answerSize = -1;
    return;
  }
  for(int i = 0; i < n - 1; i++)
  {
    int delta = a[i + 1] - a[i];
    int checker = 0;
    for(; checker < 3; checker++)
    {
      if(d[checker] == delta || d[checker] == INT_MAX)
      {
        if(delta == 0 && d[checker] == 0)
        {
          if(a[pos[checker]] != a[i])
          {
            return;
          }
        }
        d[checker] = delta;
        pos[checker] = i;
        counter[checker]++;
        break;
      }
    }
    if(checker == 3)
    {
      return;
    }
  }
  if(counter[1] > counter[0])
  {
    std::swap(d[0], d[1]);
    std::swap(pos[0], pos[1]);
    std::swap(counter[0], counter[1]);
  } else if(counter[1] == counter[0])
  {
    if(d[0] > d[1])
    {
      std::swap(d[0], d[1]);
      std::swap(pos[0], pos[1]);
      std::swap(counter[0], counter[1]);
    }
  }
  if(counter[1] == 0)//Одинаковая дельта
  {
    if(n == 2)//Всего два числа
    {
      answer[0] = a[0] - d[0];
      answer[1] = a[1] + d[0];
      int newD = d[0] / 2;
      if((a[0] + newD * 2) == a[1])
      {
        answer[2] = a[0] + newD;
        answerSize++;
      }
      else if((a[0] + d[0] * 2) == a[1])
      {
        answer[2] = a[0] + d[0];
        answerSize++;
      }
      if(d[0] != 0)
      {
        answerSize += 2;
      }
    }
    else
    {
      if(d[0] == 0)
      {
        answerSize = 1;
        answer[0] = a[0];
      }
      else
      {
        answerSize = 2;
        answer[0] = a[0] - d[0];
        answer[1] = a[n - 1] + d[0];
      }
    }
  }
  else if(counter[1] > 1 || d[0] == 0)
  {
    return;
  }
  else
  {
    if(a[pos[1]] + d[0] * 2 == a[pos[1] + 1])
    {
      answerSize = 1;
      answer[0] = a[pos[1]] + d[0];
    }
  }
}

void WriteData()
{
  printf("%d\n", answerSize);
  std::sort(answer, answer + 3);
  for(int i = 0; i < answerSize; i++)
  {
    printf("%d ", answer[i]);
  }
  printf("\n");
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