#include <stdio.h>
#include <algorithm>

using namespace std;

pair<int, int>* lens;
int n;

int compare(const void* a, const void* b)
{
  pair<int, int> realA = *(pair<int, int>*)a;
  pair<int, int> realB = *(pair<int, int>*)b;
  /*if(realB.second == realA.second)
  {
    return realB.first - realA.first;
  }*/
  return realB.second - realA.second;
}

double f(int len, int i)
{
  if(i == n)
    return 0.0;
  return lens[i].first + ((double)lens[i].second / 100.0) * f(len + lens[i].first, i + 1) + (1 - ((double)lens[i].second / 100.0)) * (f(len, i + 1) + len);
}

int main()
{
  scanf("%d", &n);
  lens = new pair<int, int>[n];
  for(int i = 0; i < n; i++)
  {
    int len, p;
    scanf("%d %d", &len, &p);
    lens[i] = make_pair(len, p);
  }
  qsort(lens, n, sizeof(pair<int, int>), compare);
  for(int i = 0; i < n; i++)
  {
    printf("%d %d\n", lens[i].first, lens[i].second);
  }
  printf("%.10f\n", f(0, 0));
  return 0;
}
