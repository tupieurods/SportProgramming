#include <stdio.h>
#include <set>

using namespace std;

int main()
{
  set<__int64> answer;
  __int64 current = 1;
  __int64 delta = 0;
  while(current <= 1LL << 32)
  {
    answer.insert(current);
    delta++;
    current += delta;
  }
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    int val;
    scanf("%d", &val);
    if(answer.find(val) != answer.end())
    {
      printf("1 ");
    }
    else
    {
      printf("0 ");
    }
  }
  return 0;
}