#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int n, m;
const int TREESIZE = 4 * (1 << 17);
__int64 color[TREESIZE], sum[TREESIZE], colordiff[TREESIZE];

void ReadData()
{
  scanf("%d %d", &n, &m);
}

void BuildTree(int l, int r, int index)
{
  if(l == r)
  {
    color[index] = l + 1;
  }
  else
  {
    int center = (l + r) / 2;
    BuildTree(l, center, index * 2 + 1);
    BuildTree(center + 1, r, index * 2 + 2);
  }
}

void Push(int l, int r, int index)
{
  if(colordiff[index] == 0)
  {
    return;
  }
  if(l != r)
  {
    color[index * 2 + 1] = color[index];
    color[index * 2 + 2] = color[index];
    int center = (l + r) / 2;
    sum[index * 2 + 1] += colordiff[index] * (center - l + 1);
    sum[index * 2 + 2] += colordiff[index] * (r - center);
    colordiff[index * 2 + 1] += colordiff[index];
    colordiff[index * 2 + 2] += colordiff[index];
  }
  colordiff[index] = 0;
}

void update(int l, int r, int ul, int ur, int index, __int64 newColor)
{
  Push(l, r, index);
  if(ul > ur)
  {
    return;
  }
  if(ul == l && ur == r && color[index] != 0)
  {
    sum[index] += abs(color[index] - newColor) * (r - l + 1);
    colordiff[index] += abs(color[index] - newColor);
    color[index] = newColor;
    return;
  }
  int center = (l + r) / 2;
  update(l, center, ul, std::min(ur, center), index * 2 + 1, newColor);
  update(center + 1, r, std::max(ul, center + 1), ur, index * 2 + 2, newColor);
  sum[index] = sum[index * 2 + 1] + sum[index * 2 + 2];
  color[index] = color[index * 2 + 1] == color[index * 2 + 2] ? color[index * 2 + 1] : 0;
}

__int64 query(int l, int r, int ul, int ur, int index)
{
  //printf("query: l:%d r:%d ul:%d ur:%d index:%d\n", l, r, ul, ur, index);
  Push(l, r, index);
  if(ul > ur)
  {
    return 0;
  }
  if(ul == l && ur == r)
  {
    return sum[index];
  }
  int center = (l + r) / 2;
  return query(l, center, ul, std::min(ur, center), index * 2 + 1)
          + query(center + 1, r, std::max(ul, center + 1), ur, index * 2 + 2);
}

void Solve()
{
  memset(color, 0, sizeof(color));
  memset(sum, 0, sizeof(sum));
  memset(colordiff, 0, sizeof(colordiff));
  BuildTree(0, n - 1, 0);
  for(int i = 0; i < m; i++)
  {
    int type, l, r;
    scanf("%d %d %d", &type, &l, &r);
    if(type == 1)
    {
      __int64 X;
      scanf("%I64d", &X);
      update(0, n - 1, l - 1, r - 1, 0, X);
    }
    else if(type == 2)
    {
      printf("%I64d\n", query(0, n - 1, l - 1, r - 1, 0));
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
    WriteData();
  }
  return 0;
}