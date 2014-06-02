#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

int main()
{
  int n;
  scanf("%d", &n);
  int kArr[109];
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &kArr[i]);
  }
  int answer = INT_MAX;
  for(int i = 0; i < n; i++)
  {
    int currentAnswer = 0;
    for(int j = 0; j < kArr[i]; j++)
    {
      int val;
      scanf("%d", &val);
      currentAnswer += 15 + val * 5;
    }
    answer = std::min(answer, currentAnswer);
  }
  printf("%d\n", answer);
}