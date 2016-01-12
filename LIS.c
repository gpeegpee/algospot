#include <stdio.h>

#define FOR(i,j) for(i=0; i<(j); ++i)
#define MAX_SIZE (500)
#define MAX(a,b) (a)>(b)? (a):(b)
#define MIN(a,b) (a)>(b)? (b):(a)
#define debugf printf

int number[MAX_SIZE];
int max_count[MAX_SIZE][MAX_SIZE];

void init(int size_of_number)
{
	int i;
	int j;
	int k;
	int count = 0;
	int min_value = 0;
	FOR(i, size_of_number)
	{
		for(j=i, j < size_of_number; ++j)
		{
			if (i == j)
			{
				max_count[i][j] = 1;
			}
			else
			{
				if (number[i] >= number[j])
				{
					max_count[i][j] = 0;
				}
				else
				{
					count = 1;
					min_value = number[i];
					for(k=i+1;k<j;++k)
					{
						if ()
					}
				}
			}
		}
	}
}

int get_answer(int size_of_number)
{
	int i;
	int j;

	int total_count = 0;
	int max_count = 1;

	FOR(i, size_of_number)
	{
		if (i ==0)
		{
			max_count[0] = 1;
			right_number[0] = number[0];
		}
		else
		{
			if (right_number[i-1] < number[i])
			{

			}
			else
			{

			}
		}
	}
}

int main()
{
	int test_case = 0;
	int N;
	int i,j,k;

	scanf("%d", &test_case);

	FOR(i, test_case)
	{
		scanf("%d", &N);
		FOR(j, N)
		{
			scanf("%d", &number[j]);
		}
		init(N);
		printf("%d\n", get_answer(N));
	}

	return 0;
}
