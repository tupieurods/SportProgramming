#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
  int n;
  scanf("%d", &n);
  int* adding = new int[n + 10];
  int* vals = new int[n + 10];
  memset(adding, 0, sizeof(int) * (n + 10));
  memset(vals, 0, sizeof(int) * (n + 10));
  double sum = 0;
  int cnt = 1;
  for(int i = 0; i < n; i++)
  {
    int t;
    scanf("%d", &t);
    switch(t)
    {
      case 1:
      {
        int x, count;
        scanf("%d %d", &count, &x);
        sum += count * x;
        adding[count - 1] += x;
        break;
      }
      case 2:
      {
        int k;
        scanf("%d", &k);
        cnt++;
        sum += k;
        vals[cnt - 1] = k;
        break;
      }
      case 3:
      {
        sum -= adding[cnt - 1] + vals[cnt - 1];
        adding[cnt - 2] += adding[cnt - 1];
        adding[cnt - 1] = 0;
        //printf("%f\n\n", sum);
        cnt--;
        break;
      }
    }
    if(cnt != 0)
    {
      printf("%.10f\n", sum / (double)cnt);
    }
    else
    {
      printf("%.10f\n", 0.0);
    }
  }
  return 0;
}
