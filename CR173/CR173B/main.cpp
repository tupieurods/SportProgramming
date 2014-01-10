#include <stdio.h>
#include <stdlib.h>
#include <cmath>

using namespace std;

int main()
{
  int n;
  scanf("%d\n", &n);
  int A = 0, G = 0;
  char* answer = new char[n + 1];
  answer[n] = '\0';
  for(int i = 0; i < n; i++)
  {
    int a, g;
    scanf("%d %d", &a, &g);
    int delta1 = abs(A + a - G);
    int delta2 = abs(G + g - A);
    if((delta1 > 500) && (delta2 > 500))
    {
      printf("-1");
      return 0;
    }
    if(delta1 < delta2)
    {
      A += a;
      answer[i] = 'A';
    }
    else
    {
      G += g;
      answer[i] = 'G';
    }
  }
  printf("%s", answer);
  return 0;
}
