#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

__int64 n, m;
char str1[1000009], str2[1000009];

void ReadData()
{
  scanf("%I64d %I64d%*c", &n, &m);
  scanf("%s%*c", str1);
  scanf("%s%*c", str2);
}

int gcd(int a, int b)
{
  if(b == 0)
  {
    return a;
  }
  return gcd(b, a % b);
}

__int64 answer;
int cnt[1000009][30];

void Solve()
{
  int len1 = strlen(str1),
    len2 = strlen(str2);
  if(len1 < len2)
  {
    swap(len1, len2);
    swap(str1, str2);
    swap(n, m);
  }
  int g = gcd(len1, len2);
  __int64 nok_len = (len1 * 1LL * len2) / g;
  memset(cnt, 0, sizeof(cnt));
  for(int i = 0; i < len2; i++)
  {
    //Сколько раз встретится конкретная буква в склееной строке от str2
    //в позиции от 0 до НОД(len1, len2). Дальше будет повторяться
    cnt[i % g][(int)(str2[i] - 'a')]++;
  }
  answer = 0;
  for(int i = 0; i < len1; i++)
  {
    //Сколько раз встретится конкретная буква в склееной строке от str1
    //в позиции от 0 до НОД(len1, len2). Дальше будет повторяться
    answer += cnt[i % g][(int)(str1[i] - 'a')];
  }
  answer = ((len1 * n) / nok_len) * (nok_len - answer);
}

void WriteData()
{
  printf("%I64d\n", answer);
}

int main()
{
  int QWE = 1;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d", &QWE);
  #endif
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}