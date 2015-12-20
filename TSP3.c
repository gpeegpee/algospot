#include <stdio.h>

#define FOR(i,j) for(i=1; i<=(j); ++i)
#define MAX_CITY (20)
#define MIN(a,b) (a)>(b)?(b):(a)
#define MAX(a,b) (a)>(b)?(a):(b)
#define VISITED (1)

float distance[MAX_CITY+1][MAX_CITY+1];
float min_distance[MAX_CITY+1][MAX_CITY+1];
int visited[MAX_CITY + 1];

void init(int num_of_city)
{
	int i;
	int j;

	FOR(i, num_of_city)
	{
		FOR(j, num_of_city)
		{
			if (i == j)
			{
				min_distance[i][j] = 0.0;
			}
			else
			{
				min_distance[i][j] = -1;
			}
		}
	}
}

float solve(int start, int finish)
{
	if (min_distance[start][finish] != -1)
	{
		return min_distance[start][finish];
	}

	int i;
	int j;
	int num_of_city = finish - start +1;
	float result = distance[start][start+1];

	visited[start] = VISITED;

	for (i = start; i<= finish; ++i)
	{
		result = MIN(result, distance[start][i] + solve(i, finish));
	}

	return result;
}

int main()
{
	int test_case = 0;
	int i = 0;
	int j = 0;
	int k = 0;
	int N = 0;

	scanf("%d", &test_case);

	FOR(i, test_case)
	{
		scanf("%d", &N);
		FOR(j, N)
		{
			FOR(k, N)
			{
				scanf("%f", &distance[j][k]);
			}
		}
		init(N);
		printf("%.10f\n", solve(1, N));
	}
}
