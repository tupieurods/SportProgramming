#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int h, w, n;

void ReadData()
{
  scanf("%d %d %d%*c", &h, &w, &n);
}

int answer;

void Solve()
{
  answer = 0;
  int lines = 0;
  int pos = -1;
  char str[105];
  for(int i = 0; i < n; i++)
  {
    scanf("%s%*c", &str);
    int len = strlen(str);
    if(pos + 1 + len > w)
    {
      lines++;
      pos = len;
    }
    else
    {
      pos += 1 + len;
    }
  }
  lines++;
  answer = lines / h + (int)(lines % h != 0);
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