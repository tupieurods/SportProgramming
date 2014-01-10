#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <hash_set>

using namespace std;

int answer;
int n, k;
int *ipAdrs;

void ReadData()
{
  scanf("%d %d", &n, &k);
  ipAdrs = new int[n];
  for(int i = 0; i < n; i++)
  {
    int a, b, c, d;
    scanf("%d.%d.%d.%d", &a, &b, &c, &d);
    ipAdrs[i] = (a << 24) | (b << 16) | (c << 8) | d;
    //printf("%d.%d.%d.%d = %d\n", a, b, c, d, ipAdrs[i]);
  }
}

void Solve()
{
  answer = 0;
  stdext::hash_set<int> masks;
  for(int i = 31; i >= 0; i--)
  {
    answer |= 1 << i;
    masks.clear();
    for(int i = 0; i < n; i++)
    {
      masks.insert(answer & ipAdrs[i]);
    }
    if(masks.size() == k)
      return;
  }
  answer = -1;
}

void WriteData()
{
  if(answer == -1)
  {
    printf("-1\n");
  }
  else
  {
    int mask[4];
    for(int i = 3; i >= 0; i--)
    {
      mask[i] = answer & 255;
      answer >>= 8;
    }
    printf("%d.%d.%d.%d\n", mask[0], mask[1], mask[2], mask[3]);
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