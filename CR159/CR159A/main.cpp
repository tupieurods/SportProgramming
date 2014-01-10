#include <stdio.h>
#include <stdlib.h>

using namespace std;

int compare(const void* a, const void* b)
{
  return (*(int*)b - *(int*)a);
}

int main()
{
  int n, m, k;
  scanf("%d %d %d\n", &n, &m, &k);
  int* filters = new int[n];
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &filters[i]);
  }
  qsort(filters, n, sizeof(n), compare);
  int canUse = 0;
  while(true)
  {
    bool flag = false;
    int freeSockets = k - 1;
    int needsToPower = m;
    int currentFilter = 0;
    for(int i = 0; i < canUse; i++)
    {
      needsToPower -= filters[i] - 1;
    }
    needsToPower--;
    if(freeSockets >= needsToPower)
    {
      printf("%d\n", canUse);
      return 0;
    }
    if((canUse == n) && (!flag))
    {
      printf("-1\n");
      return 0;
    }
    canUse++;
  }
  return 0;
}
