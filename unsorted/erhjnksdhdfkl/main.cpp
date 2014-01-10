#include <stdio.h>
#include <set>
#include <cstring>

using namespace std;

int main()
{
  char s[51000];
  int n, v;

  set< pair<int, int> > q;
  int balance = 0;
  __int64 cost = 0;
  gets(s);
  n = strlen(s);

  for(int i = 0; i < n; i++)
    {
      if(s[i] == ')') balance--;
      if(s[i] == '(') balance++;
      if(s[i] == '?')
        {
          int opencost, closecost;
          scanf("%d %d", &opencost, &closecost);
          cost += closecost;
          q.insert(make_pair( opencost - closecost, i) );
          balance--;
          s[i] = ')';
        }
      if(balance < 0)
        {
          if(q.empty()) break;
          s[q.begin()->second] = '(';
          balance += 2;
          cost += q.begin()->first;
          q.erase(q.begin());
        }
    }

  if(balance)
    {
      puts("-1\n");
    }
  else
    {
      printf("%I64d\n", cost);
      puts(s);
    }

  return 0;
}
