#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <set>
#include <time.h>

using namespace std;

int n, m, *a;
int *answer;

void ReadData()
{
  scanf("%d %d", &n, &m);
  a = new int[n];
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
}

int maximal;
map<int, pair<int, int>> step;

void Solve()
{
  answer = new int[m];
  memset(answer, 0xFF, sizeof(int) * m);
  answer[1] = 0;
  step.clear();
  step.insert(make_pair(1, make_pair(-1, -1)));
  for(int i = 0; i < n; i++)
  {
    int val = a[i];
    for(int j = m; j >= 0; j--)
    {
      if(answer[j] != -1
        && answer[(j * val) % m] == -1)
      {
        if(answer[j] == i && i > 0)
          continue;
        answer[(j * val) % m] = i;
        step.insert(make_pair((j * val) % m, make_pair(j, i)));
      }
    }
  }
  maximal = 1;
  for(int i = 2; i < m; i++)
  {
    if(answer[i] != -1)
      maximal = i;
  }
}

void WriteData()
{
  printf("%d\n", maximal);
  if(maximal == 1)
    return;
  set<int> forPrint;
  int index = maximal;
  while(true)
  {
    if(step[index].second == -1)
      break;
    if(forPrint.find(step[index].second + 1) != forPrint.end())
      throw;
    forPrint.insert(step[index].second + 1);
    index = step[index].first;
  }
  int check = 1;
  for(set<int>::iterator it = forPrint.begin();
      it != forPrint.end(); it++)
  {
    check *= a[*it - 1];
    check %= m;
    printf("%d ", *it);
  }
  if(check != maximal)
    throw;
  printf("\n");
}

int main()
{
  if(!true)
  {
    freopen("input.txt", "w", stdout);
    srand(time(NULL));
    printf("100\n");
    for(int i = 0; i < 100; i++)
    {
      n = rand() % 15 + 1;
      m = rand() % 998 + 2;
      printf("%d %d\n", n, m);
      for(int j = 0; j < n; j++)
      {
        printf("%d ", rand() % m + 1);
      }
      printf("\n\n");
    }
    return 0;
  }
  int QWE;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
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