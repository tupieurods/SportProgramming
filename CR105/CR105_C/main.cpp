#include <stdio.h>
#include <stdlib.h>
#include <vector>

int n, a, b;

void ReadData()
{
  scanf("%d %d %d", &n, &a, &b);
}

std::vector<int> answer;

void Solve()
{
  answer.clear();
  if(n == 1)
  {
    answer.push_back(1);
    return;
  }
  if(b > n - 1 || a > n - 2)
  {
    return;
  }
  answer.push_back(1);
  n--;
  int sum = 1;
  for(int i = 0; i < b; i++)
  {
    sum += answer[answer.size() - 1];
    answer.push_back(sum);
  }
  if(b == 0)
  {
    answer.push_back(1);
    n--;
  }
  for(int i = 0; i < a; i++)
  {
    answer.push_back(answer[answer.size() - 1] + 1);
  }
  int last = n - a - b;
  for(int i = 0; i < last; i++)
  {
    answer.push_back(1);
  }
}

void WriteData()
{
  if(answer.size() == 0)
  {
    printf("-1\n");
    return;
  }
  for(std::vector<int>::iterator it = answer.begin(); it != answer.end(); it++)
  {
    printf("%d ", *it);
  }
  printf("\n");
}

int main()
{
  int QWE = 1;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
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