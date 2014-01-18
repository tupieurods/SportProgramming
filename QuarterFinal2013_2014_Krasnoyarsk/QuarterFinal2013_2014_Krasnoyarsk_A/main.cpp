#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <map>
#include <set>

using namespace std;

typedef unsigned int uint;

template <uint alphabet, uint mod>
class slidingHash
{
private:
  int _windowSize;
public:
  uint hash;
  uint st;
  int current;
  slidingHash(const char *str, int windowSize)
  {
    _windowSize = windowSize;
    hash = 0;
    st = 1;
    for(int i = 0; i < windowSize; i++)
    {
      hash = (hash * alphabet + str[i]) % mod;
      if(i > 0)
      {
        st = (st * alphabet) % mod;
      }
    }
    current = windowSize;
  }

  void moveNext(const char *str)
  {
    uint minus = st * str[current - _windowSize] % mod;
    if(hash >= minus)
    {
      hash -= minus;
    }
    else
    {
      hash = hash - minus + mod;
    }
    hash = (hash * alphabet + str[current]) % mod;
    current++;
  }
};

struct mapKey
{
  uint h1, h2, h3;

  bool operator <(const mapKey &o1)
  {
    if(h1 == o1.h1)
    {
      if(h2 == o1.h2)
      {
        return h3 < o1.h3;
      }
      return h2 < o1.h2;
    }
    return h1 < o1.h1;
  }

  /*bool operator <(const mapKey &o1, const mapKey &o2)
  {
  if(o1.h1 == o2.h1)
  {
  if(o1.h2 == o2.h2)
  {
  return o1.h3 < o2.h3;
  }
  return o1.h2 < o2.h2;
  }
  return o1.h1 < o2.h1;
  }*/
};

bool operator <(const mapKey &o1, const mapKey &o2)
{
  if(o1.h1 == o2.h1)
  {
    if(o1.h2 == o2.h2)
    {
      return o1.h3 < o2.h3;
    }
    return o1.h2 < o2.h2;
  }
  return o1.h1 < o2.h1;
}

bool operator >(const mapKey &o1, const mapKey &o2)
{
  if(o1.h1 == o2.h1)
  {
    if(o1.h2 == o2.h2)
    {
      return o1.h3 > o2.h3;
    }
    return o1.h2 > o2.h2;
  }
  return o1.h1 > o2.h1;
}

bool operator ==(const mapKey &o1, const mapKey &o2)
{
  return o1.h1 == o2.h1 && o1.h2 == o2.h2 && o1.h3 == o2.h3;
}

bool operator !=(const mapKey &o1, const mapKey &o2)
{
  return o1.h1 != o2.h1 && o1.h2 != o2.h2 && o1.h3 != o2.h3;
}

int k;
char str[100009];
map<mapKey, pair<mapKey, bool>> m;

void ReadData()
{
  scanf("%d%*c", &k);
  scanf("%s%*c", str);
}

int answer;

void Solve()
{
  m.clear();
  answer = 0;
  slidingHash<128, 33554393> hash1(str, k);
  slidingHash<128, 33554383> hash2(str, k);
  slidingHash<128, 33554371> hash3(str, k);
  int len = strlen(str);
  mapKey prev = {hash1.hash, hash2.hash, hash3.hash};
  mapKey unreal = {INT_MAX, INT_MAX, INT_MAX};
  m.insert(make_pair(prev, make_pair(unreal, false)));
  map<mapKey, pair<mapKey, bool>>::iterator it;
  for(int i = 1; i + k <= len; i++)
  {
    hash1.moveNext(str);
    hash2.moveNext(str);
    hash3.moveNext(str);
    mapKey current = {hash1.hash, hash2.hash, hash3.hash};
    it = m.find(current);
    if(it == m.end())
    {
      m.insert(make_pair(current, make_pair(unreal, false)));
    }
    it = m.find(prev);
    if(it->second.first == unreal)
    {
      it->second.first = current;
    }
    else
    {
      if(it->second.first != current)
      {
        it->second.second = true;
      }
    }
    prev = current;
  }
  for(it = m.begin(); it != m.end(); it++)
  {
    if(it->second.second)
    {
      answer++;
    }
  }
}

void WriteData()
{
  printf("%d\n", answer);
}

int main()
{
  /*__int64 n = ((1LL << 32) - 127) / 128 + 1;
  while(true)
  {
  n--;
  bool flag = true;
  for(int i = 2; i * 1LL * i <= n; i++)
  {
  if(n % i == 0)
  {
  flag = false;
  }
  }
  if(flag)
  {
  printf("%I64d\n", n);
  //return 0;
  }
  }*/
  /*char str[] = "sdhgjkjsdklgsdjgjsdklgjdfjgdjfkgjdfkjghkdfjhkdfjkhdfjklhjdfkjhdkfjhkdfjhksdjsgkldk";
  slidingHash<128, 33554393> hash1(str, 10);
  slidingHash<128, 33554383> hash2(str, 10);
  slidingHash<128, 33554371> hash3(str, 10);
  for(int i = 0 ; i < 5; i++)
  {
  printf("%u %u %u\n", hash1.hash, hash2.hash, hash3.hash);
  hash1.moveNext(str);
  hash2.moveNext(str);
  hash3.moveNext(str);
  }
  return 0;*/
  time_t check = clock();
  int QWE = 1;
  //freopen("input.txt", "r", stdin);
  //freopen("debruijn.in", "r", stdin);
  //freopen("debruijn.out", "w", stdout);
  //scanf("%d", &QWE);
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  check = clock() - check;
  //printf("%lf", ((float)check)/CLOCKS_PER_SEC);
  return 0;
}