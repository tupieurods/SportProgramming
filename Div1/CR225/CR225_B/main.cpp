#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int PREVIOUS = 0;
int CURRENT = 1;
int NEXT = 2;

using namespace std;

int n, m;
pair<int, int> volcanoes[100009];

void ReadData()
{
  memset(volcanoes, 0, sizeof(volcanoes));
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; i++)
  {
    int xVal, yVal;
    scanf("%d %d", &xVal, &yVal);
    volcanoes[i].first = yVal;
    volcanoes[i].second = xVal;
  }
}

bool answer;
pair<int, int> ranges[3][200009];

void Solve()
{
  sort(volcanoes, volcanoes + m);
  answer = true;
  int cnt[3] = {0, 0, 0};
  int ind = 0;
  if(volcanoes[0].first == 1)
  {
    cnt[PREVIOUS] = 1;
    ranges[PREVIOUS][0].first = 1;
    ranges[PREVIOUS][0].second = volcanoes[0].second - 1;
    while(volcanoes[ind].first == 1)
    {
      ind++;
    }
  }
  else
  {
    ranges[PREVIOUS][0].first = 1;
    ranges[PREVIOUS][0].second = n;
    cnt[PREVIOUS] = 1;
  }
  int prevLine = 1;
  while(ind < m)
  {
    int startX = 1;
    int line = volcanoes[ind].first;
    if(line - 1 != prevLine)
    {
      cnt[PREVIOUS] = 1;
      ranges[PREVIOUS][0].second = n;
    }
    cnt[CURRENT] = 0;
    cnt[NEXT] = 0;
    while(ind < m && volcanoes[ind].first == line)
    {
      if(startX <= volcanoes[ind].second - 1)
      {
        ranges[CURRENT][cnt[CURRENT]].first = startX;
        ranges[CURRENT][cnt[CURRENT]].second = volcanoes[ind].second - 1;
        cnt[CURRENT]++;
      }
      startX = volcanoes[ind].second + 1;
      ind++;
    }
    if(startX <= n)
    {
      ranges[CURRENT][cnt[CURRENT]].first = startX;
      ranges[CURRENT][cnt[CURRENT]].second = n;
      cnt[CURRENT]++;
    }
    //m^2
    /*for(int i = 0; i < cnt[CURRENT]; i++)
    {
      for(int j = 0; j < cnt[PREVIOUS]; j++)
      {
        if(ranges[PREVIOUS][j].second >= ranges[CURRENT][i].first)
        {
          if(ranges[PREVIOUS][j].first <= ranges[CURRENT][i].second)
          {
            ranges[NEXT][cnt[NEXT]].first = max(ranges[PREVIOUS][j].first, ranges[CURRENT][i].first);
            ranges[NEXT][cnt[NEXT]].second = ranges[CURRENT][i].second;
            cnt[NEXT]++;
          }
          break;
        }
      }
    }*/
    for(int i = 0; i < cnt[CURRENT]; i++)
    {
      int l = 0, r = cnt[PREVIOUS] - 1, mid;
      while(r - l > 5)
      {
        mid = (l + r) / 2;
        if(ranges[PREVIOUS][mid].second < ranges[CURRENT][i].first)
        {
          l = mid;
        }
        else
        {
          r = mid;
        }
      }
      for(; l <= r; l++)
      {
        if(ranges[PREVIOUS][l].second >= ranges[CURRENT][i].first)
        {
          if(ranges[PREVIOUS][l].first <= ranges[CURRENT][i].second)
          {
            ranges[NEXT][cnt[NEXT]].first = max(ranges[PREVIOUS][l].first, ranges[CURRENT][i].first);
            ranges[NEXT][cnt[NEXT]].second = ranges[CURRENT][i].second;
            cnt[NEXT]++;
          }
          break;
        }
      }
    }
    if(cnt[NEXT] == 0)
    {
      answer = false;
      return;
    }
    /*printf("line %d:", line);
    for(int i = 0; i < cnt[CURRENT]; i++)
    {
      printf("[%d; %d]; ", ranges[CURRENT][i].first, ranges[CURRENT][i].second);
    }
    printf("\n");*/
    swap(PREVIOUS, NEXT);
    prevLine = line;
  }
  if(cnt[PREVIOUS] == 0 || (ranges[PREVIOUS][cnt[PREVIOUS] - 1].second != n && prevLine == n))
  {
    answer = false;
  }
}

void WriteData()
{
  printf("%d\n", answer ? 2 * n - 2 : -1);
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