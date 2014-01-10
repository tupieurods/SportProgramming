#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define LOCAL

int n, m;
char matrix[1009][1009];

void ReadData()
{
  scanf("%d %d", &n, &m);
}

int answer;
void Solve()
{
  answer = 0;
  memset(matrix, 0, sizeof(matrix));
  int filled = 0;
  int current = 1;
  bool direction = true;
  int line = 0, column = 0;
  char c = 'A';
  while(filled < n * m)
  {
    answer++;
    //Заполнение
    int toFill = current;
    if(n * m < filled + toFill + current + 1)
    {
      toFill = n * m - filled;
    }
    filled += toFill;
    while(toFill != 0)
    {
      matrix[line][column] = c;
      toFill--;
      column += direction ? 1 : -1;
      if(column == -1 || column == m)
      {
        line++;
        direction = !direction;
        column = direction ? 0 : m- 1;
      }
    }
    //Увеличение количества элементов для заполнения
    current++;
    //Получение символа для заполнения
    int mask = (1 << (int)(c - 'A'));
    toFill = current;
    if(n * m < filled + toFill + current + 1)
    {
      toFill = n * m - filled;
    }
    int lineCopy = line, columnCopy = column;
    bool copyDirection = direction;
    while(toFill != 0)
    {
      if(line != 0 && matrix[line - 1][column] != '\0')
      {
        mask |= (1 << (int)(matrix[line - 1][column] - 'A'));
      }
      toFill--;
      column += direction ? 1 : -1;
      if(column == -1 || column == m)
      {
        line++;
        direction = !direction;
        column = direction ? 0 : m- 1;
      }
    }
    line = lineCopy;
    column = columnCopy;
    direction = copyDirection;
    for(int i = 0; i < 26; i++)
    {
      if(((mask >> i) & 1) == 0)
      {
        c = 'A' + i;
        break;
      }
    }
  }
}

void WriteData()
{
  printf("%d\n", answer);
  for(int i = 0; i < n; i++)
  {
    printf("%s\n", matrix[i]);
  }
}

int main()
{
  int QWE = 1;
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  scanf("%d", &QWE);
  #endif
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
}