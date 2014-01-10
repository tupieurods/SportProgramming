#include <stdio.h>
#include <string.h>
#include <vector>
#include <set>

int n, x;
int *a;
int *inSet;

void ReadData()
{
  scanf("%d %d", &n, &x);
  a = new int[n + 1];
  inSet = new int[n + 1];
  memset(inSet, 0xFF, sizeof(int) * (n + 1));
  for(int i = 1; i <= n; i++)
  {
    scanf("%d", &a[i]);
  }
}

std::vector<int> sets;

int f(int val)
{
  if(inSet[val] == -1)
  {
    if(a[val] == x)
      return -2;
    int result;
    if(a[val] == 0)
    {
      int to_push = sets.size();
      sets.push_back(1);
      result = to_push;
    }
    else
    {
      result = f(a[val]);
      if(result != -2)
        sets[result]++;
    }
    inSet[val] = result;
  }
  return inSet[val];
}

bool *answer;
int maximal;
void Solve()
{
  sets.clear();
  f(x);
  for(int i = 1; i <= n; i++)
  {
    f(i);
  }
  maximal = 0;
  for(std::vector<int>::iterator it = sets.begin(); it != sets.end(); it++)
  {
    maximal += *it;
  }
  answer = new bool[maximal + 1];
  memset(answer, 0, sizeof(bool) * (maximal + 1));
  //answer[0] = true;
  answer[sets[0]] = true;
  int cnt = sets.size();
  for(int i = 1; i < cnt; i++)
  {
    int val = sets[i];
    for(int j = maximal - val; j >= 0; j--)
    {
      if(answer[j])
        answer[j + val] = true;
    }
  }
}

void WriteData()
{
  //printf("count: %d\n", sets.size());
  for(int i = 1; i <= maximal; i++)
  {
    if(answer[i])
      printf("%d\n", i);
  }
  printf("\n");
  /*for(int i = 0; i < sets.size(); i++)
  {
    printf("      %d\n", sets[i]);
  }*/
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