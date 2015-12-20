#include <stdio.h>
#include <math.h>

#define FOR(i,j) for(i=0; i<(j); ++i)
#define MAX_CITY_SIZE (50)
#define MAX_DAY (100)

/*
1 <= C <= 50, 2 <= N <= 50, 1 <= D <= 100
교도소가 있는 마을의 번호 p (0 <= p < n)
확률을 계산할 마을의 수 t (1 <= t <= n)
t 개의 정수로 확률을 계산할 마을의 번호 q (0 <= q < n)
*/

int N, D, P;
int data[MAX_CITY_SIZE][MAX_CITY_SIZE];
int T;
int Q[MAX_CITY_SIZE];
float city_prob[MAX_CITY_SIZE][MAX_DAY+1];

int city_count[MAX_CITY_SIZE];

void init()
{
	int i;
	int j;

	FOR(i, N)
	{
		FOR(j, D+1)
		{
			city_prob[i][j] = -1;
		}
	}

	FOR(i, N)
	{
		int count = 0;
		FOR(j, N)
		{
			if (data[i][j] == 1)
			{
				++count;
			}
		}
		city_count[i] = count;
	}
}

float get_answer(int city, int day)
{
	if (day == 0)
	{
		if (city == P)
		{
			return 1.0;
		}
		else
		{
			return 0.0;
		}
	}

	if (city_prob[city][day] != -1)
	{
		return city_prob[city][day];
	}

	float prob = 0.0;
	int i;
	FOR(i, N)
	{
		if (data[i][city] == 1)
		{
			prob += get_answer(i, day -1) / city_count[i];
		}
	}

	city_prob[city][day] = prob;
	return prob;
}

int main()
{
	int test_case = 0;
	int i, j, k;

	scanf("%d", &test_case);

	FOR(i, test_case)
	{
		scanf("%d %d %d", &N, &D, &P);
		FOR(j, N)
		{
			FOR(k, N)
			{
				scanf("%d", &data[j][k]);
			}
		}
		scanf("%d", &T);
		FOR(j, T)
		{
			scanf("%d", &Q[j]);
		}

		init();
		FOR(j, T)
		{
			printf("%.8f ", floor(100000000*get_answer(Q[j], D))/100000000);
		}
		printf("\n");
	}
}
