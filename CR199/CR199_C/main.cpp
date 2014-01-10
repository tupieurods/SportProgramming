#include <stdio.h>
#include <stdlib.h>


int main()
{
  /*freopen("input.txt", "w", stdout);
  printf("1000\n");
  for(int i = 1; i < 101; i++)
  {
    for(int j = 1; j < 101; j++)
    {
      printf("%d %d\n", i, j);
    }
  }
  return 0;*/
  int QWE = 1;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  scanf("%d", &QWE);
  #endif
  for(int T = 0; T < QWE; T++)
  {
    double r, h;
    __int64 answer;
    //ReadData
    scanf("%lf %lf", &r, &h);
    //Solve
    answer = 0LL;
    double mh = h - r / 2.0;
    double top = 0.0;
    for(double i = r / 2.0; i <= h; i += r)
    {
      answer += 2;
      top += r;
    }
    top -= r / 2.0;
    double tmp = r *r + 4.0 * (h + r - top) * (h + r - top);
    if(r *r + 4.0 * (h + r - top) * (h + r - top) >= 8.0 *r * r)
      answer++;
    //WriteData
    //printf("r:%I64d h:%I64d %I64d\n", r, h, answer);
    printf("%I64d\n", answer);
  }
  return 0;
}