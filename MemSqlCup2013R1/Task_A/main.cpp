#include <stdio.h>

inline int max(int v1, int v2)
{
  return v1 > v2 ? v1 : v2;
}

inline int min(int v1, int v2)
{
  return v1 < v2 ? v1 : v2;
}

int main()
{
  int n;
  scanf("%d", &n);
  int area = 0, ymin = 100000, xmin = 100000, ymax = 0, xmax = 0;
  for(int i = 0; i < n; i++)
  {
    int xl, yl, xr, yr;
    scanf("%d %d %d %d", &xl, &yl, &xr, &yr);
    area += (xr - xl) * (yr - yl);
    xmin = min(xmin, xl);
    xmax = max(xmax, xr);
    ymin = min(ymin, yl);
    ymax = max(ymax, yr);
  }
  if(area == (ymax - ymin) * (xmax - xmin)
    && (ymax - ymin) == (xmax - xmin))
  {
    printf("YES\n");
  }
  else
  {
    printf("NO\n");
  }
  return 0;
}