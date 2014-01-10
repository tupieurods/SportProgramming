#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, m;
char str1[100009], str2[100009];

void ReadData()
{
  scanf("%s%*c", str1);
  scanf("%s%*c", str2);
  n = strlen(str1);
  m = strlen(str2);
}

int answer;

void Solve()
{
  answer = 0;
  if(m > n)
  {
    return;
  }
  int s[30], p[30];
  memset(s, 0, sizeof(s));
  memset(p, 0, sizeof(p));
  for(int i = 0; i < m; i++)
  {
    p[str2[i] - 'a']++;
    if(str1[i] != '?')
      s[str1[i] - 'a']++;
  }
  int cnt = n - m + 1;
  for(int i = 0; i < cnt; i++)
  {
    bool flag = true;
    for(int j = 0; j < 30; j++)
    {
      if(s[j] > p[j])
      {
        flag = false;
        break;
      }
    }
    if(flag)
    {
      answer++;
    }
    if(i + 1 != cnt)
    {
      if(str1[i] != '?')
        s[str1[i] - 'a']--;
      if(str1[i + m] != '?')
        s[str1[i + m] - 'a']++;
    }
  }
}

void WriteData()
{
  printf("%d\n", answer);
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