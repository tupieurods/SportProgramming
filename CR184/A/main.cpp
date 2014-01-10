#include <stdio.h>
#include <string.h>
#include <vector>

int main()
{
  int n;
  scanf("%d", &n);
  bool vals[101];
  memset(vals, 0, sizeof(vals));
  for(int i = 0; i < n; i++)
  {
    int tmp;
    scanf("%d", &tmp);
    vals[tmp] = true;
  }
  std::vector<int> answer;
  bool flag = false;
  if(vals[0])
    answer.push_back(0);
  if(vals[100])
    answer.push_back(100);
  for(int i = 1; i < 10; i++)
  {
    if(vals[i])
    {
      answer.push_back(i);
      flag = true;
      break;
    }
  }
  for(int i = 1; i < 10; i++)
  {
    if(vals[i * 10])
    {
      answer.push_back(i * 10);
      flag = true;
      break;
    }
  }
  if(!flag)
  {
    for(int i = 11; i < 100; i++)
    {
      if(vals[i])
      {
        answer.push_back(i);
        break;
      }
    }
  }
  printf("%d\n", answer.size());
  for(std::vector<int>::iterator it = answer.begin(); it != answer.end(); it++)
  {
    printf("%d ", *it);
  }
  return 0;
}