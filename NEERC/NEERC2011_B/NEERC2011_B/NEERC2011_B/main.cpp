#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <deque>
#include <stdlib.h>

using namespace std;

#define DEBUG

void getNumberOfMinimalBits(int n, int &max, int &countBits)
{
  while(max < n)
  {
    max <<= 1;
    countBits++;
  }
  countBits--;
}

int firstNBitsToInt(char* str, int n)
{
  int result = 0;
  for(int i = 0; i < n; i++)
  {
    result <<= 1;
    if(str[i] == '1')
      result |= 1;
  }
  return result;
}

void PrintNumbersWithNBits(ofstream cout, int n, int bitsCount)
{
  int max = 0;
  for(int i = 0; i < n; i++)
  {
    char* str = new char[15];
    itoa(max, str, 2);
    int len = strlen(str);
    for(int j = 0; j < bitsCount - len; j++)
    {
      cout << 0;
    }
    max++;
    cout << str << endl;
  }
}

int main()
{
  for(int T = 1; T <= 50; T++)
  {
    char str1[7];
    sprintf(str1,"%.2d",T);
    ifstream strm(str1);

    sprintf(str1,"%.2d.a",T);
#ifdef DEBUG
    ofstream cout(str1);
#endif

    int n;
#ifdef DEBUG
    strm >> n;
#else
    cin >> n;
#endif

    int max = 1;
    int count = 1;
    getNumberOfMinimalBits(n, max, count);
#ifdef DEBUG
    //cout << max << endl;
#endif
    //Если n равно некоторому 2^k
    if(max == n)
    {
      int max = 0;
      for(int i = 0; i < n; i++)
      {
        char* str = new char[15];
        itoa(max, str, 2);
        int len = strlen(str);
        for(int j = 0; j < count - len; j++)
        {
          cout << 0;
        }
        max++;
        cout << str << endl;
      }
      //PrintNumbersWithNBits(n, count);
      continue;
    }
    max--;
    int saveCount = count;
    deque< char* > anwser;
    set<int> used;
    char* str;
    for(int j = n; j > 1; j--)
    {
      str = new char[15];
      itoa(max, str, 2);
      string tmp(str);
      int len = strlen(str);
      bool flag = false;
      if(count == saveCount)
      {
        //Проверяем, а может нужно перейти на меньшее число бит
        int ind = firstNBitsToInt(str, len - 1);//len >= count - 1 ? count - 1 : len);
        if(used.count(ind) == 0)
        {
          used.insert(ind);
          if(ind + 1>= j)
          {
            flag = true;
            //count--;
            max = ind;
          }
        }
      }
      for(int i = 0; i < count - len; i++)
      {
        tmp = "0" + tmp;
      }
      if(flag)
        count--;
      memcpy(str, tmp.c_str(), count);
      str[count] = '\0';
      //cout << "debug " << max << " " << str << " " << firstNBitsToInt(str, count) << endl;
      anwser.push_front(str);
      max--;
    }
    //TODO: Переделать вывод нуля
    if((count == saveCount) && (used.count(0) == 0))
      count--;
    for(int i = 0; i < count; i++)
    {
      cout << 0;
    }
    cout << endl;
    for(deque< char* >::iterator i = anwser.begin(); i != anwser.end(); i++)
    {
      cout << *i << endl;
    }
    strm.close();
#ifdef DEBUG
    cout.close();
#endif
  }
  return 0;
}