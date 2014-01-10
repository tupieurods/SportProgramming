#include <stdio.h>
#include <algorithm>

struct date
{
  int year, month, day;
};

date start, finish;
int answer;

int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool checkYear(int year)
{
  if(year % 4 == 0)
  {
    if(year % 100 == 0)
    {
      return year % 400 == 0;
    }
    return true;
  }
  return false;
}

int getYearLen(int year)
{
  return checkYear(year) ? 366: 365;
}

int getMonthLen(int month, int year)
{
  if(month == 2)
    return checkYear(year) ? 29 : 28;
  return months[month - 1];
}

void ReadData()
{
  scanf("%d:%d:%d", &start.year, &start.month, &start.day);
  scanf("%d:%d:%d", &finish.year, &finish.month, &finish.day);
  if(start.year == finish.year)
  {
    if(start.month == finish.month)
    {
      if(start.day > finish.day)
        std::swap(start, finish);
    }
    else if(start.month > finish.month)
    {
      std::swap(start, finish);
    }
  }
  else if(start.year > finish.year)
  {
    std::swap(start, finish);
  }
}

void Solve()
{
  answer = 0;
  if(start.year == finish.year)
  {
    if(start.month == finish.month)
    {
      answer = finish.day - start.day;
    }
    else
    {
      answer = finish.day - 1;
      answer += getMonthLen(start.month, start.year) - start.day + 1;
      for(int currentMonth = start.month + 1; currentMonth < finish.month; currentMonth++)
      {
        answer += getMonthLen(currentMonth, start.year);
      }
    }
  }
  else
  {
    answer = getMonthLen(start.month, start.year) - start.day + 1;
    for(int currentMonth = start.month + 1; currentMonth <= 12; currentMonth++)
    {
      answer += getMonthLen(currentMonth, start.year);
    }
    for(int currentMonth = 1; currentMonth < finish.month; currentMonth++)
    {
      answer += getMonthLen(currentMonth, finish.year);
    }
    answer += finish.day - 1;
  }
  for(int currentYear = start.year + 1; currentYear < finish.year; currentYear++)
  {
    int tmp = getYearLen(currentYear);
    answer += getYearLen(currentYear);
  }
}

void WriteData()
{
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