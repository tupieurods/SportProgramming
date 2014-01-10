#include <stdio.h>

using namespace std;

int *minArray;
int *deltaArray;

int getMaximalStart(int delta)
{
  int result = 0;
  do
    {
      if(delta - deltaArray[result] <= 0)
        {
          printf("%d ", minArray[result] - delta + deltaArray[result]);
          delta = 0;
        }
      else
        {
          delta -= deltaArray[result];
          printf("%d ", minArray[result]);
        }
      result++;
    }
  while(delta != 0);
  return result;
}

int main()
{
  int d, sumTime;
  scanf("%d %d", &d, &sumTime);
  minArray = new int[d];
  deltaArray = new int[d];
  int minSum = 0;
  int maxSum = 0;
  for(int i = 0; i < d; i++)
    {
      int minimal, maximum;
      scanf("%d %d", &minimal, &maximum);
      minArray[i] = minimal;
      deltaArray[i] = maximum - minimal;
      minSum += minimal;
      maxSum += maximum;
    }
  if(minSum > sumTime || maxSum < sumTime)
    printf("NO");
  else
    {
      printf("YES\n");
      if(minSum == sumTime)
        {
          for(int i = 0; i < d; i++)
            printf("%d ", minArray[i]);
        }
      else
        {
          int sumDelta = maxSum - sumTime;
          int start = sumDelta == 0 ? 0 : getMaximalStart(sumDelta); //Откуда суммировать максимумы
          for(int i = start; i < d; i++)
            printf("%d ", minArray[i] + deltaArray[i]);
        }
    }
  return 0;
}
