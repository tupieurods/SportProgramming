#include <stdio.h>
#include <vector>

using namespace std;

struct elem
{
  int day;
  int countAdded;
};

int n, m;
vector<elem> workers;

void ShowAnwser()
{
  for(vector<elem>::iterator i = workers.begin(); i != workers.end(); i++)
    {
      for(int j = 0; j < i->countAdded; j++)
        {
          printf("%d ", i->day);
        }
    }
}

int numberOfWorkers(int day)
{
  int vacationsLeft = day / (n + m);
  if(day % (n + m) == 0)
    vacationsLeft--;
  //printf("vLeft=%d\n",vacationsLeft);
  int result = 0;
  for(vector<elem>::iterator i = workers.begin(); i != workers.end(); i++)
    {
      if((i->day + vacationsLeft*m + vacationsLeft*n <= day)
          && (day <= i->day + vacationsLeft * m + (vacationsLeft + 1)*n - 1))
        result += i->countAdded;
    }
  return result;
}

int main()
{
  int k;
  scanf("%d %d %d", &n, &m, &k);
  int count = 0;
  int daysWithoutNew = 0;
  int day = 1;
  do
    {
      int today = numberOfWorkers(day);
      //printf("day=%d\ttoday=%d\n", day, today);
      if(today < k)
        {
          workers.push_back( {day, k - today});
          count += k - today;
        }
      int tomorrow = numberOfWorkers(day + 1);
      if(tomorrow == 0)
        {
          workers.push_back( {day, 1});
          count++;
        }
      if(workers.end()->day != day)
        daysWithoutNew++;
      else
        daysWithoutNew = 0;
      day++;
    }
  while(daysWithoutNew != (n + m) * 2);
  printf("%d\n", count);
  ShowAnwser();
  return 0;
}
