#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

struct AVLnode
{
  int key;
  int h;
  AVLnode *l, *r;

  AVLnode():l(NULL), r(NULL), h(0), key(INT_MAX)
  {
  }

  AVLnode(int key):l(NULL), r(NULL), h(0), key(key)
  {
  }

  void Fixup()
  {
    h = max(l->h, r->h) + 1;
  }
};

class AVLtree
{
  public:
    AVLnode *NIL;
    AVLnode *root;
    int count;

    AVLtree()
    {
      NIL = new AVLnode;
      root = NIL;
      count = 0;
    }

    ~AVLtree()
    {
      dropTree(root);
    }

    void Insert(int key)
    {
      root = InsertReal(root, key);
      count++;
    }

    void show()
    {
      showReal(root);
    }

    bool check()
    {
      int checker = checkCount(root);
      if(checker != count)
      {
        printf("count fail\n");
        return false;
      }
      if(!check_H_and_order(root))
      {
        return false;
      }
      return true;
    }

  private:

    bool check_H_and_order(AVLnode *current)
    {
      if(current == NIL)
      {
        return true;
      }
      if(abs(current->l->h - current->r->h) > 1)
      {
        printf("h difference fail\n");
        return false;
      }
      if(abs(current->h != max(current->l->h, current->r->h) + 1) > 1)
      {
        printf("h calc fail\n");
        return false;
      }
      if(current->l != NIL && current->l->key > current->key)
      {
        printf("left key fail\n");
        return false;
      }
      if(current->r != NIL && current->r->key < current->key)
      {
        printf("right key fail\n");
        return false;
      }
      bool result = check_H_and_order(current->l) + check_H_and_order(current->r);
      return result;
    }

    int checkCount(AVLnode *current)
    {
      if(current == NIL)
      {
        return 0;
      }
      return 1 + checkCount(current->l) + checkCount(current->r);
    }

    void showReal(AVLnode *current)
    {
      if(current == NIL)
      {
        return;
      }
      showReal(current->l);
      printf("%d ", current->key);
      showReal(current->r);
    }

    AVLnode* InsertReal(AVLnode *current, int key)
    {
      if(current == NIL)
      {
        AVLnode *toAdd = new AVLnode(key);
        toAdd->l = NIL;
        toAdd->r = NIL;
        return toAdd;
      }
      if(current->key > key)
      {
        current->l = InsertReal(current->l, key);
      }
      else
      {
        current->r = InsertReal(current->r, key);
      }
      return Balance(current);
    }

    void dropTree(AVLnode *current)
    {
      if(current == NIL)
      {
        return;
      }
      dropTree(current->l);
      dropTree(current->r);
      delete current;
    }

    AVLnode* RotateLeft(AVLnode *current)
    {
      AVLnode *y = current->r;
      current->r = y->l;
      y->l = current;
      current->Fixup();
      y->Fixup();
      return y;
    }

    AVLnode* RotateRight(AVLnode *current)
    {
      AVLnode *x = current->l;
      current->l = x->r;
      x->r = current;
      current->Fixup();
      x->Fixup();
      return x;
    }

    AVLnode* Balance(AVLnode *current)
    {
      if(current->r->h > current->l->h + 1)
      {
        if(current->r->l->h > current->r->r->h)
        {
          current->r = RotateRight(current->r);
        }
        current = RotateLeft(current);
      }
      else if(current->l->h > current->r->h + 1)
      {
        if(current->l->r->h > current->l->l->h)
        {
          current->l = RotateLeft(current->l);
        }
        current = RotateRight(current);
      }
      else
      {
        current->Fixup();
      }
      return current;
    }
};

int main()
{
  AVLtree tree;
  for(int T = 0; T < 100000; T++)
  {
    printf("iteration: %d\n", T + 1);
    tree.Insert(rand() % 10000);
    if(!tree.check())
    {
      tree.show();
      char c;
      c = getch();
      if(c == 'q')
      {
        return 0;
      }
    }
  }
  return 0;
}