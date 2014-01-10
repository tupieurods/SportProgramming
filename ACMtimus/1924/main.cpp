#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
//Можно решить проще. Достаточно проверить чётность суммы от 1 до N включительно.
using namespace std;

int n;

void ReadData()
{
  scanf("%d", &n);
}

bool answer;
bool used[55];
map<int, bool> cache;


bool f(int cnt, int sum)
{
  if(cache.find(sum * 100 + cnt) != cache.end())
  {
    return cache[sum * 100 + cnt];
  }
  if(cnt == 0)
  {
    return abs(sum) % 2 == 0;
  }
  bool IsBlack = (n - cnt) % 2 == 0;
  bool black = false, grimy = false;
  for(int i = 0; i < n; i++)
  {
    if(used[i] == false)
    {
      used[i] = true;
      bool result = f(cnt - 1, sum + i + 1);
      black = black || result;
      grimy = grimy || !result;
      /*result = f(cnt - 1, sum - i - 1);
      black = black || result;
      grimy = grimy || !result;*/
      used[i] = false;
    }
  }
  if(IsBlack)
  {
    cache.insert(make_pair(sum * 100 + cnt, black || !grimy));
    return black || !grimy;
  }
  else
  {
    cache.insert(make_pair(sum * 100 + cnt, !grimy || black));
    return !grimy || black;
  }
}

void Solve()
{
  cache.clear();
  memset(used, 0, sizeof(used));
  answer = f(n, 0);
}

void WriteData()
{
  if(answer)
  {
    printf("black\n");
  }
  else
  {
    printf("grimy\n");
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