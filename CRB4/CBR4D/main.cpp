#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct cover
{
  int pos;
  int w;
  int h;
};

struct cacheElement
{
  int max;
  int next;
};

vector<cacheElement> cache;
vector<cover> covers;

bool coverCompare(cover first, cover second)
{
  bool result;
  if(first.h == second.h)
    result = first.w > second.w;
  else
    result = first.h > second.h;
  return result;
}

int f(int pos)//Находит цепь с максимальной длиной
{
  if(cache[pos].max == -1)
    {
      cache[pos] = {0, -1};
      for(int i = pos + 1; i < covers.size(); i++)
        {
          if((covers[i].h < covers[pos].h) && (covers[i].w < covers[pos].w) && (1 + f(i) > cache[pos].max))
            {
              cache[pos].max = 1 + f(i);
              cache[pos].next = i;
            }
        }
    }
  return cache[pos].max;
}

void g(int pos)//Выводит элементы цепи
{
  if(cache[pos].max != 0)
    g(cache[pos].next);
  printf("%d ", covers[pos].pos);
}

int main()
{
  int n, cwidth, cheight;
  scanf("%d %d %d", &n, &cwidth, &cheight);
  for(int i = 1; i <= n; i++)
    {
      int width, height;
      scanf("%d %d", &width, &height);
      if(cwidth >= width || cheight >= height)
        continue;
      covers.push_back( {i, width, height});
    }
  if(!covers.empty())
    {
      for(int i = 0; i < covers.size(); i++)
        {
          cache.push_back( { -1, -1});
        }
      sort(covers.begin(), covers.end(), coverCompare);
      int maximal = 0;
      for(int i = 0; i < covers.size(); i++)
        {
          if(f(i) > f(maximal))
            maximal = i;
        }
      printf("%d\n", f(maximal) + 1);
      g(maximal);
    }
  else
    printf("0");
  /*for(vector<cover>::iterator i = covers.begin(); i != covers.end(); i++)
    {
      printf("pos=%d\th=%d\tw=%d\n", i->pos, i->h, i->w);
    }
  for(vector<cacheElement>::iterator i = cache.begin(); i != cache.end(); i++)
    {
      printf("max=%d\tnext=%d\n", i->max, i->next);
    }*/
  return 0;
}
