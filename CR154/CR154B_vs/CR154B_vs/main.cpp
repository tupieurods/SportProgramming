#include <iostream>
#include <map>
#include <set>
#include <stdlib.h>

using namespace std;

int* data;
//map<__int64, int> cache;

//#define LOCALTEST

int compare(const void* a, const void* b)
{
  return (*(int*)a - *(int*)b);
}

int binarySearch(int value, int start, int end)
{
  //нет искомого элемента
  if (start >= end)
    return -(1 + start);

  //Центр массива
  int mid = start + (end - start) / 2;

  //Если элемент в самой правой границе - искомый
  if (data[end - 1] == value)
    return end - 1;

  //Если в центре искомый элемент
  if (data[mid] == value)
  {
    return data[mid] != data[mid + 1]
      ? mid
      : binarySearch(value, mid + 1, end);
  }

  //Сравнение с центральным элементом
  return data[mid] < value
    //Центральный меньше искомого
    ? binarySearch(value, mid + 1, end)
    //Центральный больше  искомого
    : binarySearch(value, start, mid);
}

/*int f(int start, int finish)
{
if(start > finish)
return INT_MAX;
if(start == finish)
return 0;
if(cache.count((__int64)start * 1000000 + finish) == 0)
{
int result = 0;
if(data[finish] > 2 * data[start])
{
result = 1 + min(f(start + 1, finish), f(start, finish - 1));
}
cache.insert(make_pair((__int64)start * 1000000 + finish, result));
return result;
}
return cache[(__int64)start * 1000000 + finish];
}*/

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int QWE;
#ifdef LOCALTEST
  cin >> QWE;
#else
  QWE = 1;
#endif
  for(int T = 0; T < QWE; T++)
  {
    int n;
    cin >> n;
    data = new int[n];
    for(int i = 0; i < n; i++)
    {
      cin >> data[i];
    }
    qsort(data, n, sizeof(int), compare);
    int len = 0;
#ifdef LOCALTEST
    cout << "New" << endl;
#endif
    //set<int> used;
    for(int i = 0; i < n; i++)
    {
      /*if(used.count(data[i]) != 0)
      continue;
      used.insert(data[i]);*/
      int searchResult = binarySearch(data[i] * 2, 0, n);
#ifdef LOCALTEST
      cout << searchResult << endl;
#endif
      if(searchResult < 0)
      {
        searchResult = abs(searchResult) - 2;
      }
      len = max(len, searchResult - i + 1);
    }
    cout << n - len << endl;
    //cout << f(0, n - 1) << endl;
    delete data;
    //used.clear();
    //cache.clear();
  }
  return 0;
}