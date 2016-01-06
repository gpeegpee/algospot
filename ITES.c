#include <stdio.h>

#define FOR(i,j) for(i=0; i<(j); ++i)
#define MAX(a,b) (a)>(b)? (a):(b)
#define MIN(a,b) (a)>(b)? (b):(a)

#define MAX_SUM_SIZE (5000000)
#define MAX_N_SIZE (50000000)
#define debugf printf

int signalNum[MAX_N_SIZE];

void init(int size_of_array)
{
	int i;/
	signalNum[0] = 1983;
	for(i = 1; i< size_of_array; ++i)
	{
		signalNum[i] = (signalNum[i-1] * 214013 + 2531011) % 10000 + 1;
	}
}

int get_answer(int front, int rear)
{

	return result;
}

int main()
{
	int test_case = 0;
	int K,N;
	int i;

	scanf("%d", &test_case);

	FOR(i, test_case)
	{
		scanf("%d %d", &K, &N);
		init(N);
		printf("%d\n", get_answer(1, N));
	}

	return 0;
}
