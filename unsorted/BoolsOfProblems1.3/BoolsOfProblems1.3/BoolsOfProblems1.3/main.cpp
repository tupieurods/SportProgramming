#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <set>
#include <sstream>

using namespace std;
string numbers[3];
string anwser[3];
int oldLens[3];
int N;
set<int> cache;

bool f(int pos, bool flag)
{
  if(cache.count(pos * 10000 + (int)flag))
    return false;
  if(pos == N)
  {
    return !flag;
  }
  int first[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int second[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int maxI = 10;
  int maxJ = 10;
  //Первое число
  if(numbers[0][pos]!='?')
  {
    //for(int i = 0; i < 10; i++)
    first[0] = (int)(numbers[0][pos] - '0');
    maxI = 1;
  }
  //Второе число
  if(numbers[1][pos]!='?')
  {
    //for(int i = 0; i < 10; i++)
    second[0] = (int)(numbers[1][pos] - '0');
    maxJ = 1;
  }
  bool res = false;
  for(int i = 0; i < maxI; i++)
  {
    for(int j = 0; j < maxJ; j++)
    {
      if(numbers[2][pos] == '?')
      {
        res = f(pos + 1, (first[i] + second[j] + (int)flag) > 9);
        if(res)
        {
          anwser[0][pos] = '0' + first[i];
          anwser[1][pos] = '0' + second[j];
          anwser[2][pos] = '0' + ((first[i] + second[j] + (int)flag) % 10);
          return true;
        }
      }
      else if((first[i] + second[j] + (int)flag) % 10 == (int)(numbers[2][pos] - '0'))
      {
        res = f(pos + 1, (first[i] + second[j]  + (int)flag) > 9);
        if(res)
        {
          anwser[0][pos] = '0' + first[i];
          anwser[1][pos] = '0' + second[j];
          anwser[2][pos] = '0' + ((first[i] + second[j] + (int)flag) % 10);
          return true;
        }
      }
    }
  }
  cache.insert(pos * 10000 + (int)flag);
  return false;
}

void printNumber(int number)
{
  for(int i = oldLens[number] - 1; i >= 0; i--)
  {
    cout << anwser[number][i];
  }
}

int main()
{
  freopen("input.txt", "r", stdin);
  int QWE = 1;
  for(int T = 0; T < QWE; T++)
  {
    string str;
    getline(std::cin, str);
    int current = 0;
    for(string::iterator it = str.begin(); it != str.end(); it++)
    {
      if((*it == '+') || (*it == '='))
      {
        current++;
        continue;
      }
      numbers[current] += *it;
    }
    N = max(numbers[0].length(), max(numbers[1].length(), numbers[2].length()));
    for(int i = 0; i < 3; i++)
    {
      anwser[i] = string(N, '0');
      //cout << anwser[i] << endl;
      reverse(numbers[i].begin(), numbers[i].end());
      oldLens[i] = numbers[i].length();
      for(int j = 0; j < oldLens[i]; j++)
      {
        anwser[i][j] = numbers[i][j];
      }
      if(oldLens[i] < N)
      {
        for(int j = 0; j < N - oldLens[i]; j++)
        {
          numbers[i] += "0";
        }
      }
    }
    if(f(0, false))
    {
      printNumber(0);
      cout << "+";
      printNumber(1);
      cout << "=";
      printNumber(2);
    }
    else
    {
      cout << "No solution";
    }
  }
  return 0;
}