#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <functional>

using namespace std;

pair<int, int> a[3];

void ReadData()
{
  for(int i = 0; i < 3; i++)
  {
    int val;
    scanf("%d", &val);
    a[i].first = val;
    a[i].second = i + 1;
  }
}

bool answer;
int answerArr[3];

void AddToAnswer(int val, int v1, int v2)
{
  int l = min(v1, v2);
  int r = max(v1, v2);
  if(l == 2)
  {
    answerArr[1] += val;
  }
  else if(r == 2)
  {
    answerArr[0] += val;
  }
  else
  {
    answerArr[2] += val;
  }
}

void Solve()
{
  answer = false;
  memset(answerArr, 0, sizeof(answerArr));
  sort(a, a + 3, greater<pair<int, int>>());
  //reverse(a, a + 3);
  for(int i = 0; i < 3; i++)
  {
    a[i].first--;
  }
  if(a[0].first == 0)
  {
    /*if(a[1].first == 0 && a[2].first == 0)
    {
      answer = true;
    }*/
    return;
  }
  a[0].first--;
  AddToAnswer(1, a[0].second, a[1].second);
  AddToAnswer(1, a[0].second, a[2].second);
  sort(a, a + 3, greater<pair<int, int>>());
  //reverse(a, a + 3);
  if(((a[2].first + a[1].first - a[0].first) % 2) == 1)
  {
    return;
  }
  
  int y = (a[2].first + a[1].first - a[0].first) / 2;
  int x = a[2].first - y;
  if(x < 0 || y < 0)
    return;
  if(y > x)
    swap(x, y);
  a[0].first -= x;
  a[1].first -= y;
  AddToAnswer(x, a[2].second, a[0].second);
  AddToAnswer(y, a[2].second, a[1].second);
  if(a[0].first != a[1].first)
  {
    return;
  }
  AddToAnswer(a[0].first, a[1].second, a[0].second);
  for(int i = 0; i < 3; i++)
  {
    if(answerArr[i] < 0)
      return;
  }
  answer = true;
}

void WriteData()
{
  if(!answer)
  {
    printf("Impossible\n");
    return;
  }
  for(int i = 0; i < 3; i++)
  {
    printf("%d ", answerArr[i]);
  }
  printf("\n");
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