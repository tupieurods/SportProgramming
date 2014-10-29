#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

char b1[39], b2[39];
int lb1, lb2;

void ReadData()
{
	scanf("%s%*c", b1);
	lb1 = strlen(b1);
	scanf("%s%*c", b2);
	lb2 = strlen(b2);
}

char subAns[39][39];
char ans[100];

void Solve()
{
	memset(subAns, 0, sizeof(subAns));
	memset(ans, 0, sizeof(ans));
	/*printf("%s\n", b1);
	printf("egg\n");
	printf("%s\n", b2);*/
	int idx = 0;
	for(int j = lb2 - 1; j >= 0; j--)
	{
		for(int i = 0; i < lb1; i++)
		{
			if(b2[j] == '0')
			{
				subAns[idx][i] = '0';
			}
			else
			{
				subAns[idx][i] = b1[i];
			}
		}
		idx++;
	}
	__int64 rb2 = 0;
	for(int j = 0; j < lb2; j++)
	{
		rb2 <<= 1;
		if(b2[j] == '1')
		{
			rb2 |= 1;
		}
	}
	__int64 rb1 = 0;
	for(int j = 0; j < lb1; j++)
	{
		rb1 <<= 1;
		if(b1[j] == '1')
		{
			rb1 |= 1;
		}
	}
	__int64 ranswer = rb1 * rb2;
	if(ranswer == 0)
	{
		ans[0] = '0';
	}
	int pos = 0;
	while(ranswer != 0)
	{
		if((ranswer & 1LL) != 0)
		{
			ans[pos] = '1';
		}
		else
		{
			ans[pos] = '0';
		}
		pos++;
		ranswer >>= 1;
	}
}

void WriteData()
{
	int len1 = lb1 + lb2 - 1;
	int ansLen = strlen(ans);
	int totalLen = std::max(ansLen, len1);
	for(int i = 0; i + lb1 < totalLen; i++)
	{
		printf(" ");
	}
	printf("%s\n", b1);
	for(int i = 0; i + lb2 < totalLen; i++)
	{
		printf(" ");
	}
	printf("%s\n", b2);
	int psheeeeee = std::max(lb1, lb2);
	for(int i = 0; i + psheeeeee < totalLen; i++)
	{
		printf(" ");
	}
	for(int i = 0; i < psheeeeee; i++)
	{
		printf("-");
	}
	printf("\n");
	for(int i = 0; i < lb2; i++)
	{
		for(int j = 0; j + lb1 < totalLen; j++)
		{
			printf(" ");
		}
		totalLen--;
		printf("%s\n", subAns[i]);
	}
	totalLen = std::max(ansLen, len1);
	for(int i = 0; i < totalLen; i++)
	{
		printf("-");
	}
	printf("\n");
	for(int i = 0; i + ansLen < totalLen; i++)
	{
		printf(" ");
	}
	for(int i = ansLen - 1; i >= 0; i--)
	{
		printf("%c", ans[i]);
	}
	printf("\n");
	//printf("%s\n", ans);
	printf("\n");
}

int main()
{
	int QWE = 1;
	freopen("BINARY.IN", "r", stdin);
	scanf("%d%*c", &QWE);
	for(int T = 0; T < QWE; T++)
	{
		printf("Test %d\n", T + 1);
		ReadData();
		Solve();
		WriteData();
	}
	return 0;
}