#include <stdio.h>
#include <string.h>

char str[10000009];

void ReadData()
{
  scanf("%s", &str);
}

bool answer;

void Solve()
{
  answer = true;
  int n = strlen(str);
  int pos = n - 1;
  while(pos > 0)
  {
    switch(str[pos])
    {
    case 'e':
      {
        if(pos + 1 < 3 || (str[pos - 1] != 'n' || str[pos - 2] != 'o'))
        {
          answer = false;
        }
        pos -= 3;
        break;
      }
    case 'n':
      {
        bool inVal = false, putonVal = false;
        if(pos + 1 >= 2 && str[pos - 1] == 'i')
        {
          inVal = true;
          pos -= 2;
        }
        else if(pos + 1 >= 5 && str[pos - 1] == 'o'
          && str[pos - 2] == 't'
          && str[pos - 3] == 'u'
          && str[pos - 4] == 'p')
        {
          putonVal = true;
          pos -= 5;
        }
        answer = inVal || putonVal;
        break;
      }
    case 't':
      {
        bool outVal = false, outputVal = false, inputVal = false;
        if(pos + 1 >= 3 && str[pos - 1] == 'u'
          && str[pos - 2] == 'o')
        {
          outVal = true;
          pos -= 3;
        }
        else if(pos + 1 >= 5 && str[pos - 1] == 'u'
          && str[pos - 2] == 'p'
          && str[pos - 3] == 'n'
          && str[pos - 4] == 'i')
        {
          inputVal = true;
          pos -= 5;
        }
        else if(pos + 1 >= 6 && str[pos - 1] == 'u'
          && str[pos - 2] == 'p'
          && str[pos - 3] == 't'
          && str[pos - 4] == 'u'
          && str[pos - 5] == 'o')
        {
          outputVal = true;
          pos -= 6;
        }
        answer = outVal || inputVal || outputVal;
        break;
      }
    default:
      {
        answer = false;
        break;
      }
    }
    if(answer == false)
      return;
  }
}

void WriteData()
{
  if(answer)
    printf("YES\n");
  else
    printf("NO\n");
}

int main()
{
  int QWE;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
#endif
  scanf("%d%*c", &QWE);
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}