#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <map>

using namespace std;

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  char str[500009];
  scanf("%s%*c", str);
  int m;
  scanf("%d", &m);
  int len = strlen(str);
  __int64 answer = 0LL;
  map<char, int> s;
  map<char, int>::iterator it;
  int start = 0;
  for(int i = 0; i < len; i++)
  {
    char current = str[i];
    if(current >= 'A' && current <= 'Z')
    {
      current = current - 'A' + 'a';
      str[i] = current;
    }
    it = s.find(current);
    if(it == s.end())
    {
      s.insert(make_pair(current, 1));
    }
    else
    {
      it->second++;
    }
    if(s.size() <= m)
    {
      int n = i - start + 1;
      answer += n;//((1LL + n) * n) / 2LL;
    }
    else
    {
      while(s.size() > m)
      {
        current = str[start];
        it = s.find(current);
        if(it->second == 1)
        {
          s.erase(it);
        }
        else
        {
          it->second--;
        }
        start++;
      }
      int n = i - start + 1;
      answer += n;//((1LL + n) * n) / 2LL;
    }
  }
  printf("%I64d\n", answer);
  return 0;
}