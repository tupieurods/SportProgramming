#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <iomanip>
#include <math.h>
#include <algorithm>

//#define DEBUG
//#define MULTITEST

using namespace std;

struct chimney
{
  char symb;
  int x, y;
};

struct angleChar
{
  char liter;
  double angle;
};

struct FFFUUU
{
  double start, finish;
};

bool compare(angleChar v1, angleChar v2)
{
  return v1.angle > v2.angle;//Пока забить на eps
}

angleChar calcAngle(double xStart, chimney chim)
{
  double angle = ((double)chim.x - xStart) / sqrt(pow((double)chim.y, 2) + pow((double)chim.x - xStart, 2));
  angleChar result = {chim.symb, angle};
  return result;
}

double calc_X_crossing(double x1, double y1, double x2, double y2)
{
  return (x1 * (y2 - y1) - y1 * (x2 - x1)) / (y2 - y1);
}

int main()
{
  ifstream strm("input.txt");
  int QWE;
#ifdef MULTITEST
  strm >> QWE;
#else
  QWE = 1;
#endif
  for(int T = 0; T < QWE; T++)
  {
    int n;
    string pattern;
    strm >> n;
    strm >> pattern;
    chimney* inputData = new chimney[n];
    for(int i = 0; i < n; i++)
    {
      strm >> inputData[i].symb >> inputData[i].x >> inputData[i].y;
    }
    set<double> points;
    for(int i = 0; i < n; i++)
    {
      for(int j = i + 1; j < n; j++)
      {
        if(inputData[i].y == inputData[j].y)
          continue;
        points.insert(calc_X_crossing(inputData[i].x, inputData[i].y, inputData[j].x, inputData[j].y));
      }
    }
#ifdef DEBUG
    for(set<double>::iterator i = points.begin(); i != points.end(); i++)
      cout << setprecision(7) << *i << endl;
#endif
    double prev = -50000;
    vector<FFFUUU> anwser;
    for(set<double>::iterator i = points.begin(); i != points.end(); i++)
    {
      vector<angleChar> angles;
      double center = (prev + (*i)) / 2;
#ifdef DEBUG
      //cout << center << endl;
#endif
      for(int j = 0; j < n; j++)
      {
        angles.push_back(calcAngle(center, inputData[j]));
#ifdef DEBUG
        //cout << angles[j].liter << setprecision(7) << angles[j].angle << endl;
#endif
      }
      sort(angles.begin(), angles.end(), compare);
      string currentView = "";
      for(vector<angleChar>::iterator j = angles.begin(); j != angles.end(); j++)
      {
        currentView += j->liter;
        //cout << j->liter << setprecision(7) << j->angle << endl;
      }
      reverse(currentView.begin(), currentView.end());
      if(currentView == pattern)
      {
        //cout << "ALARM!!" <<endl << currentView << endl;
        FFFUUU tmp = {prev, *i};
        anwser.push_back(tmp);
      }
      prev = *i;
    }

    //TODO: Запилить проверку правого infinity
    //TODO: Выпилить дублирование кода
    vector<angleChar> angles;
    for(int j = 0; j < n; j++)
    {
      angles.push_back(calcAngle(35000, inputData[j]));
    }
    sort(angles.begin(), angles.end(), compare);
    string currentView = "";
    for(vector<angleChar>::iterator j = angles.begin(); j != angles.end(); j++)
    {
      currentView += j->liter;
    }
    reverse(currentView.begin(), currentView.end());
    if(currentView == pattern)
    {
      FFFUUU tmp = {prev, 35000};
      anwser.push_back(tmp);
    }
    cout << anwser.size() << endl;
    for(vector<FFFUUU>::iterator i = anwser.begin(); i != anwser.end(); i++)
    {
      if(i->start == -50000)
        cout << "*" << " ";
      else
        cout << setprecision(14) << i->start << " ";
      if(i->finish == 35000)
        cout << "*" << " ";
      else
        cout << setprecision(14) << i->finish << " ";
    }
    cout << endl;

    //cout << inputData[0].symb << inputData[0].x << inputData[0].y << endl;
    delete inputData;
  }
  return 0;
}