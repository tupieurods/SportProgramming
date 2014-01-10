#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <deque>
#include <math.h>
#include <algorithm>

using namespace std;

//#define LOCALTEST

struct box
{
  __int64 count;
  int pos;
};

bool compare(box a, box b)
{
  return a.count > b.count;
}

int main()
{
  freopen("input.txt", "r", stdin);
  int QWE;
#ifdef LOCALTEST
  cin >> QWE;
#else
  QWE = 1;
#endif
  for(int T = 0; T < QWE; ++T)
  {
    //get input
    deque<box>* boxes = new deque<box>[19];
    __int64 x;
    int n;
    cin >> x >> n;
    for(int i = 1; i <= n; i++)
    {
      int k;
      __int64 q;
      cin >> k >> q;
      box tmp;
      tmp.count = q;
      tmp.pos = i;
      boxes[k].push_back(tmp);
    }
    //end get input

    for(int i = 0; i < 19; i++)
    {
      sort(boxes[i].begin(), boxes[i].end(), compare);
    }

    //solving
    deque<int> opened;
    bool solved = true;
    __int64 freeSum = 0;
    int pos = -1;
    //Проходим всё число
    while(x != 0)
    {
      pos++;
      int last = x % 10;
      __int64 needs = (__int64)pow(10.0, pos) * last;
      x /= 10LL;
      if(last == 0)
        continue;

      bool flag = false;
      needs -= freeSum;
      if(needs <= 0)
      {
        freeSum = _abs64(needs);
        continue;
      }

      freeSum = 0;

      //Поиск суммы
      while(needs > 0)
      {
        __int64 max = 0;
        int toRemove = -1;
        for(int i = pos; i >= 0; --i)
        {
          if(boxes[i].size() > 0)
          {
            if(((__int64)pow(10.0, i) * boxes[i][0].count) > max)
            {
              max = (__int64)pow(10.0, i) * boxes[i][0].count;
              toRemove = i;
              flag = true;
            }
          }
        }
        //Если нашли
        if(toRemove != -1)
        {
          opened.push_back(boxes[toRemove][0].pos);
          boxes[toRemove].pop_front();
          needs -= max;
        }
        else//Не нашли
        {
          flag = false;
          break;
        }
      }

      if(!flag)
      {
        solved = false;
        break;
      }
      else
      {
        freeSum = _abs64(needs);
      }
    }
    //end solving

    //Write Anwser
    if(solved)
    {
      cout << opened.size() << endl;
      for(int i = 0; i < opened.size(); ++i)
      {
        cout << opened[i] << " ";
      }
    }
    else
    {
      cout << -1;
    }
#ifdef LOCALTEST
    cout << "next" << endl;
#else
    cout << endl;
#endif
    //End Write Anwser
  }
  return 0;
}