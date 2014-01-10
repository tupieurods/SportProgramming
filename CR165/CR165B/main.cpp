#include <stdio.h>
#include <deque>

using namespace std;


int main()
{
  int n;
  scanf("%d", &n);
  int anwser = 0, postAnwser = 0;
  int last = -1;
  bool flag = true;
  deque<int> afterOne;
  for(int i = 0; i < n; i++)
  {
    int tmp;
    scanf("%d", &tmp);
    if(tmp != 1 && flag)
    {
      anwser++;
    }
    else
    {
      if(tmp == 1)
        flag = false;
      afterOne.push_front(tmp);
    }
  }
  if(afterOne.size() != 1)
  {
    for(int i = 0; i < afterOne.size() - 1; i++)
    {
      if(afterOne[i] > afterOne[i + 1])
       postAnwser++;
      else
        break;
    }
    printf("%d\n", anwser + afterOne.size() - postAnwser - 1);
  }
  else
  {
    printf("%d\n", anwser);
  }
  return 0;
}
