#include <iostream>
#include <math.h>
#include <set>

using namespace std;

int main()
{
  int n;
  int c;
  int b;
  cin >> n >> c >> b;
  cout << "accept" << endl;
  //Сводим A к нулю
  while(b != 0)
  {
    int newB;
    cin >> newB;
    if(newB <= b)
    {
      b = newB;
      cout << "accept" << endl;
    }
    else
    {
      cout << "decline" << endl;
    }
  }
  //Получаем все веса
  int* omega = new int[n];
  int current = 0;
  while(current != n)
  {
    int newB;
    cin >> newB;
    if(newB > b)
    {
      omega[current++] = newB - b;
      b = newB;
      if(current != n)
      {
        cout << "accept" << endl;
      }
      else
      {
        break;
      }
    }
    else
    {
      cout << "decline" << endl;
    }
  }
  //Debug Вывод всех весов
  /*for(int i = 0; i < n; i++)
  {
  cout << omega[i] << endl;
  }*/
  //Решаем задачу о рюкзаке
  int total = 1 << n;
  int optimal = 0;
  int optimalCode = 0;
  for(int i = 1; i < total; i++)
  {
    int current = 0;
    int copy = i;
    for(int j = 0; j < n; j++)
    {
      current += (copy & 1) * omega[j];
      copy >>= 1;
    }
    if((current <= c) && (current > optimal))
    {
      optimal = current;
      optimalCode = i;
    }
  }
  //Если полученное равно максимум то останавливаемся
  if(optimal == b)
  {
    cout << "stop" << endl;
    return 0;
  }
  cout << "accept" << endl;
  multiset<int> delta;
  for(int i = 0; i < n; i++)
  {
    if((optimalCode & 1) == 0)
    {
      delta.insert(omega[i]);
    }
    optimalCode >>= 1;
  }
  multiset<int>::iterator it;
  while(!delta.empty())
  {
    int newB;
    cin >> newB;
    int bDelta = b - newB;
    it = delta.find(bDelta);
    if(it != delta.end())
    {
      b = newB;
      //Последниый вычет
      if(delta.size() == 1)
      {
        cout << "stop" << endl;
        return 0;
      }
      cout << "accept" << endl;
      delta.erase(it);
    }
    else
    {
      cout << "decline" << endl;
    }
  }
  //Дебажный вывод
  //cout << optimal << endl;
  return 0;
}