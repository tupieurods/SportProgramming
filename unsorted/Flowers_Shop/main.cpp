#include <cstdlib>
#include <iostream>

using namespace std;

int F;

void MatchBestAesthetic(signed char row, signed char column, int** table, bool** calculated)
{
    int max = table[row][column];
    for (signed char i = column; i < F; i++)
    {
        if (!calculated[row + 1][i])
            MatchBestAesthetic((signed char)(row + 1), i, table, calculated);
        max =max>table[row + 1][i] + table[row][column] ? max : table[row + 1][i] + table[row][column];
    }
    calculated[row][column] = true;
    table[row][column] = max;
}


int main(int argc, char *argv[])
{
    int V;
    scanf("%d%d",&F,&V);
    if(F==1)
    {
        int maxValue = 0, maxID = 1;
        for(signed char j = 0; j < V; j++)
        {
            int tmp;
            scanf("%d",&tmp);
            if(tmp>maxValue)
            {
                maxValue = tmp;
                maxID = j+1;
            }
        }
        printf("%d\n%d",maxValue,maxID);
        return 0;
    }
    int **table = new int*[F];
    bool **calculated = new bool*[F];
    for (signed char i = 0; i < F; i++)
    {
        table[i] = new int[F];
        calculated[i] = new bool[F];
        int tmp;
        for (signed char j = 0; j < V; j++)
        {
            scanf("%d",&tmp);
            if((j>=i)&&(j<i+F))
                table[i][j-i]=tmp;
            calculated[i][j] = i == F-1 ? true:false;
        }
    }
    for (signed char i = 0; i < F; i++)
        MatchBestAesthetic(0, i, table, calculated);
    signed char maxID = 0;
    for (signed char i = 0; i < F; i++)
    {
        for (signed char j = maxID; j < F; j++)
        {
            if (table[i][j] > table[i][maxID])
                maxID = j;
        }
        if (i == 0)
        {
            printf("%d\n",table[0][maxID]);
        }
        printf("%d ", maxID + i + 1);
    }
    /*system("PAUSE");
    return EXIT_SUCCESS;*/
    return 0;
}
