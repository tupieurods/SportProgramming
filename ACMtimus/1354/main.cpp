#include <stdio.h>
#include <string.h>

char str[100009];
int n;

bool ReadData()
{
  int result = scanf("%s", &str);
  return result != EOF;
}

inline int min(int v1, int v2)
{
  return v1 < v2 ? v1 : v2;
}

inline int max(int v1, int v2)
{
  return v1 > v2 ? v1 : v2;
}

int d1[100009], d2[100009];
int d1Answer, d2Answer, d1AnswerPrev, d2AnswerPrev;
bool allEqual;

void Solve()
{
  n = strlen(str);
  allEqual = true;
  int l1 = 0, r1 = -1, l2 = 0, r2 = -1;
  for(int i = 0; i < n; i++)
  {
    if(str[i] != str[0])
      allEqual = false;
    int k1 = i > r1 ? 0 : min(d1[l1 + r1 - i], r1 - i);
    while(i - k1 >= 0 && i + k1 < n && str[i - k1] == str[i + k1]) k1++;
    d1[i] = k1;
    k1--;
    if(i + k1 > r1)
    {
      l1 = i - k1;
      r1 = i + k1;
    }

    int k2 = (i > r2 ? 0 : min(d2[l2 + r2 - i + 1], r2 - i + 1)) + 1;
    while(i - k2 >= 0 && i + k2 - 1 < n && str[i - k2] == str[i + k2 - 1]) k2++;
    k2--;
    d2[i] = k2;
    if(i + k2 - 1 > r2)
    {
      l2 = i - k2;
      r2 = i + k2 - 1;
    }
  }
  
  d1Answer = n - 1;
  d2Answer = n - 1;
  for(int i = n - 1; i >= 0; i--)
  {
    if(n - i == d1[i])
    {
      d1AnswerPrev = d1Answer;
      d1Answer = i;
    }
    if(n - i == d2[i])
    {
      d2AnswerPrev = d2Answer;
      d2Answer = i;
    }
  }
}

void WriteData()
{
  printf("%s", str);
  int len1 = d1[d1Answer] * 2 - 1;
  int len2 = d2[d2Answer] * 2;
  int index = min(n - 1 - len1, n - 1 - len2);
  if(len2 == 0)
    index = n - 1 - len1;
  if(allEqual)
    index = 0;
  if(index == -1)
  {
    if(n % 2 == 1)
    {
      len1 = d1[d1AnswerPrev] * 2 - 1;
      index = min(n - 1 - len1, n - 1 - len2);
    }
    else
    {
      len2 = d1[d2AnswerPrev] * 2;
      index = min(n - 1 - len1, n - 1 - len2);
      //printf("NotImplemented\n");
      //return;
    }
  }
  for(int i = index; i >= 0; i--)
  {
    printf("%c", str[i]);
  }
  printf("\n");
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
  #endif
  while(ReadData())
  {
    Solve();
    WriteData();
  }
  return 0;
}