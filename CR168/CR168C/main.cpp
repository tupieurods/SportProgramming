#include <stdio.h>
#include <set>
#include <stdlib.h>

using namespace std;

int compare(const void* a, const void* b)
{
  return (*(int*)b - *(int*)a);
}

int main()
{
  int n, k;
  scanf("%d %d", &n, &k);
  if(k == 1)
  {
    printf("%d", n);
    return 0;
  }
  int* a = new int[n];
  set<int> answer;
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
    answer.insert(a[i]);
  }
  qsort(a, n, sizeof(int), compare);
  for(int i = 0; i < n; i++)
  {
    if(((a[i] % k) == 0) && (answer.count(a[i]) != 0))
    {
      //printf("%d\n", a[i] / k);
      answer.erase(a[i] / k);
    }
  }
  /*for(set<int>::iterator it = answer.begin(); it != answer.end(); it++)
  {
    printf("%d ", *it);
  }*/
  printf("\n%d", answer.size());
  return 0;
}
