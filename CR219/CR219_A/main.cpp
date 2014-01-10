#include <stdio.h>
#include <string.h>

int k;
int a[10];
char str[20];

void ReadData()
{
  scanf("%d%*c", &k);
  memset(a, 0, sizeof(a));
  for(int i = 0; i < 4; i++)
  {
    scanf("%s%*c", str);
    for(int j = 0; j < 4; j++)
    {
      if(str[j] == '.')
      {
        continue;
      }
      a[str[j] - '0']++;
    }
  }
}

bool answer;

void Solve()
{
  answer = true;
  k *= 2;
  for(int i = 0; i < 10; i++)
  {
    if(a[i] > k)
    {
      answer = false;
      break;
    }
  }
}

void WriteData()
{
  if(answer)
  {
    printf("YES\n");
  }
  else
  {
    printf("NO\n");
  }
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