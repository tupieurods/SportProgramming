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
  int cnt, minimal;

  AVLnode():l(NULL), r(NULL), h(0), key(INT_MAX), cnt(0), minimal(INT_MAX)
  {
  }

  AVLnode(int key):l(NULL), r(NULL), h(0), key(key), cnt(1), minimal(key)
  {
  }

  void Fixup()
  {
    cnt = l->cnt + r->cnt + 1;
    h = max(l->h, r->h) + 1;
    minimal = min(key, min(l->minimal, r->minimal));
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

    void InsertToPos(int pos, int key)
    {
      root = InsertToPosReal(root, pos, key);
      count++;
    }

    int GetMinimal(int l, int r)
    {
      return GetMinimalReal(root, l, r);
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
      /*if(current->l != NIL && current->l->key > current->key)
      {
        printf("left key fail\n");
        return false;
      }
      if(current->r != NIL && current->r->key < current->key)
      {
        printf("right key fail\n");
        return false;
      } */
      bool result = check_H_and_order(current->l) + check_H_and_order(current->r);
      return result;
    }

    int checkCount(AVLnode *current)
    {
      if(current == NIL)
      {
        return 0;
      }
      int result = 1 + checkCount(current->l) + checkCount(current->r);
      if(result != current->cnt)
      {
        printf("in checkCount: cnt fail\n");
      }
      return result;
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

    int GetMinimalReal(AVLnode *current, int l, int r)
    {
      if(l > r || current == NIL)
      {
        throw;
      }
      if(l == r && current->l->cnt + 1 == l)
      {
        return current->key;
      }
      if(l == 1 && r == current->cnt)
      {
        return current->minimal;
      }
      int result = INT_MAX;
      if(l == current->l->cnt + 1)
      {
        l++;
        result = current->key;
      }
      if(r == current->l->cnt + 1)
      {
        r--;
        result = current->key;
      }
      if(r <= current->l->cnt)//В левом поддереве
      {
        result = min(result, GetMinimalReal(current->l, l, r));
      }
      else if(l > current->l->cnt + 1)//В правом поддереве
      {
        result = min(result, GetMinimalReal(current->r, l - current->l->cnt - 1, r - current->l->cnt - 1));
      }
      else//В двух поддеревьях
      {
        result = min(current->key, 
          min(GetMinimalReal(current->l, l, current->l->cnt),
              GetMinimalReal(current->r, 1, r - current->l->cnt - 1)));
      }
      return result;
    }

    AVLnode* InsertToPosReal(AVLnode *current, int pos, int key)
    {
      if(current == NIL)
      {
        AVLnode *toAdd = new AVLnode(key);
        toAdd->l = NIL;
        toAdd->r = NIL;
        return toAdd;
      }
      if(pos <= current->l->cnt)
      {
        current->l = InsertToPosReal(current->l, pos, key);
        current = RotateRight(current);
      }
      else
      {
        current->r = InsertToPosReal(current->r, pos - current->l->cnt - 1, key);
        current = RotateLeft(current);
      }
      return Balance(current);
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

int n;

void ReadData()
{
  scanf("%d%*c", &n);
}

void Solve()
{
  AVLtree tree;
  for(int T = 0; T < n; T++)
  {
    char c;
    scanf("%c", &c);
    if(c == '+')
    {
      int i, x;
      scanf("%d %d%*c", &i, &x);
      tree.InsertToPos(i, x);
      /*if(!tree.check())
      {
        printf("shit\n");
      }*/
    }
    else
    {
      int i, j;
      scanf("%d %d%*c", &i, &j);
      printf("%d\n", tree.GetMinimal(i, j));
    }
  }
}

void WriteData()
{
  printf("\n");
}

int main()
{
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