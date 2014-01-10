#include <stdio.h>
#include <string.h>

char str[1000005];
int z[1000005];
int len, answer;

void CalcZArrayN2()
{
  for(int i = 1; i < len; i++)
  {
    while((i + z[i] < len) && (str[i + z[i]] == str[z[i]]))
    {
      z[i]++;
    }
  }
}

inline int max(int a, int b)
{
  return a > b ? a : b;
}

inline int min(int a, int b)
{
  return a < b ? a : b;
}

void CalcZArrayLinear()
{
  int l = 0, r = 0;
  for(int i = 1; i < len; i++)
  {
    if(i <= r)
    {
      z[i] = min(r - i + 1, z[i - l]);
    }
    while((i + z[i] < len) && (str[i + z[i]] == str[z[i]]))
    {
      z[i]++;
    }
    if(i + z[i] - 1 > r)
    {
      l = i;
      r = i + z[i] - 1;
    }
  }
}

void ReadData()
{
  memset(str, 0, sizeof(char) * 1000005);
  memset(z, 0, sizeof(int) * 1000005);
  scanf("%s\n", &str);
}

void Solve()
{
  len = strlen(str);
  answer = -1;
  if(len < 3)
    return;
  CalcZArrayLinear();
  int maxz = 0;
  for (int i = 1; i < len; i++)
  {
    // z[i] == len - i Суффикс с позиции i равен некоторому префиксу
    // maxz >= len - i Значит левее есть суффикс, равный некоторому префиксу и он как минимум не меньше текущего
    if (z[i] == len-i && maxz >= len-i)
    { 
      answer = len-i;
      break;
    }
    maxz = max(maxz, z[i]);
  }
}

void WriteData()
{
  if(answer == -1)
  {
    printf("Just a legend");
  }
  else
  {
    for(int i = 0; i < answer; i++)
    {
      printf("%c", str[i]);
    }
  }
  printf("\n");
}

int main()
{
  int QWE;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d\n", &QWE);
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