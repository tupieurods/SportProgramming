#include <stdio.h>
#include <map>
#include <set>
#include <string.h>

using namespace std;

int* data;
int n, l;
int* maxArr;
int* minArr;

bool solve(int elemNum)
{
  if(elemNum == n - 1)
  {
    if(data[elemNum] >= 1 && data[elemNum] <= l)
      return true;
    else
      return false;
  }
  for(int i = 1; i <= l; i++)
  {
    int tmp = -data[elemNum] + i;
    if(tmp >= minArr[elemNum+1] && tmp <= maxArr[elemNum+1])
    {
      data[elemNum+1] = tmp;
      if(!solve(elemNum + 1))
      {
        continue;
      }
      data[elemNum] = i;
      return true;
    }
  }
  return false;
}

int main()
{
  int d;
  scanf("%d %d %d", &n, &d, &l);
  data = new int[n];
  maxArr = new int[n];
  minArr = new int[n];
  data[0] = d;
  memset(data + 1, 0, sizeof(int)*(n - 1));
  memset(maxArr, 0, sizeof(int)*n);
  memset(minArr, 0, sizeof(int)*n);
  maxArr[n-1] = l;
  minArr[n-1] = 1;
  for(int i = n - 2; i >= 0; i--)
  {
    maxArr[i] = l - minArr[i+1];
    minArr[i] = 1 - maxArr[i+1];
  }
  if(!solve(0))
  {
    printf("-1");
    return 0;
  }
  for(int i = 0; i < n; i++)
    printf("%d ", data[i]);
  return 0;
}
