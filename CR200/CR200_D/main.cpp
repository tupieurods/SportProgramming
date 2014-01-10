#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  #endif
  char str[1000009];
  while(scanf("%s%*c", str) != EOF)
  {
    int len = strlen(str);
    std::stack<char> st;
    for(int i = 0; i < len; i++)
    {
      if(st.size() == 0 || st.top() != str[i])
      {
        st.push(str[i]);
      }
      else
      {
        st.pop();
      }
    }
    if(st.size() == 0)
    {
      printf("Yes\n");
    }
    else
    {
      printf("No\n");
    }
  }
  return 0;
}