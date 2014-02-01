#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>

using namespace std;

int f = 0, s = 1, t = 0;
int cnt[270000],cnt2[2700];

bool invalid()
{
  int key = f * 10000 + s * 100 + t;
  int key2 = s * 100 + t;
  if(cnt[key] < 99 && cnt2[key2] < 1999)
  {
    return false;
  }
  return true;
}

int main()
{
  int letters[50];
  memset(letters, 0, sizeof(letters));
  memset(cnt, 0, sizeof(cnt));
  //freopen("output.txt", "w", stdout);
  printf("ab");
  cnt2[0] = 1;
  for(int i = 2; i < 1000000; i++)
  {
    t = rand() % 26;
    while(invalid() || letters[t] >= 39999)
    {
      t = rand() % 26;
    }
    cnt[f * 10000 + s * 100 + t]++;
    cnt2[s * 100 + t]++;
    letters[t]++;
    f = s;
    s = t;
    printf("%c", 'a' + t);
  }
  return 0;
}
