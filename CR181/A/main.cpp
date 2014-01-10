#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
  int n;
  scanf("%d", &n);
  vector<int> negative, positive;
  int cntZero = 0;
  for(int i = 0; i < n; i++)
  {
    int tmp;
    scanf("%d", &tmp);
    if(tmp > 0)
    {
      positive.push_back(tmp);
    }
    else if(tmp < 0)
    {
      negative.push_back(tmp);
    }
    else
    {
      cntZero++;
    }
  }
  int pos = 0;
  if(positive.size() == 0)
  {
    positive.push_back(negative[0]);
    positive.push_back(negative[1]);
    pos = 2;
  }
  printf("%d %d\n", 1, negative[pos]);
  pos++;
  int pos2 = 0;
  if(pos == 3)
  {
    printf("%d %d %d\n", 2, positive[0], positive[1]);
    pos2 = 2;
  }
  else
  {
    printf("%d %d\n", 1, positive[0]);
    pos2 = 1;
  }
  printf("%d ", cntZero + positive.size() - pos2 + negative.size() - pos);
  {
    for(int i = 0; i < cntZero; i++)
      printf("0 ");
    for(int i = pos; i < negative.size(); i++)
      printf("%d ", negative[i]);
    for(int i = pos2; i < positive.size(); i++)
      printf("%d ", positive[i]);
  }
  return 0;
}
