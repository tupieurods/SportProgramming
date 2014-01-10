#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
  int n;
  scanf("%d", &n);
  vector<int> anwser;
  int countNegative = 0;
  anwser.push_back(0);
  for(int i = 0; i < n; i++)
  {
    int tmp;
    scanf("%d", &tmp);
    if(tmp < 0)
    {
      countNegative++;
      if(countNegative == 3)
      {
        anwser.push_back(0);
        countNegative = 1;
      }
    }
    anwser[anwser.size() - 1]++;
  }
  printf("%d\n", anwser.size());
  for(vector<int>::iterator i = anwser.begin(); i != anwser.end(); i++)
  {
    printf("%d ", *i);
  }
  return 0;
}
