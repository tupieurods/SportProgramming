#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct rect
{
  int w, h;
};

int n, w, h;
rect rects[209];

void ReadData()
{
  scanf("%d %d %d", &w, &h, &n);
  for(int i = 0; i < n; i++)
  {
    scanf("%d %d", &rects[i].w, &rects[i].h);
  }
}

inline int min(int v1, int v2)
{
  return v1 < v2 ? v1 : v2;
}

int dp[609][609];
int answer;

int f(int cw, int ch)
{
  /*for(int i = 0; i < debugVal; i++)
  {
    printf(" ");
  }
  printf("%d %d\n", cw, ch);*/
  if(cw == 0 || ch == 0)
  {
    return 0;
  }
  if(dp[cw][ch] != -1)
  {
    return dp[cw][ch];
  }
  int result = cw * ch;
  for(int i = 1; i < cw; i++)
  {
    result = min(result, f(i, ch) + f(cw - i, ch));
  }
  for(int i = 1; i < ch; i++)
  {
    result = min(result, f(cw, i) + f(cw, ch - i));
  }
  //Неправильные переходы. По идее должны заменить два нижних цикла
  //Но чёто не прёт.
  /*for(int i = 0; i < n; i++)
  {
    if(rects[i].h > ch || rects[i].w > cw)
    {
      continue;
    }
    int cols = 1;
    int rows = ch / rects[i].h;
    int current = rects[i].w * ch - rects[i].w * rects[i].h * cols * rows;
    result = min(result, current + f(cw - rects[i].w, ch, debugVal+1));

    cols = cw / rects[i].w;
    rows = 1;
    current = rects[i].h * cw - rects[i].w * rects[i].h * cols * rows;
    result = min(result, current + f(cw, ch - rects[i].h, debugVal+1));
  } */
  /*for(int i = 1; i <= cw; i++)
  {
  for(int j = 0; j < n; j++)
  {
  if(rects[j].h > ch || rects[j].w > i)
  {
  continue;
  }
  int cols = i / rects[j].w;
  int rows = ch / rects[j].h;
  int current = i * ch - rects[j].w * rects[j].h * cols * rows;
  result = min(result, current + f(cw - i, ch));
  }
  }
  for(int i = 1; i <= ch; i++)
  {
  for(int j = 0; j < n; j++)
  {
  if(rects[j].h > i || rects[j].w > cw)
  {
  continue;
  }
  int cols = cw / rects[j].w;
  int rows = i / rects[j].h;
  int current = i * cw - rects[j].w * rects[j].h * cols * rows;
  result = min(result, current + f(cw, ch - i));
  }
  }*/
  dp[cw][ch] = result;
  return result;
}

void Solve()
{
  memset(dp, 0xFF, sizeof(dp));
  for(int i = 0; i < n; i++)
  {
    dp[rects[i].w][rects[i].h] = 0;
  }
  answer = f(w, h);
}

void WriteData()
{
  printf("%d\n", answer);
}

#define LOCAL

int main()
{
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif
  ReadData();
  Solve();
  WriteData();
  return 0;
}