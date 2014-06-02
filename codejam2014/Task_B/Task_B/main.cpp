#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

double c, f, x;

void ReadData()
{
  scanf("%lf %lf %lf", &c, &f, &x);
}

double answer;

void Solve()
{
  answer = x / 2.0;
  double current = 0;
  double adder = 2.0;
  for(int i = 0; i < 200000; i++)
  {
    current += c / adder;
    double realCurrent = current + x / (adder + f);
    adder += f;
    answer = std::min(answer, realCurrent);
    /*if(answer - realCurrent > 1e-7)
    {
      answer = realCurrent;
    }
    else
    {
      break;
    }*/
  }
}

void WriteData()
{
  printf("%.7lf\n", answer);
}

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int QWE;
  scanf("%d", &QWE);
  for(int T = 0; T < QWE; T++)
  {
    printf("Case #%d: ", T + 1);
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}