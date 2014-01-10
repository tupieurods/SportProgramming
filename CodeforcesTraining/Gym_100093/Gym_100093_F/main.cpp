#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct vertex
{
  vertex *l, *r;
  int N, minimal, val;
};

int n;
vertex *mainHead, *nil;

void ReadData()
{
  scanf("%d%*c", &n);
}

inline int min(int v1, int v2)
{
  return v1 < v2 ? v1 : v2;
}

inline int max(int v1, int v2)
{
  return v1 > v2 ? v1 : v2;
}

inline void setVertexInfo(vertex *v, vertex *l, vertex *r, int Nval, int minimalVal)
{
  v->l = l;
  v->r = r;
  v->N = Nval;
  v->minimal = minimalVal;
  v->val = minimalVal;
}

void Restore(vertex *v)
{
  v->N = v->l->N + v->r->N + 1;
  v->minimal = min(v->val, min(v->l->minimal, v->r->minimal));
}

vertex* rotateRight(vertex* v)
{
  vertex *result = v->l;
  v->l = result->r;
  result->r = v;
  Restore(v);
  Restore(result);
  return result;
}

vertex* rotateLeft(vertex* v)
{
  vertex *result = v->r;
  v->r = result->l;
  result->l = v;
  Restore(v);
  Restore(result);
  return result;
}

vertex* treeInsertToRoot(vertex *root, int pos, int value)
{
  if(root == nil)
  {
    vertex *newVertex = new vertex;
    setVertexInfo(newVertex, nil, nil, 1, value);
    return newVertex;
  }
  if(pos <= root->l->N)
  {
    root->l = treeInsertToRoot(root->l, pos, value);
    root = rotateRight(root);
  }
  else
  {
    root->r = treeInsertToRoot(root->r, pos - root->l->N - 1, value);
    root = rotateLeft(root);
  }
  return root;
}

vertex* treeInsertRandomize(vertex *root, int pos, int value)
{
  if(root == nil)
  {
    vertex *newVertex = new vertex;
    setVertexInfo(newVertex, nil, nil, 1, value);
    return newVertex;
  }
  if(rand() < RAND_MAX / (root->N + 1))
  {
    return treeInsertToRoot(root, pos, value);
  }
  if(pos <= root->l->N)
  {
    root->l = treeInsertRandomize(root->l, pos, value);
  }
  else
  {
    root->r = treeInsertRandomize(root->r, pos - root->l->N - 1, value);
  }
  root->N++;
  root->minimal = min(root->val, min(root->l->minimal, root->r->minimal));
  return root;
}

void showTree(vertex *root)
{
  if(root == nil)
  {
    return;
  }
  showTree(root->l);
  printf("%d ", root->val);
  showTree(root->r);
}

vertex* treeInsert(int pos, int value)
{
  return treeInsertRandomize(mainHead, pos, value);
}

void queryAdd()
{
  int pos, value;
  scanf("%d %d%*c", &pos, &value);
  mainHead = treeInsert(pos, value);
  /*showTree(mainHead);
  printf("\n");*/
}

int getMinimum(vertex *root, int l, int r)
{
  //Конец поиска
  if(l > r || root == nil)
  {
    throw;
  }
  if(l == 1 && r == root->N)
  {
    return root->minimal;
  }
  if(l == r && l == root->l->N + 1)
  {
    return root->val;
  }
  //Выбор перехода
  int result = INT_MAX;
  if(l == root->l->N + 1)
  {
    l++;
    result = root->val;
  }
  if(r == root->l->N + 1)
  {
    r--;
    result = root->val;
  }
  //Полностью в левом поддереве
  if(r <= root->l->N)
  {
    result = min(result, getMinimum(root->l, l ,r));
  }
  else if(l > root->l->N + 1)//Полностью в правом поддереве
  {
    result = min(result,
      getMinimum(root->r, l - root->l->N - 1, r - root->l->N - 1));
  }
  else//В двух поддеревьях
  {
    result = min(root->val,
      min(getMinimum(root->l, l, root->l->N),
          getMinimum(root->r, 1, r - root->l->N - 1)));
  }
  return result;
}

void queryMinimum()
{
  int l, r;
  scanf("%d %d%*c", &l, &r);
  int result = getMinimum(mainHead, l, r);
  if(result == INT_MAX)
  {
    throw;
  }
  printf("%d\n", result);
}

void Solve()
{
  if(nil != NULL)
  {
    delete nil;
  }
  nil = new vertex;
  setVertexInfo(nil, NULL, NULL, 0, INT_MAX);
  mainHead = nil;
  for(int i = 0; i < n; i++)
  {
    char c;
    scanf("%c", &c);
    if(c == '+')
    {
      queryAdd();
    }
    else if(c == '?')
    {
      queryMinimum();
    }
    else
    {
      throw;
    }
  }
}

void WriteData()
{
  //showTree(mainHead);
  printf("\n");
}

int main()
{
  srand(758);
  int QWE = 1;
  freopen("rmq.in", "r", stdin);
  #ifndef ONLINE_JUDGE
  scanf("%d", &QWE);
  #else
  freopen("rmq.out", "w", stdout);
  #endif
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}