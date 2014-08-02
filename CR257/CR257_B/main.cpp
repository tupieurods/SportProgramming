//Contest solution fix
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  const __int64 MOD = 1000000007;
  __int64 a, b, c;
  __int64 n;
  scanf("%I64d %I64d %I64d", &a, &b, &n);
  c = b - a;
  __int64 answer;
  if(n % 3 == 0)
  {
    answer = c;
  }
  else if(n % 3 == 1)
  {
    answer = a;
  }
  else
  {
    answer = b;
  }
  if((((n - 1) / 3) % 2) == 1)
  {
    answer *= -1;
  }
  while(answer < 0)
  {
    answer += MOD;
  }
  printf("%I64d\n", answer % MOD);
  return 0;
}

//After contest solution
/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  const __int64 MOD = 1000000007;
  __int64 a, b, c;
  __int64 n;
  scanf("%I64d %I64d %I64d", &a, &b, &n);
  __int64 answer[6];
  answer[0] = a;
  answer[1] = b;
  answer[2] = b - a;
  answer[3] = -a;
  answer[4] = -b;
  answer[5] = -b + a;
  int idx = n % 6;
  if(idx == 0)
  {
    idx = 5;
  }
  else
  {
    idx--;
  }
  while(answer[idx] < 0)
  {
    answer[idx] += MOD;
  }
  printf("%I64d\n", answer[idx] % MOD);
  return 0;
} */