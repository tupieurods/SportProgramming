#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

char str[1009];
  int alpha[30];

int main()
{
  int QWE = 1;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d%*c", &QWE);
  #endif
  for(int T = 0; T < QWE; T++)
  {
    scanf("%s%*c", str);
    int k;
    scanf("%d%*c", &k);
    int maximal = 0;
    for(int j = 0; j < 26; j++)
    {
      scanf("%d", &alpha[j]);
      maximal = std::max(maximal, alpha[j]);
    }
    int len = strlen(str);
    __int64 answer = 0;
    for(int i = 0; i < len; i++)
    {
      answer += alpha[str[i] - 'a'] * 1LL * (i + 1);
    }
    for(int i = 0; i < k; i++)
    {
      answer += (len + 1 + i) * 1LL * maximal;
    }
    printf("%I64d\n", answer);
  }
  return 0;
}