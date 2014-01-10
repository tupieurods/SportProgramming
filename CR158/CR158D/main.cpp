#include <iostream>
#include <stdio.h>
#include <deque>
#include <set>

using namespace std;

struct edge
{
  int from;
  int to;
  int value;
};

int* s;

bool compare(int a, int b)
{
  if(s[a] == s[b])
    return a < b;
  return s[a] < s[b];
}

void AddLastEdges(set<int, bool(*)(int, int)> &colorToAdd, deque<edge> &anwser, int from)
{
  for(set<int>::iterator i = colorToAdd.begin(); i != colorToAdd.end(); i++)
  {
    edge toAdd;
    toAdd.from = from;
    toAdd.to = *i + 1;
    toAdd.value = 0;
    anwser.push_back(toAdd);
  }
}

int main()
{
  int n;
  std::ios::sync_with_stdio(false);
  //scanf("%d", &n);
  cin >> n;
  set<int, bool(*)(int, int)> white(compare);
  set<int, bool(*)(int, int)> black(compare);
  s = new int[n];
  for(int i = 0; i < n; i++)
  {
    int color;
    //scanf("%d %d", &color, &s[i]);
    cin >> color >> s[i];
    if(color == 0)
    {
      white.insert(i);
    }
    else
    {
      black.insert(i);
    }
  }
  /*for(set<int>::iterator i = white.begin(); i != white.end(); i++)
    cout << *i << endl;
  cout << endl;*/
  deque<edge> anwser;
  while(true)
  {
    int whiteIndex = *white.begin();
    int blackIndex = *black.begin();
    /*cout << white.size() << endl;
    cout << black.size() << endl << endl;
    printf("whiteIndex= %d s[whiteIndex]= %d\n", whiteIndex, s[whiteIndex]);
    printf("blackIndex= %d s[blackIndex]= %d\n", blackIndex, s[blackIndex]);*/
    white.erase(white.begin());
    black.erase(black.begin());
    edge e;
    e.from = whiteIndex + 1;
    e.to = blackIndex + 1;
    if(s[whiteIndex] > s[blackIndex])
    {
      e.value = s[blackIndex];
    }
    else
    {
      e.value = s[whiteIndex];
    }
    anwser.push_back(e);
    //cout << "stage1" << endl;
    //Вершинки кончились
    if(white.size() == 0 && black.size() == 0)
      break;
    //cout << "stage2" << endl;
    if(white.size() == 0 && s[whiteIndex] == 0)
    {
      AddLastEdges(black, anwser, whiteIndex + 1);
      break;
    }
    else if(black.size() == 0 && s[blackIndex] == 0)
    {
      AddLastEdges(white, anwser, blackIndex + 1);
      break;
    }
    //cout << "stage3" << endl;
    if(s[whiteIndex] > s[blackIndex])
    {
      s[whiteIndex] -= s[blackIndex];
      white.insert(whiteIndex);
    }
    else
    {
      s[blackIndex] -= s[whiteIndex];
      black.insert(blackIndex);
    }
    //cout << "stage4" << endl;
  }
  for(deque<edge>::iterator i = anwser.begin(); i != anwser.end(); i++)
  {
    //printf("%d %d %d\n", i->from, i->to, i->value);
    cout << i->from << " " << i->to << " " << i->value << endl;
  }
  return 0;
}
