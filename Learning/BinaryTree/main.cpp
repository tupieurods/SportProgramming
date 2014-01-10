#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <algorithm>

struct vertex
{
  int key;
  vertex *parent, *left, *right;
};

vertex *TreeRoot;
std::vector<vertex*> shit;
int n;

void updateTree(vertex *&root, int val)
{
  vertex *prevVertex = NULL;
  vertex *current = root;
  while(current != NULL)
  {
    prevVertex = current;
    if(val <= current->key)
    {
      current = current->left;
    }
    else
    {
      current = current->right;
    }
  }

  current = new vertex;
  shit.push_back(current);
  current->key = val;
  current->left = NULL;
  current->right = NULL;
  current->parent = prevVertex;
  if(prevVertex != NULL)
  {
    if(val <= prevVertex->key)
    {
      prevVertex->left = current;
    }
    else
    {
      prevVertex->right = current;
    }
  }
  else
  {
    root = current;
  }
}

void showTree(vertex *current)
{
  if(current == NULL)
  {
    return;
  }
  showTree(current->left);
  printf("%d ", current->key);
  showTree(current->right);
}

vertex* treeMinimum(vertex *root)
{
  if(root == NULL)
  {
    throw;
  }
  while(root->left != NULL)
  {
    root = root->left;
  }
  return root;
}

vertex* treeMaximum(vertex *root)
{
  if(root == NULL)
  {
    throw;
  }
  while(root->right != NULL)
  {
    root = root->right;
  }
  return root;
}

vertex* findElementInTree(vertex *root, int val)
{
  if(root == NULL)
  {
    throw;
  }
  while(root != NULL)
  {
    if(root->key == val)
    {
      break;
    }
    if(val < root->key)
    {
      root = root->left;
    }
    else
    {
      root = root->right;
    }
  }
  return root;
}

vertex* nextElementInTree(vertex *current)
{
  if(current == NULL)
  {
    throw;
  }
  if(current->right != NULL)
  {
    return treeMinimum(current->right);
  }
  vertex *parent = current->parent;
  while(parent != NULL && parent->right == current)
  {
    current = parent;
    parent = current->parent;
  }
  return parent;
}

vertex* prevElementInTree(vertex *current)
{
  if(current == NULL)
  {
    throw;
  }
  if(current->left != NULL)
  {
    return treeMaximum(current->left);
  }
  vertex *parent = current->parent;
  while(parent != NULL && parent->left == current)
  {
    current = parent;
    parent = current->parent;
  }
  return parent;
}

void deleteElementFromTree(vertex *&root, vertex *toDel)
{
  if(toDel == NULL)
  {
    return;
  }
  if(toDel->left == NULL && toDel->right == NULL)//У вершины нет детей
  {
    if(toDel->parent != NULL)
    {
      if(toDel->parent->left == toDel)
      {
        toDel->parent->left = NULL;
      }
      else
      {
        toDel->parent->right = NULL;
      }
      delete toDel;
    }
    else
    {
      //Удаляем корень
      delete toDel;
      root = NULL;
    }
  }
  else if(toDel->left != NULL && toDel->right != NULL)//Есть оба сына
  {
    vertex *newVertex = treeMinimum(toDel->right);
    newVertex->left = toDel->left;
    newVertex->left->parent = newVertex;
    if(toDel->parent == NULL)
    {
      root = newVertex;
    }
    else
    {
      if(toDel->parent != NULL)
      {
        if(toDel->parent->right == toDel)
        {
          toDel->parent->right = newVertex;
        }
        else
        {
          toDel->parent->left = newVertex;
        }
      }
    }
    if(newVertex == toDel->right)
    {
      newVertex->parent = toDel->parent;
      
    }
    else
    {
      if(newVertex->right != NULL)
      {
        newVertex->right->parent = newVertex->parent;
      }
      newVertex->parent->left = newVertex->right;
      newVertex->right = toDel->right;
      newVertex->right->parent = newVertex;
      newVertex->parent = toDel->parent;
    }
    delete toDel;
  }
  else//Есть один из сыновей
  {
    if(toDel->parent == NULL)
    {
      root = toDel->left == NULL ? toDel->right : toDel->left;
      root->parent = NULL;
    }
    else
    {
      if(toDel->parent->left == toDel)
      {
        toDel->parent->left = toDel->left == NULL 
          ? toDel->right : toDel->left;
        toDel->parent->left->parent = toDel->parent;
      }
      else
      {
        toDel->parent->right = toDel->left == NULL 
          ? toDel->right : toDel->left;
        toDel->parent->right->parent = toDel->parent;
      }
    }
    delete toDel;
  }
}

