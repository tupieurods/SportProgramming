#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

using namespace std;

int n, m, s, f;
vector<pair<int, pair<int, int>>> moments;

void ReadData()
{
  scanf("%d %d %d %d", &n, &m, &s, &f);
  for(int i = 0; i < m; i++)
  {
    int t, l, r;
    scanf("%d %d %d", &t, &l, &r);
    moments.push_back(make_pair(t, make_pair(l ,r)));
  }
}

inline bool inRange(int l, int r, int pos)
{
  return ((pos >= l) && (pos <= r));
}

void Solve()
{
  char c;
  int delta;
  if(s > f)
  {
    delta = -1;
    c = 'L';
  }
  else
  {
    delta = 1;
    c = 'R';
  }
  int moment = 0;
  for(int i = 1; i < 1000009; i++)
  {
    char toPrint = c;
    if(i == moments[moment].first)
    {
      if(inRange(moments[moment].second.first, moments[moment].second.second, s)
        || inRange(moments[moment].second.first, moments[moment].second.second, s + delta))
      {
        toPrint = 'X';
      }
      else
      {
        s += delta;
      }
      moment++;
    }
    else
    {
      s += delta;
    }
    printf("%c", toPrint);
    if(s == f)
    {
      break;
    }
  }
}

void WriteData()
{
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
    #ifndef ONLINE_JUDGE
    WriteData();
    #endif
  }
  return 0;
}