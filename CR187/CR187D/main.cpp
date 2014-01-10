#include <stdio.h>
#include <string.h>

int b, d;
char a[105], c[105];

void ReadData()
{
  scanf("%d %d%*c", &b, &d);
  scanf("%s", &a);
  scanf("%s", &c);
}

int answer;
int l1, l2;

void Solve()
{
  l1 = strlen(a);
  l2 = strlen(c);
  //arr[i] сколько букв из l2 циклически совпадают в строке
  //l1, если было установлено i букв
  int *arr = new int[l2];
  for(int i = 0; i < l2; i++)
  {
    int cnt = 0;
    for(int j = 0; j < l1; j++)
    {
      if(c[(i + cnt) % l2] == a[j])
        cnt++;
    }
    arr[i] = cnt;
  }
  answer = 0;
  for(int i = 0; i < b; i++)
  {
    answer += arr[answer % l2];
  }
}

void WriteData()
{
  printf("%d\n", answer / (l2 * d));
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