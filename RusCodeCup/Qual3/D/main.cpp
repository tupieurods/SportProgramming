#include <stdio.h>
#include <string.h>
#include <deque>

using namespace std;

int n;
int a[70], b[70], c[70];
bool used[70];
bool answer;

void ReadData()
{
  scanf("%d", &n);
}

bool f(int added)
{
  if(added == n)
    return true;
  added++;
  int from = 1;
  while(used[from])
  {
    from++;
  }
  int current = a[added];
  for(int i = from; i <= 3 * n; i++)
  {
    if(i + current > 3 * n)
      break;
    if(used[i] || used[i + current])
      continue;
    used[i] = true;
    used[i + current] = true;
    b[added] = i;
    c[added] = i + current;
    if(f(added))
    {
      return true;
    }
    used[i] = false;
    used[i + current] = false;
  }
  return false;
}

void Solve()
{
  answer = false;
  memset(used, 0, sizeof(bool));
  for(int i = 1; i <= n; i++)
  {
      a[i] = n + 1 - i;//Fast
//    a[i] = i;//So slow
    used[i] = true;
  }
  if(n % 4 == 2 || n % 4 == 3)
    return;
  answer = f(0);
}

void WriteData()
{
  if(answer == false)
  {
    printf("-1\n");
    return;
  }
  for(int i = 1; i <= n; i++)
  {
    printf("%d ", a[i]);
  }
  printf("\n");
  for(int i = 1; i <= n; i++)
  {
    printf("%d ", b[i]);
  }
  printf("\n");
  for(int i = 1; i <= n; i++)
  {
    printf("%d ", c[i]);
  }
  printf("\n");
}

int main()
{
  ReadData();
  Solve();
  WriteData();
  return 0;
}