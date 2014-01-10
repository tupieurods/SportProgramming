#include <stdio.h>
#include <set>

using namespace std;

int main()
{
  int n, s, t;
  scanf("%d %d %d", &n, &s, &t);
  s--;
  t--;
  int* p = new int[n];
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &p[i]);
    p[i]--;
  }
  if(s == t)
  {
    printf("0");
    return 0;
  }
  int pos = s;
  set<int> used;
  int answer = 0;
  //for(int i = 0; i < 500000; i++)
  while(true)
  {
    if(used.find(pos) != used.end())
    {
      break;
    }
    used.insert(pos);
    pos = p[pos];
    answer++;
    if(pos == t)
    {
      printf("%d", answer);
      return 0;
    }
  }
  printf("-1");
  return 0;
}
