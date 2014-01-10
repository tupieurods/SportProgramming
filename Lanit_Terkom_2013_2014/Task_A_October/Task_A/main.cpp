#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
//#include <hash_map>

using namespace std;

int n, heapSize;
int a_in[500009], a[500009];

int compare(const void *v1, const void *v2)
{
  return *(int*)v1 - *(int*)v2;
}

void ReadData()
{
  scanf("%d", &n);
  /*stdext::hash_map<int, int> m;
  stdext::hash_map<int, int>::iterator it;*/
  for(int i = 0; i < n; i++)
  {
    //int val;
    //scanf("%d", &val);
    scanf("%d", &a_in[i]);
    /*it = m.find(val);
    if(it == m.end())
    {
      m.insert(make_pair(val, 1));
    }
    else
    {
      it->second++;
    } */
  }
  qsort(a_in, n, sizeof(int), compare);
  heapSize = 1;
  //memset(a, 0, sizeof(a));
  for(int i = 0; i < n; i++)
  {
    if(i == 0 || a_in[i] == a_in[i - 1])
    {
      a[heapSize]++;
    }
    else
    {
      heapSize++;
      a[heapSize] = 1;
    }
    //a[heapSize + 1] = it->second;
    //heapSize++;
  }
}

void heapify(int index)
{
  int newIndex = index;
  do
  {
    index = newIndex;
    int l = index * 2;
    int r = index * 2 + 1;
    if(l <= heapSize && a[l] > a[newIndex])
    {
      newIndex = l;
    }
    if(r <= heapSize && a[r] > a[newIndex])
    {
      newIndex = r;
    }
    swap(a[index], a[newIndex]);
  }while(newIndex != index);
}

int getMax()
{
  int maximal = a[1];
  a[1] = a[heapSize];
  a[heapSize] = 0;
  heapSize--;
  heapify(1);
  return maximal;
}

void heapInsert(int val)
{
  heapSize++;
  int index = heapSize;
  while(index > 1 && a[index / 2] < val)
  {
    a[index] = a[index / 2];
    index /= 2;
  }
  a[index] = val;
}

void heapDelete(int index)
{
  if(index == 1)
  {
    a[1] = a[heapSize];
    a[heapSize] = 0;
    heapSize--;
    heapify(1);
    return;
  }
  if(index == heapSize)
  {
    a[heapSize] = 0;
    heapSize--;
    return;
  }
  int val = a[index];
  a[index] = a[heapSize];
  a[heapSize] = 0;
  heapSize--;
  if(val > a[index])
  {
    heapify(index);
  }
  else
  {
    while(index > 1 && a[index / 2] < val)
    {
      a[index] = a[index / 2];
      index /= 2;
    }
    a[index] = val;
  }
}

int answer;

void Solve()
{
  answer = 0;
  for(int i = heapSize / 2; i > 0; i--)
  {
    heapify(i);
  }
  int b[3];
  b[2] = 1;
  //b[0] = 0, b[1] = 0;
  while(heapSize >= 3)
  {
    answer++;
    b[0] = 0, b[1] = 0;
    for(int i = 2; i < 8; i++)
    {
      if(a[i] > a[b[0]])
      //if(a[i] >= a[b[0]])
      {
        b[1] = b[0];
        b[0] = i;
      }
      else if(a[i] > a[b[1]])
      {
        b[1] = i;
      }
    }
    if(b[1] > b[0])
    {
      swap(b[0], b[1]);
    }
    for(int i = 0; i < 3; i++)
    {
      if(a[b[i]] == 1)
      {
        heapDelete(b[i]);
      }
      else
      {
        a[b[i]]--;
        heapify(b[i]);
      }
    }
  }
}

void WriteData()
{
  printf("%d\n", answer);
}

//#define LOCAL

int main()
{
  int QWE = 1;
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  scanf("%d", &QWE);
#endif
  for(int T = 0; T < QWE; T++)
  {
#ifdef LOCAL
    clock_t tm = clock();
#endif
    ReadData();
    Solve();
    WriteData();
#ifdef LOCAL
    tm = clock() - tm;
    printf("time: %.10lf\n", (float)tm / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}

//#include <stdio.h>
//#include <stdlib.h>
//
//int n;
//int a[500009];
//
//void ReadData()
//{
//  scanf("%d", &n);
//  for(int i = 0; i < n; i++)
//  {
//    scanf("%d", &a[i]);
//  }
//}
//
//int compare(const void *v1, const void *v2)
//{
//  return *(int*)v1 - *(int*)v2;
//}
//
//bool check(int k)
//{
//  if(n / 3 < k)
//  {
//    return false;
//  }
//  int j = k;
//  for(int i = 0; i < k; i++)
//  {
//    if(j >= n - k)
//    {
//      return false;
//    }
//    if(a[i] == a[n - k + i])
//    {
//      return false;
//    }
//    while(j < n - k && (a[i] == a[j] || a[n - k + i] == a[j]))
//    {
//      j++;
//    }
//    j++;
//  }
//  if(j > n - k)
//  {
//    return false;
//  }
//  return true;
//}
//
//int answer;
//
//void Solve()
//{
//  answer = 0;
//  qsort(a, n, sizeof(int), compare);
//  int l = 0, r = n;
//  while(r - l >5)
//  {
//    int center = l + (r - l) / 2;
//    if(check(center))
//    {
//      l = center;
//    }
//    else
//    {
//      r = center;
//    }
//  }
//  for(int i = l; i <= r; i++)
//  {
//    if(check(i))
//    {
//      answer = i;
//    }
//    else
//    {
//      break;
//    }
//  }
//}
//
//void WriteData()
//{
//  printf("%d\n", answer);
//}
//
////#define LOCAL
//
//int main()
//{
//  int QWE = 1;
//#ifdef LOCAL
//  freopen("input.txt", "r", stdin);
//  scanf("%d", &QWE);
//#endif
//  for(int T = 0; T < QWE; T++)
//  {
//    ReadData();
//    Solve();
//    WriteData();
//  }
//  return 0;
//}