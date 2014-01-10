#include <iostream>
#include <string>
#include <set>
#include <hash_map>
#include <deque>
#include <stdlib.h>
#include <string.h>

using namespace std;

//#define LOCALTEST

int main()
{
  int QWE;
#ifdef LOCALTEST
  freopen("input.txt", "r", stdin);
  cin >> QWE;
#else
  QWE = 1;
#endif
  for(int T = 0; T < QWE; T++)
  {
    string str;
#ifdef LOCALTEST
    getline(cin, str);
#endif
    getline(cin, str);
    //__int64 sWord = 0;
    int count = (str.length() + 1) / 4;
    //set<char> dangerStr;
    hash_map<int, int> danger;
    hash_map<int, int>::iterator mapIt;
    //string shit;
    for(int i = 0; i < count; i++)
    {
      int key = (int)str[i * 4] * 10000 + (int)str[i * 4 + 1] * 1000 + (int)str[i * 4 + 2] * 100;
      mapIt = danger.find(key);
      if(mapIt != danger.end())
      {
        mapIt->second++;
      }
      else
      {
        danger.insert(make_pair(key, 1));
      }
    }
    //cout << sWord << endl;
    //cout << dangerStr << endl;


    char symb;
    __int64 anwser = 0;
    int current = 1;
    deque<int> currentWord;
    hash_map<int, int> charsCount;
    int pows[4] = {1, 10, 100, 1000};
    while(cin.get(symb))
    {
      int key = (int)symb * 10000;// + (int)str[i * 4 + 1] * 1000 + (int)str[i * 4 + 1] * 100;
      //Читаем до конца строчки
      int i = 1;
      while(cin.get(symb) && (i != 3))
      {
        key += (int)symb * 10000/pows[i];
        i++;
      }
      currentWord.push_back(key);
      mapIt = charsCount.find(key);
      if(mapIt != charsCount.end())
      {
        mapIt->second++;
      }
      else
      {
        charsCount.insert(make_pair(key, 1));
      }
      if(current >= count)
      {
        if(current != count)
        {
          charsCount[currentWord[0]]--;
          currentWord.pop_front();
        }
        //__int64 currentCost = 0;
        bool flag = true;
        for(mapIt = danger.begin(); mapIt != danger.end(); mapIt++)
        {
          if(mapIt->second != charsCount[mapIt->first])
          {
            flag = false;
            break;
          }
        }
        if(flag)
          anwser++;
      }
      current++;
    }
    cout << anwser << endl;
  }
  return 0;
}