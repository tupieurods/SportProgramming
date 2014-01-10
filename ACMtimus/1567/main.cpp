#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>

int main()
{
  char arr[11][5] = 
  {
    "abc", "def", "ghi",
    "jkl", "mno", "pqr",
    "stu", "vwx", "yz",
    ".,!", " "
  };
  int len;
  std::map<char, int> m;
  for(int i = 0; i < 11; i++)
  {
    len = strlen(arr[i]);
    for(int j = 0; j < len; j++)
    {
      m.insert(std::make_pair(arr[i][j], j + 1));
    }
  }
  char str[1005];
  gets(str);
  int answer = 0;
  len = strlen(str);
  for(int i = 0; i < len; i++)
  {
    answer += m[str[i]];
  }
  printf("%d\n", answer);
  return 0;
}