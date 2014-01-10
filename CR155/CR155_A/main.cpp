#include <stdio.h>
#include <vector>

using namespace std;

int n;
vector<int> a[5000];

void ReadData()
{
  #ifndef ONLINE_JUDGE
  for(int i = 0; i < 5000; i++)
  {
    a[i].clear();
  }
  #endif
  scanf("%d", &n);
  for(int i = 0; i < 2 * n; i++)
  {
    int val;
    scanf("%d", &val);
    val--;
    a[val].push_back(i + 1);
  }
}

bool answer;

void Solve()
{
  answer = true;
  for(int i = 0; i < 5000; i++)
  {
    if(a[i].size() % 2 == 1)
    {
      answer = false;
      return;
    }
  }
}

void WriteData()
{
  if(answer == false)
  {
    printf("-1\n");
    return;
  }
  for(int i = 0; i < 5000; i++)
  {
    int sz = a[i].size();
    int jCnt = sz / 2;
    for(int j = 0; j < jCnt; j++)
    {
      printf("%d %d\n", a[i][j], a[i][sz - 1 - j]);
    }
  }
}

int main()
{
  int QWE = 1;
  freopen("input.txt", "r", stdin);
  #ifndef ONLINE_JUDGE
  scanf("%d", &QWE);
  #else
  freopen("output.txt", "w", stdout);
  #endif
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}