#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{
  int n, t;
  scanf("%d %d", &n, &t);
  int* data = new int[n + 1];
  memset(data, 0, sizeof(int) * (n + 1));
  int answer = 0;
  int delFrom = 0;
  int sum = 0;
  for(int i = 1; i <= n; i++)
  {
    scanf("%d", &data[i]);
    sum += data[i];
    if(sum > t)
    {
      while(sum > t)
      {
        delFrom++;
        sum -= data[delFrom];
      }
    }
    answer = max(answer, i - delFrom);
  }
  printf("%d", answer);
  return 0;
}
