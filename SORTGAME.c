#include <stdio.h>

#define FOR(i,j) for(i=0; i<(j); ++i)
#define MAX_SIZE (500)
#define MAX(a,b) (a)>(b)? (a):(b)
#define MIN(a,b) (a)>(b)? (b):(a)
#define debugf printf

#define MAX_NUMBER (8)

int numbers[MAX_NUMBER];

int get_answer(int numbers)
{
	return 0;
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
			scanf("%d", &numbers[j]);
		}
		printf("%d\n", get_answer(N));
	}

	return 0;
}
