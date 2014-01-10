// suboptimal distributed proper graph coloring algorithm
#include <set>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>
#include <iterator>
#include <queue>


typedef std::size_t Index;
typedef std::unordered_set <Index> Adjacency;
typedef std::vector <Adjacency> Adjacencies;

typedef std::vector <int> Colors;

struct Conflict
{
  int conflicts;
  int minColor;
};

typedef std::vector <Conflict> Conflicts;


// find conflicts and minimal non-conflicting colors
bool checkConflicts (const Adjacencies &G, const Colors &C, Conflicts &conflicts)
{
  std::set <int> neighbourColors;
  for (Index vend = G.size(), v = Index (0); v != vend; ++v)
  {
    // count conflicts with neighbours
    auto &c = conflicts[v];
    int cConflicts = 0;
    neighbourColors.clear();
    const int myColor = C[v];
    for (auto nend = G[v].end(), n = G[v].begin(); n != nend; ++n)
    {
      const int nColor = C[*n];
      if (nColor == myColor)
        ++cConflicts;
      neighbourColors.insert (nColor);
    }

    c.conflicts = cConflicts;

    // find min color
    auto nc = neighbourColors.cbegin();
    if (neighbourColors.empty() || *nc > 0)
      c.minColor = 0;
    else
    {
      int cMinColor = 1;
      for (auto ncend = neighbourColors.cend(); ++nc != ncend;)
      {
        const int ncColor = *nc;
        if (ncColor != cMinColor)
          break;
        cMinColor = ncColor + 1;
      }

      c.minColor = cMinColor;
    }
  }

  // check if we found any conflicts
  return std::find_if (conflicts.cbegin(), conflicts.cend(),
    [](const Conflict &c) { return c.conflicts > 0; }) != conflicts.cend();
}


// recolor most conflicting and non-adjacent vertices
void recolor (const Adjacencies &G, const Conflicts &conflicts, Colors &C)
{
  // find most conflicting vertex and recolor it to minColor and so on, but recolor only non-neighbours
  std::vector <Index> indices (G.size());
  for (Index iend = G.size(), i = Index (0); i != iend; ++i)
    indices[i] = i;

  // remove all non-conflicting vertices
  indices.erase (std::remove_if (indices.begin(), indices.end(),
    [&conflicts](Index a) { return conflicts[a].conflicts == 0; }), indices.end());

  // sort indices according to conflicts amount of corresponding vertices
  std::sort (indices.begin(), indices.end(),
    [&conflicts](Index a, Index b) 
    { return conflicts[a].conflicts > conflicts[b].conflicts
      || (conflicts[a].conflicts == conflicts[b].conflicts && conflicts[a].minColor < conflicts[b].minColor); });

  // store neighbour vertices here to skip them
  Adjacency doNotRecolor;
  for (auto i = indices.cbegin(), iend = indices.cend(); i != iend; ++i)
  {
    const Index v = *i;
    if (doNotRecolor.find (v) == doNotRecolor.end())
    {
      C[v] = conflicts[v].minColor;
      doNotRecolor.insert (G[v].begin(), G[v].end());
    }
  }
}


// breadth-first search doing 0-1 coloring (color of v is distance (0, v) mod 2)
void oddEvenColoring (const Adjacencies &G, Colors &C)
{
  if (G.empty())
    return;

  std::queue <Index> Q;
  std::vector <bool> done (G.size(), false);
  std::vector <bool>::iterator si = done.begin();

  do
  {
    const Index s = static_cast <Index> (si - done.begin());
    Q.push (s);
    done[s] = true;
    C[s] = 0;

    while (!Q.empty())
    {
      const Index u = Q.front();
      const int cv = 1 - C[u]; // color for new neighbours
      Q.pop();
      for (auto n = G[u].begin(), nend = G[u].end(); n != nend; ++n)
      {
        const Index v = *n;
        if (!done[v])
        {
          done[v] = true;
          Q.push (v);
          C[v] = cv;
        }
      }
    }

    si = std::find (si, done.end(), false); // find next connectivity component
  }
  while (si != done.end());
}


