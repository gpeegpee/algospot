#include <stdio.h>

#define FOR(i,j) for(i=0; i<(j); ++i)
#define MAX_HEIGHT (100)
#define DIVIDER (1000000007)
#define debugf

int num_of_case[MAX_HEIGHT+1];

int get_answer(const int height)
{
	debugf("[%d]\n", height);
	if (height == 1)
	{
		return 1;
	}
	else if (height == 2)
	{
		return 2;
	}

	if (num_of_case[height] != -1)
	{
		return num_of_case[height];
	}

	num_of_case[height - 1] = get_answer(height - 1) % DIVIDER;
	num_of_case[height - 2] = get_answer(height - 2) % DIVIDER;
	num_of_case[height] = (num_of_case[height - 1] + num_of_case[height - 2]) % DIVIDER;
	return num_of_case[height];
}

int main()
{
	int test_case = 0;
	int i = 0;
	int height = 0;

	scanf("%d", &test_case);

	FOR(i, MAX_HEIGHT+1)
	{
		num_of_case[i] = -1;
	}

	FOR(i, test_case)
	{
		scanf("%d", &height);
		printf("%d\n", get_answer(height));
	}
}
