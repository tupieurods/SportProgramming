#include <stdio.h>
#include <limits.h>
#include <string.h>

int **arr, **answerArr;
int n, m, answer;

void ReadData()
{
  answer = INT_MAX;
  scanf("%d %d%*c", &n, &m);
  arr = new int*[n];
  answerArr = new int*[n];
  for(int i = 0; i < n; i++)
  {
    char str[20000];
    scanf("%s", &str);
    arr[i] = new int[m];
    answerArr[i] = new int[m];
    int cnt = 0;
    for(int j = 0; j < m; j++)
    {
      arr[i][j] = (int)(str[j] - '0');
      if(arr[i][j] == 1)
        cnt++;
      answerArr[i][j] = INT_MAX;
    }
    if(cnt == 0)
      answer = -1;
    //printf("%s\n", str);
  }
}

inline int min(int val1, int val2)
{
  return val1 < val2 ? val1 : val2;
}

void Solve()
{
  if(answer == -1)
    return;
  for(int i = 0; i < n; i++)
  {
    int delta1 = 1000000, delta2 = 1000000;
    int index1 = 0, index2 = m - 1;
    for(int j = 0; j < 2 * m; j++)
    {
      if(arr[i][index1] == 1)
      {
        delta1 = 0;
      }
      else
      {
        delta1++;
      }
      answerArr[i][index1] = min(delta1, answerArr[i][index1]);
      index1++;
      if(index1 == m)
        index1 = 0;
      if(arr[i][index2] == 1)
      {
        delta2 = 0;
      }
      else
      {
        delta2++;
      }
      answerArr[i][index2] = min(delta2, answerArr[i][index2]);
      index2--;
      if(index2 == -1)
        index2 = m - 1;
    }
  }
  memset(arr[0], 0, sizeof(int) * m);
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < m; j++)
    {
      arr[0][j] += answerArr[i][j];
    }
  }
  for(int i = 0; i < m; i++)
  {
    answer = min(answer, arr[0][i]);
  }
}

void WriteData()
{
  /*for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < m; j++)
    {
      printf("%d", arr[i][j]);
    }
    printf("\n");
  }*/
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