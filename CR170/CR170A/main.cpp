#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
  int n;
  scanf("%d", &n);
  int* data = new int[n + 1];
  data[0] = 0;
  int value = 0;
  for(int i = 1; i <= n; i++)
  {
    scanf("%d", &data[i]);
    value += data[i];
    //data[i] = value;
  }
  int s, t;
  scanf("%d %d", &s, &t);
  if(s > t)
  {
    swap(s, t);
  }
  int answer = 0;
  for(int i = s; i < t; i++)
  {
    answer += data[i];
  }
  answer = min(answer, value - answer);
  printf("%d", answer);
  return 0;
}
