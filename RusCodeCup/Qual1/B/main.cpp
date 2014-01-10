#include <stdio.h>
#include <map>

using namespace std;

int n;
__int64 answer;
map<int, int> a;
map<int, int>::iterator it;

void ReadData()
{
  scanf("%d", &n);
  a.clear();
  for(int i = 0; i < n; i++)
  {
    int tmp;
    scanf("%d", &tmp);
    it = a.find(tmp);
    if(it == a.end())
    {
      a.insert(make_pair(tmp, 1));
    }
    else
    {
      it->second++;
    }
  }
}

__int64 CalcC(__int64 cnt)
{
  if(cnt < 2LL)
    return 1;
  return (cnt * (cnt - 1LL)) / 2LL;
}

void Solve()
{
  answer = 0LL;
  __int64 sum = 0LL;
  for(it = a.begin(); it != a.end(); it++)
  {
    if(it->second == 1)
      continue;
    sum += it->second;
    answer += ;
  }
}

void WriteData()
{
  printf("%I64d\n", answer);
}

int main()
{
  int QWE;
  scanf("%d", &QWE);
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}