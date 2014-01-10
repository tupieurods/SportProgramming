#include <stdio.h>
#include <deque>

using namespace std;

int main()
{
  int n;
  scanf("%d", &n);
  deque<int> d;
  bool answer = true;
  while(n != 0)
  {
    if(n % 10 != 1 && n % 10 != 4)
    {
      answer = false;
      break;
    }
    d.push_front(n % 10);
    n /= 10;
  }
  if(answer)
  {
    n = d.size();
    int current = 0;
    for(int i = 0; i < n; i++)
    {
      if(current == 0)
      {
        if(d[i] != 1)
        {
          answer = false;
          break;
        }
        current = 1;
        continue;
      }
      if(current == 1)
      {
        if(d[i] == 4)
        {
          current = 14;
        }
        continue;
      }
      if(current == 14)
      {
        if(d[i] == 4)
        {
          current = 0;
        }
        else if(d[i] != 1)
        {
          answer = false;
          break;
        }
        else
        {
          current = 1;
        }
        //continue;
      }
    }
  }
  if(answer)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}