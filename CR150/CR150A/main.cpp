#include <stdio.h>
#include <strings.h>

using namespace std;

int main()
{
  int n, k;
  scanf("%d %d", &n, &k);
  int* children = new int[k+1];
  bool* used = new bool[(n*k) + 1];
  memset(used, 0, sizeof(bool) * ((n*k) + 1));
  for(int i = 1; i <= k; i++)
  {
    int tmp;
    scanf("%d", &tmp);
    children[i] = tmp;
    used[tmp] = true;
  }
  int current = 0;
  for(int i = 1; i <= k; i++)
  {
    printf("%d ", children[i]);
    int count = 1;
    while(count != n)
    {
      current++;
      if(used[current])
        continue;
      count++;
      printf("%d ",current);
    }
    printf("\n");
  }
  return 0;
}
