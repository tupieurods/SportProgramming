#include <iostream>
#include <stdlib.h>
#include <hash_map>

using namespace std;

template<class TKey, class TValue>
class myhashmap
{
public:

	struct Entry
	{
		bool IsUsed;
		pair<TKey, TValue> Pair;
	};

private:
	static const size_t Size = 1 << 20;
	Entry* table;

public:
	myhashmap()
	{
		table = new Entry[Size];
		memset(table, 0, Size * sizeof(table[0]));
	}

	size_t GetHashCode(TKey key)
	{
		return (size_t)(key * 0x080883dd /* какое-нибудь немаленькое простое число */ );
	}

	pair<TKey, TValue>* FindOrInsert(TKey key, TValue defaultValue)
	{
		size_t x = GetHashCode(key) & (Size - 1);
		while (table[x].IsUsed)
		{
			if (table[x].Pair.first == key) return &table[x].Pair;		// found
			x = (x+1) & (Size - 1);
		}

		// not found
		table[x].IsUsed = true;
		table[x].Pair = pair<TKey, TValue>(key, defaultValue);
		return &table[x].Pair;
	}

	TValue FindOrDefault(TKey key, TValue defaultValue)
	{
		size_t x = GetHashCode(key) & (Size - 1);
		while (table[x].IsUsed)
		{
			if (table[x].Pair.first == key) return table[x].Pair.second;		// found
			x = (x+1) & (Size - 1);
		}

		// not found
		return defaultValue;
	}

};


//#define LOCALTEST

int main()
{
  //freopen("_input", "r", stdin);
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
    myhashmap<__int64, int > masks;
    //tr1::unordered_map<char, int> alphabet;
    masks.FindOrInsert(0, 1);
    __int64 currentMask = 0;
    __int64 result = 0;
    //int maxPos = -1;
	pair<__int64, int>* it;
    for(int i = 0; i < n; i++)
    {
      char c;
      cin >> c;
      /*if(alphabet.count(c) == 0)
      {
        alphabet.insert(make_pair(c, alphabet.size()));
      }*/
      int pos = c <= 'Z' ? 'Z' - c : 'z' - c + 26;//alphabet.find(c)->second;//alphabet[c];
      currentMask ^= 1LL << pos;
      //Нечётный гипердром
      //int size = alphabet.size();
      for(int j = 0; j < 52; j++)
      {
        __int64 tmp = 1LL << j;
		int cnt = masks.FindOrDefault(tmp ^ currentMask, 0);
        result += cnt;
      }

	  it = masks.FindOrInsert(currentMask, 0);
      result += it->second++;
    }
    cout << result << endl;
    //masks.clear();
    //alphabet.clear();
  }
  return 0;
}

