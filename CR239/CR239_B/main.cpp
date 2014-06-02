#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

char str1[1009], str2[1009];
int vals[2][200];
int len1, len2;

void ReadData()
{
  scanf("%s%*c", str1);
  scanf("%s%*c", str2);
  len1 = strlen(str1);
  len2 = strlen(str2);
}

int answer;

void Solve()
{
  answer = 0;
  memset(vals, 0, sizeof(vals));
  for(int i = 0; i < len1; i++)
  {
    vals[0][(int)(str1[i] - 'a')]++;
  }
  for(int i = 0; i < len2; i++)
  {
    vals[1][(int)(str2[i] - 'a')]++;
  }
  for(char i = 'a'; i <= 'z'; i++)
  {
    int current = (int)(i - 'a');
    if(vals[1][current] != 0 && vals[0][current] == 0)
    {
      answer = -1;
      return;
    }
    answer += std::min(vals[0][current], vals[1][current]);
  }
}

void WriteData()
{
  printf("%d\n", answer);
}

int main()
{
  int QWE;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d%*c", &QWE);
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