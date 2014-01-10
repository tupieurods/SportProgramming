#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <stdlib.h>
#include <strings.h>

using namespace std;

//Варианты комбинаций нижних линий которые могут получиться
//в нижнем поле при заданном верхнем
vector< map<int, int> > vars;
//Пусть n-число столбцов в строке
//M- число строк
int n, m, current;
__int64** cache;

bool isBitOff(int value, int nBit)
{
  return (value >> (nBit - 1) & 1) == 0;
}

int setBit(int value, int pos)
{
  return (value | (1 << (pos - 1)));
}

void addToVars(int top, int value)
{
  if(vars[current].count(value) == 0)
    vars[current].insert(make_pair(value, 1));
  else
    vars[current][value]++;
}

void gen(int top, int down/*,int depth*/)
{
  for(int i = 1; i <= n; i++)
  {
    if(isBitOff(top, i)) //Можно заполнить ячейку
    {
      if(i != n)//не на правой границе поля
      {
        //Пробуем вставить элемент 11
        if(isBitOff(top, i + 1))
        {
          int tmp = setBit(setBit(top, i), i + 1);
          //printf("#1\n");
          if(tmp == ((1 << n) - 1))
            addToVars(top, down);
          else
            gen(tmp, down/*,depth+1*/);
          if(isBitOff(down, i + 1))
          {
            /*Пробуем вставить элемент
            11
            01
            */
            //printf("#2\n");
            if(tmp == ((1 << n) - 1))
              addToVars(top, setBit(down, i + 1));
            else
              gen(tmp, setBit(down, i + 1)/*,depth+1*/);
          }
          if(isBitOff(down, i))
          {
            /*Пробуем вставить элемент
            11
            10
            */
            //printf("#3\n");
            if(tmp == ((1 << n) - 1))
              addToVars(top, setBit(down, i));
            else
              gen(tmp, setBit(down, i)/*,depth+1*/);
          }
        }
      }
      if(isBitOff(down, i)) //Есть место снизу
      {
        /*Пробуем вставить элемент
        1
        1
        */
        int tmp = setBit(down, i);
        int newTop = setBit(top, i);
        //printf("#4\n");
        if(newTop == ((1 << n) - 1))
          addToVars(top, tmp);
        else
          gen(newTop, tmp/*,depth+1*/);

        if(i != n && isBitOff(down, i + 1)) //Если не у правой границы поля
        {
          /*Пробуем вставить элемент
          10
          11
          */
          //printf("#5\n");
          if(newTop == ((1 << n) - 1))
            addToVars(top, setBit(tmp, i + 1));
          else
            gen(newTop, setBit(tmp, i + 1)/*,depth+1*/);
        }
        if(i != 1 && isBitOff(down, i - 1)) //Если не у левой границы поля
        {
          /*Пробуем вставить элемент
          01
          11
          */
          //printf("#6\n");
          if(newTop == ((1 << n) - 1))
            addToVars(top, setBit(tmp, i - 1));
          else
            gen(newTop, setBit(tmp, i - 1)/*,depth+1*/);
        }
      }
      return;
    }
  }
  addToVars(0, 0);
}

void generateVars()
{
  for(int i = 0; i < (1 << n); i++)
  {
    vars.push_back(map<int, int>());
  }
  for(int i = 0; i < (1 << n); i++)
  {
    //printf("i=%d\n",i);
    current = i;
    gen(i, 0);
  }
}

__int64 f(int line, int state)
{
  //printf("line:%d state:%d\n", line, state);
  if(line == 1)
  {
    return ((state == ((1 << n) - 1)) || (vars[state].count(0) != 0)) ? 1 : 0;
  }
  //printf("%d\n",cache[line-1][state]);
  if(cache[line-1][state] != -1)
    return cache[line-1][state];
  __int64 result = 0;
  for(map<int, int>::iterator j = vars[state].begin(); j != vars[state].end(); j++)
  {
    result += j->second * f(line - 1, j->first);
  }
  cache[line-1][state] = result;
  return result;
}

int main()
{
  /*m = 9;
  n = 9;*/
  scanf("%d %d", &m, &n);
  //printf("%d",((1 << n) - 1));
  generateVars();
  /*char buff[33];
  for(int i = 0; i < vars.size(); i++)
  {
    itoa(i, buff, 2);
    printf("%d %s:\n", i, buff);
    for(map<int, int>::iterator j = vars[i].begin(); j != vars[i].end(); j++)
    {
      itoa(j->first, buff, 2);
      printf("%s\t %d\n", buff, j->first);
    }
  }*/
  cache = new __int64*[m];
  for(int i = 0; i < m; i++)
  {
    cache[i] = new __int64[1<<n];
    memset(cache[i], 0xFF, sizeof(__int64)*(1<<n));
  }
  //printf("%d\n",cache[2][1]);
  printf("%I64d\n", f(m, 0));
  return 0;
}
