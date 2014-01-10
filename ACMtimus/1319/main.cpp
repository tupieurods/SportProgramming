#include <stdio.h>

int main()
{
  int answer[100][100];
  int n;
  //ReadData
  scanf("%d", &n);
  //Solve
  int current = n * n;
  int cnt = 1;
  int column = 0;
  int line = n - 1;
  while(current != 0)
  {
    for(int i = 0; i < cnt; i++)
    {
      answer[line - i][column - i] = current;
      current--;
    }
    if(column == n - 1)
    {
      line--;
      cnt--;
    }
    else
    {
      cnt++;
      column++;
    }
  }
  //WriteAnswer
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      printf("%d ", answer[i][j]);
    }
    printf("\n");
  }
}