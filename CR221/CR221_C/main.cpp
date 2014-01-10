#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[1000009];
int len;

void ReadData()
{
  scanf("%s%*c", str);
  len = strlen(str);
}

bool used[4];
int nums[4] = {1, 6, 8, 9};
int perms[] = { 1689, 1698, 1869, 1896, 1968, 1986, 6189, 6198, 6819, 6891, 6918, 6981, 8169, 8196, 8619, 8691, 8916, 8961, 9168, 9186, 9618, 9681, 9816, 9861};

void genPerm(int last, int perm)
{
  if(last == 0)
  {
    printf("%d, ", perm);
    return;
  }
  for(int i = 0; i < 4; i++)
  {
    if(!used[i])
    {
      used[i] = true;
      genPerm(last - 1, perm * 10 + nums[i]);
      used[i] = false;
    }
  }
}

void Solve()
{
  int zeroCnt = 0;
  bool used[10];
  memset(used, true, sizeof(used));
  used[1] = false, used[6] = false, used[8] = false, used[9] = false;
  int current = 0;
  for(int i = 0; i < len; i++)
  {
    int digit = str[i] - '0';
    if(digit == 0)
    {
      zeroCnt++;
    }
    else if(used[digit] == false)
    {
      used[digit] = true;
    }
    else
    {
      printf("%d", digit);
      current = (current * 10 + digit) % 7;
    }
  }
  for(int i = 0; i < 24; i++)
  {
    if((current * 10000 + perms[i]) % 7 == 0)
    {
      printf("%d", perms[i]);
      break;
    }
  }
  for(int i = 0; i < zeroCnt; i++)
  {
    printf("0");
  }
}

void WriteData()
{
  printf("\n");
}

int main()
{
  if(false)
  {
    printf("{ ");
    genPerm(4, 0);
    printf(" }\n");
    return 0;
  }
  int QWE = 1;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d%*c", &QWE);
#endif
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}