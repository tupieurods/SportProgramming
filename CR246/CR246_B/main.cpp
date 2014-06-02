#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
int a1[100009], a2[100009];
int b1[100009], b2[100009];
int in1[100009], in2[100009];

void ReadData()
{
  scanf("%d", &n);
  memset(b1, 0, sizeof(b1));
  memset(b2, 0, sizeof(b2));
  for(int i = 0; i < n; i++)
  {
    a1[i] = n - 1;
    a2[i] = n - 1;
    scanf("%d %d", &in1[i], &in2[i]);
    b1[in1[i]]++;
    b2[in2[i]]++;
  }
}

void Solve()
{
  for(int i = 0; i < n; i++)
  {
    int change = b1[in2[i]];
    a2[i] -= change;
    a1[i] += change;
  }
}

void WriteData()
{
  for(int i = 0; i < n; i++)
  {
    printf("%d %d\n", a1[i], a2[i]);
  }
  printf("\n");
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