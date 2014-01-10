#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <map>

int main()
{
  /*freopen("input.txt", "w", stdout);
  printf("1000000\n");
  for(int i = 0; i < 1000000/2; i++)
    printf("ab");
  return 0;*/
  freopen("input.txt", "r", stdin);
  int n;
  scanf("%d%*c", &n);
  char str[1000005];
  scanf("%s", &str);
  std::map<int, int> m;
  std::map<int, int>::iterator it;
  int current = 0;
  m.insert(std::make_pair(0, 1));
  for(int i = 0; i < n; i++)
  {
    if(str[i] == 'a')
      current--;
    else
      current++;
    it = m.find(current);
    if(it != m.end())
      it->second++;
    else
      m.insert(std::make_pair(current, 1));
  }
  int64_t answer = 0LL;
  for(it = m.begin(); it != m.end(); it++)
  {
    answer += ((int64_t)it->second * ((int64_t)it->second - 1)) / 2;
  }
  printf("%lld\n", answer);
  return 0;
}