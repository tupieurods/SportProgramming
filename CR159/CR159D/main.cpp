#include <stdio.h>
#include <cstring>

using namespace std;

int main()
{
  int n;
  scanf("%d", &n);
  __int64* data = new __int64[n];
  for(int i = 0; i < n; i++)
  {
    scanf("%I64d", &data[i]);
  }
  bool* anwser = new bool[n];
  memset(anwser, 0, sizeof(bool) * n);
  __int64 sum = data[n - 1];
  anwser[n - 1] = true;
  for(int i = n - 2; i >= 0; i--)
  {
    if(sum > 0)
    {
      sum -= data[i];
      anwser[i] = false;
    }
    else
    {
      sum += data[i];
      anwser[i] = true;
    }
  }
  bool invert = sum < 0;
  for(int i = 0; i < n; i++)
  {
    if(anwser[i])
    {
      if(invert)
        printf("-");
      else
        printf("+");
    }
    else
    {
      if(invert)
        printf("+");
      else
        printf("-");
    }
  }
  return 0;
}
