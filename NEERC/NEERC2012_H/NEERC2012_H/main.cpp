#include <iostream>
#include <stdlib.h>
#include <string>
#include <unordered_map>

using namespace std;

//#define LOCALTEST

int main()
{
  freopen("hyperdrome.in", "r", stdin);
  freopen("hyperdrome.out", "w", stdout);
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
    std::tr1::unordered_map<__int64, int> masks;
    masks.insert(make_pair(0, 1));
    __int64 currentMask = 0;
    __int64 result = 0;
    std::tr1::unordered_map<__int64, int>::iterator it;
    string line;
    cin >> line;
    for(int i = 0; i < n; i++)
    {
      int pos = line[i] <= 'Z' ? 'Z' - line[i] : 'z' - line[i] + 26;
      currentMask ^= 1LL << pos;
      //Нечётный гипердром
      for(int j = 0; j < 52; j++)
      {
        __int64 tmp = 1LL << j;
        it = masks.find(tmp ^ currentMask);
        if(it != masks.end())
        {
          result += it->second;
        }
      }

      it = masks.find(currentMask);
      if(it != masks.end())
      {
        //Чётный гипердром
        result += it->second++;
      }
      else
      {
        masks.insert(masks.begin(), make_pair(currentMask, 1));
      }
    }
    cout << result << endl;
#ifdef LOCALTEST
    masks.clear();
#endif
  }
  return 0;
}

/*#include <iostream>
#include <stdlib.h>
#include <limits.h>
#include <map>
#include <set>

using namespace std;

//#define LOCALTEST

int main()
{
freopen("input.txt", "r", stdin);
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
map<__int64, int> masks;
map<char, int> alphabet;
masks.insert(make_pair(0, 1));
__int64 currentMask = 0;
__int64 result = 0;
int maxPos = -1;
for(int i = 0; i < n; i++)
{
char c;
cin >> c;
if(alphabet.count(c) == 0)
{
alphabet.insert(make_pair(c, alphabet.size()));
}
int pos = alphabet[c];
currentMask ^= 1LL << pos;
//Нечётный гипердром
for(int j = 0; j < alphabet.size(); j++)
{
__int64 tmp = 1LL << j;
if(masks.count(tmp ^ currentMask) != 0)
{
result += masks[tmp ^ currentMask];
}
}

if(masks.count(currentMask) != 0)
{
//Чётный гипердром
result += masks[currentMask]++;
}
else
{
masks.insert(make_pair(currentMask, 1));
}
}
cout << result << endl;
masks.clear();
alphabet.clear();
}
return 0;
}*/