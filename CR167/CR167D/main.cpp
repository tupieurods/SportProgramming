#include <stdio.h>
#include <algorithm>
#include <deque>

using namespace std;

int main()
{
  int n;
  scanf("%d", &n);
  deque<int> data;
  for(int i = 0; i < n; i++)
  {
    int tmp;
    scanf("%d", &tmp);
    data.push_back(tmp);
  }
  int notUniqe = 0;
  for(int i = 0; i < n; i++)
  {
    int tmp;
    scanf("%d", &tmp);
    if(data[i] == tmp)
      notUniqe++;
    data.push_back(tmp);
  }
  __int64 m;
  scanf("%I64d", &m);
  sort(data.begin(), data.end());
  deque<int> UniqeCount;
  int XnotUniqe = 1;
  n *= 2;
  for(int i = 1; i < n; i++)
  {
    if(data[i] != data[i - 1])
    {
      UniqeCount.push_back(XnotUniqe);
      XnotUniqe = 1;
      continue;
    }
    XnotUniqe++;
  }
  UniqeCount.push_back(XnotUniqe);//количество самого большого уникального числа в списке не добавится в цикле
  __int64 answer = 1;
  for(deque<int>::iterator it = UniqeCount.begin(); it != UniqeCount.end(); it++)
  {
    __int64 factorial = 1;
    __int64 currentFactorialElement = 1;
    for(int i = 2; i <= *it; i++)
    {
      currentFactorialElement = i;
      while((notUniqe != 0) && (currentFactorialElement % 2 == 0))
      {
        notUniqe--;
        currentFactorialElement /= 2LL;
      }
      factorial *= currentFactorialElement;
      factorial %= m;
    }
    answer *= factorial;
    answer %= m;
  }
  printf("%I64d", answer);
  return 0;
}
