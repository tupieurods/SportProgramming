#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int compare(const void *a, const void *b)
{
  return (*(int*)a - *(int*)b);
}

int BinarySearch(int *array, int value, int start, int end)
{
  //������ ������
  //� ���� ������ ��� �������� �� �����
  /*if (array.Length == 0)
    return -1;*/

  //��� �������� ��������
  if (start >= end)
    return -(1 + start);

  //����� �������
  int mid = start + (end - start) / 2;

  //���� ������� � ����� ����� ������� - �������
  if (array[start] == value)
    return start;

  //���� � ������ ������� �������
  if (array[mid] == value)
    {
      return mid == start + 1
             ? mid
             : BinarySearch(array, value, start, mid + 1);
    }

  //��������� � ����������� ���������
  return array[mid] < value
         //����������� ������ ��������
         ? BinarySearch(array, value, mid + 1, end)
         //����������� ������  ��������
         : BinarySearch(array, value, start, mid);
}

int main()
{
  int n;
  scanf("%d", &n);
  int **data = new int*[n];
  int *sizes = new int[n];
  for(int i = 0; i < n; i++)
    {
      int k;
      scanf("%d", &k);
      data[i] = new int[k];
      sizes[i] = k;
      for(int j = 0; j < k; j++)
        {
          scanf("%d", &data[i][j]);
        }
      qsort(data[i], k, sizeof(int), compare);
    }
  /*for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < sizes[i]; j++)
        {
          printf("%d ", data[i][j]);
        }
      printf("---------\n");
    }*/
  int count = 0;
  for(int i = 0; i < n; i++)
    {
      if(sizes[i] == 1)
        continue;
      int leftID = i == n - 1 ? 0 : i + 1;
      int rightID = i == 0 ? 7 : i - 1;
      for(int j = 0; j < sizes[i] - 1; j++)
        {
          //�������� ������� ��������� �� ������ ������ ����� j � j+1
          int rightCount = abs(BinarySearch(data[rightID], data[i][j+1], 0, sizes[rightID]))
                           - abs(BinarySearch(data[rightID], data[i][j], 0, sizes[rightID]));
          //�������� ������� ��������� �� ����� ������ ����� j � j+1
          int leftCount = abs(BinarySearch(data[leftID], data[i][j+1], 0, sizes[leftID]))
                          - abs(BinarySearch(data[leftID], data[i][j], 0, sizes[leftID]));
          if(leftCount != rightCount)
            count++;
        }
    }
  printf("%d\n", count);
  return 0;
}
