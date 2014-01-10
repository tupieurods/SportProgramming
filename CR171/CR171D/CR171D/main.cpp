#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define LOCALTEST

int* data;
int** diff;
int n;
int answer;
bool visited[1<<24];

int count(int value)
{
  int result = 0;
  while(value != 0)
  {
    if(value & 1)
      result++;
    value >>= 1;
  }
  return result;
}

inline int min(int a, int b)
{
  return a < b ? a : b;
}

void f(int mask, int current)
{
  if(current == n)
  {
    answer = min(answer, count(mask));
    return;
  }
  if(visited[mask])
    return;
  visited[mask] = true;
  int copy = mask;
  int result = 1000;
  int newMask = mask | (1 << current);
  int pos = current - 1;
  for(; pos >= 0; pos--)
  {
  /*while(copy != 0)
  {*/
    if((mask & (1 << pos))
        && (diff[current][pos] != - 1)
        && ((mask & (1 << diff[current][pos])) != 0))
    {
      f(newMask, current + 1);
      for(int k = 0; k < current; k++)
      {
        if(mask & (1 << k))
        {
          f(newMask ^ (1 << k), current + 1);
        }
      }
      break;
    }
    copy >>= 1;
    //pos++;
  //}
  }
}

//Fuck, why f2 works faster?
void f2(int mask, int current)
{
  if(current == n)
  {
    answer = min(answer, count(mask));
    return;
  }
  if(visited[mask])
    return;
  visited[mask] = true;
  for(int i = 0; i < current; i++)
  {
    if(!(mask & (1 << i)))
      continue;
    for(int j = i; j < current; j++)
    {
      if(!(mask & (1 << j)))
        continue;
      if(data[i] + data[j] == data[current])
      {
        f2(mask | (1 << current), current + 1);
        for(int k = 0; k < current; k++)
        {
          if(mask & (1 << k))
          {
            f2(mask ^ (1 << k) | (1 << current), current + 1);
          }
        }
      }
    }
  }
}

int main()
{
  int QWE;
#ifdef LOCALTEST
  freopen("input.txt", "r", stdin);
  scanf("%d", &QWE);
#else
  QWE = 1;
#endif
  for(int T = 0; T < QWE; T++)
  {
    scanf("%d", &n);
    data = new int[n];
    for(int i = 0; i < n; i++)
    {
      scanf("%d", &data[i]);
    }
    diff = new int*[n];
    for(int i = 0; i < n; i++)
    {
      diff[i] = new int[n];
      for(int j = 0; j < n; j++)
      {
        diff[i][j] = -1;
        for(int k = 0; k < n; k++)
        {
          if(data[k] == (data[i] - data[j]))
          {
            diff[i][j] = k;
            break;
          }
        }
      }
    }
    answer = 1000;
    //memset(visited, 0, sizeof(bool) * (1 << 24));
    f2(1, 1);
    if(answer == 1000)
      answer = -1;
    printf("%d\n", answer);
  }
  return 0;
}