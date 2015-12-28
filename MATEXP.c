#include <stdio.h>

#define FOR(i,j) for(i=0; i<(j); ++i)
#define MAX(a,b) (a)>(b)? (a):(b)
#define MIN(a,b) (a)>(b)? (b):(a)

#define MAX_N_SIZE (100)
#define DIVIDER (10007)
#define debugf printf

int data[MAX_N_SIZE][MAX_N_SIZE];
int previousResult[MAX_N_SIZE][MAX_N_SIZE];
int Result[MAX_N_SIZE][MAX_N_SIZE];

void init(int size_of_array)
{
	int i;
	int j;
	FOR(i, size_of_array)
	{
		FOR(j, size_of_array)
		{
			previousResult[i][j] = 0;
			Result[i][j] = 0;
		}
	}
}

void multiplyResult(int size_of_array)
{
	int i,j,k;
	int sum = 0;
	FOR(i, size_of_array)
    {
    	FOR(j, size_of_array)
    	{
    		sum = 0;
    		FOR(k, size_of_array)
    		{
    			sum = sum + previousResult[i][k] * previousResult[k][j];
    			sum = sum % DIVIDER;
    		}
    		Result[i][j] = sum;
    	}
    }


}

void multiplyResultWithOne(int size_of_array)
{
	int i,j,k;
	int sum = 0;
	FOR(i, size_of_array)
    {
    	FOR(j, size_of_array)
    	{
    		sum = 0;
    		FOR(k, size_of_array)
    		{
    			sum = sum + previousResult[i][k] * data[k][j];
    			sum = sum % DIVIDER;
    		}
    		Result[i][j] = sum;
    	}
    }
}

void copyResult(int size_of_array)
{
	int i,j;
	FOR(i, size_of_array)
    {
    	FOR(j, size_of_array)
    	{
    		previousResult[i][j] = Result[i][j];
    	}
    }
}

void copyData(int size_of_array)
{
	int i,j;
	FOR(i, size_of_array)
    {
    	FOR(j, size_of_array)
    	{
    		previousResult[i][j] = data[i][j];
    	}
    }
}

int get_answer(int size_of_array, int num_of_power)
{
	int i;
	int j;
	int k;

	if (num_of_power == 1)
	{
		copyData(size_of_array);
		return 0;
	}

	if (num_of_power % 2 == 0)
	{
		get_answer(size_of_array, num_of_power / 2);
		multiplyResult(size_of_array);
		copyResult(size_of_array);
	}
	else
	{
		get_answer(size_of_array, num_of_power / 2);
		multiplyResult(size_of_array);
		copyResult(size_of_array);
		multiplyResultWithOne(size_of_array);
		copyResult(size_of_array);
	}

	return 0;
}

int main()
{
	int test_case = 0;
	int N,P;
	int i,j,k;

	scanf("%d", &test_case);

	FOR(i, test_case)
	{
		scanf("%d %d", &N, &P);
		init(N);
		FOR(j, N)
		{
			FOR(k, N)
			{
				scanf("%d", &data[j][k]);
			}
		}
		get_answer(N, P);
		FOR(j, N)
		{
			FOR(k, N)
			{
				printf("%d ", Result[j][k]);
			}
			printf("\n");
		}
	}

	return 0;
}
