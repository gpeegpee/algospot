#include <stdio.h>

#define FOR(i,j) for(i=0; i<(j); ++i)
#define FORP(i,j) for(i=1; i<=(j); ++i)
#define MAX_WIDTH (100)
#define DIVIDER (1000000007)

#define debugf

long long count[MAX_WIDTH+1];

void init_board(int width)
{
	int i;
	int j;

	count[0] = 1;
	count[1] = 1;
	count[2] = 2;

	for(i=3; i<=width; ++i)
	{
		count[i] = (count[i-1] + count[i-2]) % DIVIDER;
		debugf("count[%d] %lld\n", i, count[i]);
	}
}

long long get_answer(int width)
{
	long long sym_count = 0;
	if (width % 2 == 0)
	{
		sym_count = (count[width/2] + count[(width-2)/2]) %DIVIDER ;
	}
	else
	{
		sym_count = count[(width-1)/2];
	}

	debugf("count[%d] %lld\n", width, (DIVIDER - sym_count + count[width])%DIVIDER);
	return (DIVIDER - sym_count + count[width])%DIVIDER;
}

int main()
{
	int test_case = 0;
	int i = 0;
	int width = 0;

	scanf("%d", &test_case);

	FOR(i, test_case)
	{
		scanf("%d", &width);
		init_board(width);
		printf("%lld\n", get_answer(width));
	}
}
