#include <stdio.h>
#include <set>

using namespace std;

int n;
int first, second;
int **priors, *alex;

bool compare(int left, int right)
{
  return alex[left] > alex[right];
}

void ReadData()
{
  scanf("%d", &n);
  priors = new int*[n];
  for(int i = 0; i < n; i++)
  {
    priors[i] = new int[n];
    for(int j = 0; j < n; j++)
    {
      int val;
      scanf("%d", &val);
      priors[i][val - 1] = n - j;
    }
  }
  alex = new int[n];
  for(int i = 0; i < n; i++)
  {
    int val;
    scanf("%d", &val);
    alex[val - 1] = n - i;
  }
}

int *answer;
void Solve()
{
  int **table = new int*[n];
  set<int, bool(*)(int, int)> s(compare);
  set<int, bool(*)(int, int)>::iterator it;
  s.insert(0);
  table[0] = new int[n];
  table[0][0] = -1;
  for(int i = 1; i < n; i++)
  {
    s.insert(i);
    table[0][i] = 0;
    table[i] = new int[n];
    it = s.begin();
    for(int j = 0; j < n; j++)
    {
      if(*it != j)
        table[i][j] = *it;
      else
      {
        it++;
        table[i][j] = *it;
        it--;
      }
    }
  }
  answer = new int[n];
  memset(answer, 0xFF, sizeof(int) * n);
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      if(answer[j] == -1 || priors[j][table[i][j]] > priors[j][answer[j]])
      {
        answer[j] = table[i][j];
      }
      //printf("%d ", table[i][j] + 1);
    }
    //printf("\n");
  }

}

void WriteData()
{
  for(int i = 0; i < n; i++)
  {
    printf("%d ", answer[i] + 1);
  }
  printf("\n");
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