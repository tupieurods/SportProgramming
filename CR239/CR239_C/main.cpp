#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

int a[2];

void ReadData()
{
  scanf("%d %d", &a[0], &a[1]);
}

pair<int, int> answer[3];
bool answerReal;

void Solve()
{
  answerReal = false;
  answer[0] = make_pair(2, 1);
  for(int T = 0; T < 2; T++)
  {
    for(int b1 = 1; b1 < a[T]; b1++)
    {
      int b2 = (int)sqrt((double)(a[T] * a[T] - b1 * b1));
      if(((b2 * b2 + b1 * b1) != a[T] * a[T]) || b2 == 0)
      {
        continue;
      }
      answer[1].first = 2 + b1;
      answer[1].second = 1 + b2;
      int aP = -(answer[1].second - answer[0].second);
      int bP = -(answer[0].first - answer[1].first);
      double shitA = (aP * 1.0) / sqrt(aP * 1.0 * aP + bP * bP);
      double shitB = (bP * 1.0) / sqrt(aP * 1.0 * aP + bP * bP);
      answer[2].first = 2 + shitA * a[T == 0 ? 1 : 0];
      answer[2].second = 1 + shitB * a[T == 0 ? 1 : 0];
      aP = answer[2].first - 2;
      bP = answer[2].second - 1;
      if((aP * aP + bP * bP) != a[T == 0 ? 1 : 0] * a[T == 0 ? 1 : 0])
      {
        continue;
      }
      if((answer[2].first - answer[1].first) == 0 || (answer[2].second - answer[1].second) == 0)
      {
        continue;
      }
      answerReal = true;
      return;
    }
  }
}

void WriteData()
{
  if(answerReal)
  {
    printf("YES\n");
    for(int i = 0; i < 3; i++)
    {
      printf("%d %d\n", answer[i].first, answer[i].second);
    }
  }
  else
  {
    printf("NO\n");
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