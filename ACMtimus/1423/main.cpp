#include <stdio.h>
#include <string.h>

int n;
char s1[250009], s2[250009];
int answer;
unsigned __int64 pattern, t;
const unsigned __int64 d = 223LL;
//const unsigned __int64 mod = 1000000007LL;

void ReadData()
{
  scanf("%d%*c", &n);
  scanf("%s", &s1);
  scanf("%s", &s2);
}

void Solve()
{
  pattern = (unsigned __int64)s1[0];
  t = (unsigned __int64)s2[0];
  unsigned __int64 h = 1LL;
  for(int i = 1; i < n; i++)
  {
    h *= d;
    pattern = pattern * d + (unsigned __int64)s1[i];
    t = t * d + (unsigned __int64)s2[i];
    /*h %= mod;
    pattern %= mod;
    t %= mod;*/
  }
  answer = 0;
  for(int i = 0; i < n; i++)
  {
    /*if(answer == 9)
      //printf("valid");*/
    if(pattern == t)
    {
      int j = 0;
      int index = i;
      while(j < n && s1[j] == s2[index])
      {
        index++;
        index %= n;
        j++;
      }
      if(j == n)
        return;
    }
    answer++;
    t = d * (t - (unsigned __int64)s2[i] * h) + (unsigned __int64)s2[i];
    //t %= mod;
    //printf("%I64d %I64d\n", pattern, t);
  }
  if(pattern != t)
    answer = -1;
  //printf("%I64u %I64u\n", pattern, t);
}

void WriteData()
{
  printf("%d\n", answer);
}

int main()
{
  if(!true)
  {
    freopen("input.txt", "w", stdout);
    printf("1\n250000\n");
    for(int i = 1; i < 250000; i++)
    {
      printf("a");
    }
    printf("b\n");
    printf("b");
    for(int i = 1; i < 250000; i++)
    {
      printf("a");
    }
    printf("\n");
    return 0;
  }
  int QWE;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d", &QWE);
  #else
  QWE = 1;
  #endif
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}