void deleteElementFromTree(vertex *&root, int val)
{
  deleteElementFromTree(root, findElementInTree(root, val));
}

void ReadData()
{
  /*scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    int val;
    scanf("%d", &val);
    updateTree(TreeRoot, val);*/
    /*if(i < 3)
    {
    deleteElementFromTree(TreeRoot, val);
    }*/
  //}
}

void Solve()
{
  std::vector<int> v;
  for(int i = 0; i < 1000; i++)
  {
    int step = rand() % 2;
    if(v.size() == 0)
    {
      step = 0;
    }
    if(step == 0)
    {
      int val = rand() % 5000 - 2000;
      v.push_back(val);
      updateTree(TreeRoot, val);
      //printf("add: %d\n", val);
    }
    else
    {
      int index = rand() % v.size();
      //printf("erase: %d\n", v[index]);
      deleteElementFromTree(TreeRoot, v[index]);
      v.erase(v.begin() + index);
      showTree(TreeRoot);
      printf("\n");
      std::sort(v.begin(), v.end());
      for(std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
      {
        printf("%d ", *it);
      }
      printf("\n");
    }
  }
  /*printf("Tree: ");
  showTree(TreeRoot);
  printf("\n");

  printf("Tree minimin: %d\n", treeMinimum(TreeRoot)->key);
  printf("Tree maximum: %d\n", treeMaximum(TreeRoot)->key);
  printf("Try to find element 11 in Tree. Pointer: %d\n", findElementInTree(TreeRoot, 11));
  printf("Try to find element 12 in Tree. Pointer: %d\n", findElementInTree(TreeRoot, 12));
  vertex *result = nextElementInTree(findElementInTree(TreeRoot, 12));
  printf("Try to find next element for 12 in Tree. Pointer: %d. Key: %d\n", result, result->key);
  result = nextElementInTree(findElementInTree(TreeRoot, 13));
  printf("Try to find next element for 13 in Tree. Pointer: %d. Key: %d\n", result, result->key);
  result = prevElementInTree(findElementInTree(TreeRoot, 12));
  printf("Try to find prev element for 12 in Tree. Pointer: %d. Key: %d\n", result, result->key);
  result = prevElementInTree(findElementInTree(TreeRoot, 13));
  printf("Try to find prev element for 13 in Tree. Pointer: %d. Key: %d\n", result, result->key);
  result = prevElementInTree(findElementInTree(TreeRoot, 3));
  printf("Try to find prev element for 13 in Tree. Pointer: %d\n", result);*/

  /*deleteElementFromTree(TreeRoot, 3);
  printf("\n3 deleted. Tree: ");
  showTree(TreeRoot);
  printf("\n");*/

  /*deleteElementFromTree(TreeRoot, 16);
  printf("\n16 deleted. Tree: ");
  showTree(TreeRoot);
  printf("\n");

  deleteElementFromTree(TreeRoot, 15);
  printf("\n15 deleted. Tree: ");
  showTree(TreeRoot);
  printf("\n");*/

  /*deleteElementFromTree(TreeRoot, 5);
  printf("\n5 deleted. Tree: ");
  showTree(TreeRoot);
  printf("\n");*/
}

int main()
{
  srand(time(NULL));
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  ReadData();
  Solve();
  return 0;
}