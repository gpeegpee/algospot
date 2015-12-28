#include <stdio.h>

#define FOR(i,j) for(i=0; i<(j); ++i)
#define MAX_SIZE (100)
#define MAX_REFUND (5000)
#define MAX(a,b) (a)>(b)? (a):(b)
#define MIN(a,b) (a)>(b)? (b):(a)
#define DIVIDER (1000000007)

#define debugf

int coins[MAX_SIZE];
int refund_count[MAX_REFUND+1][MAX_SIZE+1];

void init(int money, int coins)
{
	int i;
	int j;
	FOR(i, money+1)
	{
		FOR(j, coins + 1)
		{
			refund_count[i][j] = -1;
		}
	}
}

int get_answer(int coins[], int money, int num_of_coins)
{
	debugf("====== In M[%d] =====\n", money);
	if (money == 0)
	{
		return 1;
	}

	if (refund_count[money][num_of_coins] != -1)
	{
		return refund_count[money][num_of_coins];
	}

	int i;
	int result;
	for (i=num_of_coins -1; i >= 0; --i)
	{
		if (money < coins[i])
		{
			debugf("M[%d] Coin[%d] Skip\n", money, coins[i]);
			continue;
		}
		else
		{
			debugf("M[%d] Coin[%d] OK\n", money, coins[i]);
			result = get_answer(coins, money - coins[i], i+1);
			if (refund_count[money][num_of_coins] == -1)
			{
				refund_count[money][num_of_coins] = result % DIVIDER;
			}
			else
			{
				refund_count[money][num_of_coins] += result;
				refund_count[money][num_of_coins] %= DIVIDER;
			}
			debugf("C[%d] %d\n", money, refund_count[money][num_of_coins]);
		}
	}

	if (refund_count[money][num_of_coins] == -1)
	{
		refund_count[money][num_of_coins] = 0;
	}

	debugf("Count %d\n", refund_count[money][num_of_coins]);
	return refund_count[money][num_of_coins];
}

int main()
{
	int test_case = 0;
	int M,C;
	int i,j,k;

	scanf("%d", &test_case);

	FOR(i, test_case)
	{
		scanf("%d %d", &M, &C);
		FOR(j, C)
		{
			scanf("%d", &coins[j]);
		}
		init(M, C);
		printf("%d\n", get_answer(coins, M, C));
	}

	return 0;
}
