#include <stdio.h>

/*
[description]
C(1≤C≤50)
정사각형의 수 n (1≤n≤100)
가로에 블럭이 하나의 그룹으로 되어야 한다
print result % 10,000,000
*/

#define FOR(i,j) for(i=0; i<(j); ++i)
#define FORP(i,j) for(i=1; i<=(j); ++i)
#define MAX_BLOCKS (100)
#define DIVIDER2 (20090711)
#define DIVIDER (20090711)

#define debugf

// polyomino_count[UP_COUNT][CURRENT_ROW_COUNT]
int polyomino_count[MAX_BLOCKS+1][MAX_BLOCKS+1];
int memo[MAX_BLOCKS+1][MAX_BLOCKS+1];

void init_board(int size_of_block)
{
	int i;
	int j;
	FORP(i, size_of_block)
	{
		FORP(j, size_of_block)
		{
			polyomino_count[i][j] = j - 1 + i;
			memo[i][j] = -1;
		}
		polyomino_count[0][i] = 1;
		polyomino_count[i][0] = 1;
		memo[0][i] = -1;
		memo[i][0] = -1;
	}
}

int get_answer(int up_count, int size_of_block)
{
	debugf("[%d][%d]\n", up_count, size_of_block);
	if (size_of_block == 0)
	{
		debugf("polyomino_count[%d][0] %d\n", up_count, polyomino_count[up_count][0]);
		return polyomino_count[up_count][0];
	}

	if (memo[up_count][size_of_block] != -1)
	{
		debugf("memo[%d][%d] %d\n", up_count, size_of_block, memo[up_count][size_of_block]);
		return memo[up_count][size_of_block];
	}

	int i;
	int count = 0;

	FORP(i, size_of_block)
	{
		count += polyomino_count[up_count][i] * get_answer(i, size_of_block - i);
		count = count % DIVIDER2;
	}

	memo[up_count][size_of_block] = count;
	debugf("[%d][%d] %d\n", up_count, size_of_block, count);
	return count;
}

int get_symmetric_answer(int up_count, int size_of_block)
{
	int i;
	int count = 0;

	if (size_of_block % 2 == 0)
	{
		i = 0;
	}
	else
	{
		i = 1;
	}

	for(; i<= size_of_block; i += 2)
	{
		count += get_answer(i, (size_of_block - i)/2);
		count = count % DIVIDER;
	}

	debugf("sym[%d][%d] %d\n", up_count, size_of_block, count);
	return count;
}

int main()
{
	int test_case = 0;
	int i = 0;
	int size_of_block = 0;

	scanf("%d", &test_case);

	FOR(i, test_case)
	{
		scanf("%d", &size_of_block);
		init_board(size_of_block);
		printf("%d\n", (get_answer(0, size_of_block) + DIVIDER - get_symmetric_answer(0, size_of_block))%DIVIDER );
	}
}
