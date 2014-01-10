#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str1[100009], str2[100009];
int n;

void ReadData()
{
  scanf("%s%*c", str1);
  scanf("%s%*c", str2);
  n = strlen(str1);
}

int answer;

void WriteData();
void Solve()
{
  answer = 0;
  int a[30], b[30];
  memset(a, 0, sizeof(a));
  memset(b, 0, sizeof(b));
  for(int i = 0; i < n; i++)
  {
    a[(int)(str1[i] - 'A')]--;
    a[(int)(str2[i] - 'A')]++;
    b[(int)(str1[i] - 'A')]++;
  }
  for(int i = 0; i < n; i++)
  {
    if(a[(int)(str1[i] - 'A')] < 0)
    {
      int endIndex = (int)(str1[i] - 'A');
      for(int j = 0; j < 26; j++ )
      {
        if(a[j] > 0)
        {
          if(j < endIndex)
          {
            a[endIndex]++;
            a[j]--;
            b[endIndex]--;
            str1[i] = 'A' + (char)j;
            answer++;
            break;
          }
          else
          {
            if(b[endIndex] > abs(a[endIndex]))
            {
              b[endIndex]--;
            }
            else
            {
              b[endIndex]--;
              a[endIndex]++;
              a[j]--;
              str1[i] = 'A' + (char)j;
              answer++;
            }
            break;
          }
        }
      }
    }
  }
  //printf("solved\n");
}

void WriteData()
{
  printf("%d\n", answer);
  printf("%s\n", str1);
}

int main()
{
  int QWE = 1;
  freopen("input.txt", "r", stdin);
#ifdef ONLINE_JUDGE
  freopen("output.txt", "w", stdout);
#else
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