// coloring algorithm based upon checkConflicts and recolor
int coloring (const Adjacencies &G, Colors &C)
{
  C.clear();
  if (G.empty())
    return 0;

  C.resize (G.size());
  oddEvenColoring (G, C); // pre-color using BFS

  // main loop
  Conflicts conflicts (G.size());
  while (checkConflicts (G, C, conflicts))
    recolor (G, conflicts, C);

  // return amount of colors used
  return 1 + *std::max_element (C.cbegin(), C.cend());
}


void bind (Adjacencies &G, Index u, Index v)
{
  G[u].insert (v);
  G[v].insert (u);
}


void fromArray (Adjacencies &G, const Index *arr, Index Gsize, Index degree)
{
  G.clear();
  G.resize (Gsize);
  for (Index i = 0; i < Gsize; ++i)
    G[i].insert (arr + i * degree, arr + (i + 1) * degree);
}


void printColoring (const Adjacencies &G)
{
  Colors C;
  std::cout << coloring (G, C) << std::endl;
  std::copy (C.begin(), C.end(), std::ostream_iterator <int> (std::cout, " "));
  std::cout << std::endl;
}


int main()
{
  using namespace std;

  cout << "K4,4: ";
  {
    Adjacencies G (8);
    for (Index u = 0; u < Index (4); ++u)
      for (Index v = 4; v < Index (8); ++v)
        bind (G, u, v); // K 4,4
    printColoring (G);
  }

  cout << "odd cycle: ";
  {
    Adjacencies G (5);
    bind (G, 0, 1);
    bind (G, 1, 2);
    bind (G, 2, 3);
    bind (G, 3, 4);
    bind (G, 0, 4);
    printColoring (G);
  }
  
  cout << "K8: ";
  {
    Adjacencies G (8);
    for (Index u = 0; u < Index (7); ++u)
      for (Index v = u + 1; v < Index (8); ++v)
        bind (G, u, v);
    printColoring (G);
  }

  cout << "square + center: ";
  {
    Adjacencies G (5);
    bind (G, 0, 1);
    bind (G, 1, 2);
    bind (G, 2, 3);
    bind (G, 0, 3);
    bind (G, 0, 4);
    bind (G, 1, 4);
    bind (G, 2, 4);
    bind (G, 3, 4);
    printColoring (G);
  }

  cout << "3-prism: ";
  {
    Adjacencies G;
    const Index Gv[6][3] = {{1, 2, 3}, {0, 2, 4}, {0, 1, 5}, {0, 4, 5}, {1, 3, 5}, {2, 3, 4}};
    fromArray (G, Gv[0], 6, 3);
    printColoring (G);
  }

  cout << "4-prism (cube): ";
  {
    Adjacencies G;
    const Index Gv[8][3] = 
      {{1, 3, 4}, {0, 2, 5}, {1, 3, 6}, {0, 2, 7},
       {0, 5, 7}, {1, 4, 6}, {2, 5, 7}, {3, 4, 6}};
    fromArray (G, Gv[0], 8, 3);
    printColoring (G);
  }

  cout << "some planar graph: ";
  {
    Adjacencies G;
    const Index Gv[12][4] =
    {{1, 2, 4,  5}, {7, 8,  0,  2}, {0, 1, 10, 11}, {4, 5,  6, 9},
     {3, 5, 0,  7}, {3, 4,  0, 10}, {3, 7,  8,  9}, {4, 1,  8, 6},
     {6, 7, 1, 11}, {3, 6, 10, 11}, {2, 5, 11,  9}, {2, 8, 10, 9}};
    fromArray (G, Gv[0], 12, 4);
    printColoring (G);
  }

  cout << "My test: ";
  {
    Adjacencies G(6);
    bind(G, 0, 2);
    bind(G, 1, 4);
    bind(G, 3, 5);
    bind(G, 0, 3);
    bind(G, 1, 5);
    bind(G, 2, 4);
    printColoring (G);
  }

  cin.get();
  return 0;
}