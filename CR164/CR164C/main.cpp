#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
  int n, m;
  scanf("%d %d", &n, &m);
  int anwser = min(n, m) + 1;
  int currentX = n;
  int currentY = 0;
  printf("%d\n", anwser);
  for(int i = 0; i < anwser; i++)
  {
    printf("%d %d\n", currentX, currentY);
    currentX--;
    currentY++;
  }
  return 0;
}
