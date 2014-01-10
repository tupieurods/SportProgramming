#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct dragon
{
  int x, y;
};

int compare(const void *a, const void *b)
{
  const struct dragon *a1 = (dragon*)a;
  const struct dragon *b1 = (dragon*)b;
  int delta = a1->x - b1->x;
  return delta != 0 ? delta : b1->y - a1->y;
}

int main()
{
  __int64 s;
  int n;
  scanf("%I64d %d", &s, &n);
  dragon* data = new dragon[n];
  for(int i = 0; i < n; i++)
  {
    scanf("%d %d", &data[i].x, &data[i].y);
  }
  qsort(data, n, sizeof(dragon), compare);
  for(int i = 0; i < n; i++)
  {
    if(s <= data[i].x)
    {
      printf("NO");
      return 0;
    }
    s += data[i].y;
  }
  printf("YES");
  return 0;
}
