#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int min(int a, int b)
{
  return a < b ? a : b;
}

int max(int a, int b)
{
  return a > b ? a : b;
}

int r, g, b;

void ReadData()
{
  scanf("%d %d %d", &r, &g, &b);
}

int answer;

void Solve()
{
  int copyR = r, copyG = g, copyB = b;
  answer = r / 3 + g / 3 + b / 3;
  r /= 3, g /= 3, b /= 3;
  r = copyR - r * 3;
  g = copyG - g * 3;
  b = copyB - b * 3;
  answer += min(r, min(g, b));
  r = copyR, g = copyG, b = copyB;
  int check = min(r, min(g, b));
  r -= check;
  g -= check;
  b -= check;
  check += r / 3;
  check += g / 3;
  check += b / 3; 
  answer = max(answer, check);
  r = copyR, g = copyG, b = copyB;
  check = min(r, min(g, b));
  if(check > 2)
  {
    check = 2 + (r - 2) / 3 + (g - 2) / 3 + (b - 2) / 3;
  }
  answer = max(answer, check);
}

void WriteData()
{
  printf("%d\n", answer);
}

int main()
{
  if(!true)
  {
    srand(time(NULL));
    freopen("out.txt", "w", stdout);
    for(int i = 0; i < 100000; i++)
    {
      r = rand() % 1000000001;
      g = rand() % 1000000001;
      b = rand() % 1000000001;
      printf("%d %d %d\n", r, g, b);
      Solve();
      WriteData();
    }
    return 0;
  }
  ReadData();
  Solve();
  WriteData();
  return 0;
}