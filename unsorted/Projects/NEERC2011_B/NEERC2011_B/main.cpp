#include <iostream>
#include <fstream>
#include <deque>
#include <stdlib.h>

using namespace std;

//#define MULTITEST

bool check(int value, int stage)
{
  return (value >= (1<<stage));
}

int main()
{
  for(int T = 1; T <= 50; T++)
  {
    char str1[7];
    sprintf(str1,"%.2d",T);
    //ifstream strm("input.txt");
    ifstream strm(str1);
    //int QWE = 1;
#ifdef MULTITEST
    //strm >> QWE;
#endif
    sprintf(str1,"%.2d.a",T);
    //ofstream cout(str1);

    /*for(int T = 0; T < QWE; T++)
    {*/
    int n;
    cin >> n;
    //strm >> n;
    int max = 1;
    int count = 1;
    while(max < n)
    {
      max <<= 1;
      count++;
    }
    count--;
    //cout << max << endl;
    if(max == n)
    {
      max = 0;
      for(int i = 0; i < n; i++)
      {
        char* str = new char[15];
        itoa(max, str, 2);
        int len = strlen(str);
        for(int j = 0; j < count - len; j++)
        {
          cout << 0;
          //str = '0' + str;
        }
        max++;
        cout << str << endl;
        //system("pause");
        //anwser.push_front(str);
      }
      continue;
    }
    max--;
    int countLeft = 0;
    deque< char* > anwser;
    char* str;
    while(true)
    {
      str = new char[15];
      itoa(max, str, 2);
      if((int)strlen(str) < count)
      {
        break;
      }
      anwser.push_front(str);
      max--;
      countLeft++;
    }
    count--;
    //cout << n - countLeft << endl;
    max = 0;
    //cout << countLeft << endl;
    countLeft = n - countLeft;
    for(int i = 0; i < countLeft; i++)
    {
      char* str = new char[15];
      itoa(max, str, 2);
      int len = strlen(str);
      if(check(max, count-1))
      {
        len--;
      }
      for(int j = 0; j < count - len; j++)
      {
        cout << 0;
        //str = '0' + str;
      }
      max++;
      cout << str << endl;
      //system("pause");
      //anwser.push_front(str);
    }
    for(deque< char* >::iterator i = anwser.begin(); i != anwser.end(); i++)
    {
      cout << *i << endl;
      //system("pause");
    }
    //cout << max << endl << count << endl << str << endl;
    //}
    strm.close();
    //cout.close();
  }
  return 0;
}