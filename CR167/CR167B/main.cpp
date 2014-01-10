#include <stdio.h>
#include <map>

using namespace std;

map<int, int> cache;

int f(int x)
{
  if(x == 0)
    return 0;
  if(cache.count(x) != 0)
    return cache[x];
  int result;
  if(x & 1)
    result = f(x / 2) + 1;
  else
    result = f(x / 2);
  cache.insert(make_pair(x, result));
  return result;
  /*int result = 1;
  int count = 0;
  while(result <= x)
  {
    result <<= 1;
    count++;
  }
  return count;*/
}

int main()
{
  int n;
  scanf("%d", &n);
  __int64 anwser = 0LL;
  map<int, __int64> prefix;
  for(int i = 0; i < n; i++)
  {
    int tmp;
    scanf("%d", &tmp);
    tmp = f(tmp);
    if(prefix.find(tmp) != prefix.end())
      prefix.insert(make_pair(tmp, 0));
    anwser += prefix[tmp];
    prefix[tmp]++;
  }
  printf("%I64d", anwser);
  return 0;
}
