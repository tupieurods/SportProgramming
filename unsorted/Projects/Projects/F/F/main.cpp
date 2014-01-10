#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

//#define DEBUG
//#define DEBUG2

using namespace std;

struct range
{
  int start,finish;
  __int64 sum;
};

struct element
{
  __int64 value;
  int pos;
};

//������ sums �� ������������ ���� ����� �������� ������
vector<__int64> sums;
vector<element> elems;
vector<__int64> unsortedElements;
range* r;
int n;

//���������� �������� ��� ����������
bool compareElement(element v1, element v2)
{
  if(v1.value==v2.value)
  {
    return v1.pos>v2.pos;
  }
  else
    return v1.value>v2.value;
}

bool checkForUnion(int pos, bool left)
{
  //if left==true then check union to left
  //else to right
  if(left)
  {
    if(pos == 0)//��� ������ �������
      return false;
    return unsortedElements[pos-1] >= unsortedElements[pos];
  }
  else
  {
    if(pos == n-1)//��� ������� �������
      return false;
    return unsortedElements[pos+1] >= unsortedElements[pos];
  }
}

//�� ������������
__int64 getSum(int start, int finish)
{
  if(start==1)
    return sums[finish - 1];
  return sums[finish - 1] - sums[start-2];
}

int main()
{
  ifstream strm("input.txt");
  int QWE;
#ifdef DEBUG2
  strm>>QWE;
#else
  QWE=1;
#endif
  for(int T=0; T<QWE;T++)
  {
    strm>>n;
    __int64 sum=0;
    r=new range[n];
    for(int i=0; i<n; i++)
    {
      __int64 tmp;
      strm >> tmp;
      sum += tmp;
      sums.push_back(sum);
#ifdef DEBUG
      cout << sums[i] << endl;
#endif
      element tmpElem = {tmp,i};
      elems.push_back(tmpElem);
      unsortedElements.push_back(tmp);
      range tmpRange = {i, i, tmp};
      r[i] = tmpRange;
    }
    sort(elems.begin(), elems.end(), compareElement);
    range anwser={0,0, 0};
    //������� ���� ������
    for(vector<element>::iterator i = elems.begin(); i!=elems.end(); i++)
    {
#ifdef DEBUG
      cout << (*i).value << " " << (*i).pos << endl;
#endif
      __int64 sum = (r[(*i).pos].start == r[(*i).pos].finish) ? (*i).value : 0;
      //����� ���� �����
      bool toLeft = checkForUnion( (*i).pos, true);
      //�������
      int cLeft = r[(*i).pos].start;
      int cRight = r[(*i).pos].finish;
      //��������, � ����� � ��� ��������������� ������� ��� � ���������� � �����-��
      bool flag = (r[(*i).pos].start==(*i).pos && r[(*i).pos].finish>=(*i).pos);
      bool flag2 = (r[(*i).pos].start==(*i).pos && r[(*i).pos].finish==(*i).pos);
      //� ������ �������
      if(toLeft && flag)
      {
        sum += r[(*i).pos - 1].sum + (sum==0 ? r[(*i).pos].sum : 0);
        cLeft = r[(*i).pos - 1].start;
        cRight = r[(*i).pos].finish;
        r[cRight].start = cLeft;//�������� � �������� �����
        r[cLeft].finish = cRight;//�������� ������ �����
        r[cRight].sum = sum;//�������� �������� �����
        r[cLeft].sum = sum;//�������� ������ �����
#ifdef DEBUG
        cout << "left union" << cLeft << " " << cRight << endl;
#endif
      }
      //� ������� �������
      if(checkForUnion( (*i).pos, false) && flag2)
      {
        sum += r[(*i).pos + 1].sum;
        int startIndex = toLeft ? r[(*i).pos].start : (*i).pos;
        cLeft = r[startIndex].start;
        cRight = r[(*i).pos + 1].finish;
        r[startIndex].finish = r[(*i).pos + 1].finish;//�������� �����
        r[r[(*i).pos + 1].finish].start = r[startIndex].start;//�������� ������� �����
        r[startIndex].sum = sum;//�������� ������ ����� �����
        r[r[(*i).pos + 1].finish].sum = sum;//�������� ������� ����� �����
#ifdef DEBUG
        cout << "right union" << cLeft << " " << cRight << endl;
#endif
      }
#ifdef DEBUG
      cout << "sum: " << sum << endl;
#endif
      //���� ���������� �������� ������������ ��� ������� �����
      if(sum * (*i).value > anwser.sum)
      {
        anwser.sum = sum * (*i).value;
        anwser.start = cLeft;
        anwser.finish = cRight;
#ifdef DEBUG
        cout << "NEW: " << anwser.sum << " " << anwser.start 
          << " " << anwser.finish <<endl;
#endif
      }
    }
    cout << anwser.sum << endl << anwser.start + 1 << " " << anwser.finish + 1<<endl;
    //cout<<getSum(2,2)<<endl;
    delete r;
    unsortedElements.clear();
    elems.clear();
  }
  return 0;
}