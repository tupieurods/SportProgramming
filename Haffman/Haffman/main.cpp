#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <queue>

using namespace std;

char fileName[109];
char symb[256];

struct node
{
  int cnt;
  unsigned char c;
  node *l, *r;

  node(): cnt(0), c(0), l(NULL), r(NULL)
  {
  }

  bool operator> (const node &node2)
  {
    return this->cnt == node2.cnt ? this->c > node2.c : this->cnt > node2.cnt;
  }
};

struct MyComparator
{
  bool operator() (node *arg1, node *arg2) const
  {
    return *arg1 > *arg2;
  }
};

pair<int, int> codes[256];

void dfs(node *currentNode, int deep, int code)
{
  if(currentNode->l == NULL && currentNode->r == NULL)//list
  {
    if(deep == 0)//1 symbol in text. srsly?
    {
      codes[currentNode->c].first = 1;
      codes[currentNode->c].second = 0;
      return;
    }
    codes[currentNode->c].first = deep;
    codes[currentNode->c].second = code;
    return;
  }
  /*if(deep == 8)
  {
    throw;
  }*/
  if(currentNode->l != NULL)
  {
    dfs(currentNode->l, deep + 1, code);
  }
  if(currentNode->r != NULL)
  {
    dfs(currentNode->r, deep + 1, code | (1 << (31 - deep)));
  }
}

bool isOn(int val, int pos)
{
  return (val & (1 << pos)) != 0;
}

void setBit(unsigned char &wByte, int pos)
{
  wByte |= (unsigned char)(1) << pos;
}

void clearCodes(node *currentNode)
{
  if(currentNode->l != NULL)
  {
    clearCodes(currentNode->l);
  }
  if(currentNode->r != NULL)
  {
    clearCodes(currentNode->r);
  }
  delete currentNode;
}

node* getTree()
{
  priority_queue<node*, vector<node*>, MyComparator> pq;
  for(int i = 0; i < 256; i++)
  {
    if(symb[i] != 0)
    {
      node *newNode = new node();
      newNode->c = (unsigned char)i;
      newNode->cnt = symb[i];
      pq.push(newNode);
    }
  }
  //printf("phase 1 done!\n");
  /*while(pq.size() != 0)
  {
    node *curr = pq.top();
    printf("%d %d\n", curr->cnt, curr->c);
    pq.pop();
  }*/
  while(pq.size() != 1)
  {
    node *_l = pq.top();
    pq.pop();
    node *_r = pq.top();
    pq.pop();
    node *newNode = new node();
    newNode->cnt = _l->cnt + _r->cnt;
    newNode->l = _l;
    newNode->r = _r;
    pq.push(newNode);
  }
  //printf("phase 2 done!\n");
  memset(codes, 0, sizeof(codes));
  node *mainNode = pq.top();
  pq.pop();
  return mainNode;
}

void encode()
{
  freopen(fileName, "rb", stdin);
  freopen("out.txt", "wb", stdout);
  memset(symb, 0, sizeof(symb));
  char c;
  int cnt = 0;
  while(scanf("%c", &c) != EOF)
  {
    unsigned char current = (unsigned char)c;
    symb[current]++;
    cnt++;
  }
  node *mainNode = getTree();
  dfs(mainNode, 0, 0);
  //printf("phase 3 done!\n");
  fseek(stdin, 0, SEEK_SET);
  //printf("%d", cnt);
  fwrite(&cnt, sizeof(int), 1, stdout);
  for(int i = 0; i < 256; i++)
  {
    //printf("%d", &symb[i]);
    fwrite(&symb[i], sizeof(int), 1, stdout);
  }
  int bitsLeft = 8;
  unsigned char byteToWrite = 0;
  while(scanf("%c", &c) != EOF)
  {
    unsigned char current = c;
    for(int j = 0; j < codes[current].first; j++)
    {
      if(isOn(codes[current].second, 31 - j) == 1)
      {
        setBit(byteToWrite, bitsLeft - 1);
      }
      bitsLeft--;
      if(bitsLeft == 0)
      {
        printf("%c", byteToWrite);
        byteToWrite = 0;
        bitsLeft = 8;
      }
    }
    //printf("%c", c);
  }
  if(bitsLeft != 8)
  {
    printf("%c", byteToWrite);
  }
  clearCodes(mainNode);
}

void decode()
{
  freopen(fileName, "rb", stdin);
  freopen("out2.txt", "wb", stdout);
  memset(symb, 0, sizeof(symb));
  char c;
  int cnt = 0;
  //scanf("%d", &cnt);
  fread(&cnt, sizeof(int), 1, stdin);
  for(int i = 0; i < 256; i++)
  {
    int val;
    //scanf("%d", &val);
    fread(&val, sizeof(int), 1, stdin);
    symb[i] = val;
  }
  int bitsLeft = 0;
  node *mainNode = getTree();
  node *currentNode = mainNode;
  while(cnt != 0)
  {
    if(currentNode->l == NULL && currentNode->r == NULL)
    {
      printf("%c", currentNode->c);
      currentNode = mainNode;
      cnt--;
    }
    else
    {
      if(bitsLeft == 0)
      {
        bitsLeft = 8;
        scanf("%c", &c);
      }
      //why not using function isOn?
      if((c & ((unsigned char)1 << (bitsLeft - 1))) != 0)
      {
        currentNode = currentNode->r;
      }
      else
      {
        currentNode = currentNode->l;
      }
      bitsLeft--;
    }
  }
}

int main()
{
  int val = -1;
  while(val != 0 && val != 1)
  {
    printf("encode: 0; decode: 1. Make your choice.\n");
    scanf("%d", &val);
  }
  printf("I wanna file name, without spaces pls\n");
  scanf("%s", fileName);
  if(val == 0)
  {
    encode();
  }
  else
  {
    decode();
  }
  return 0;
}