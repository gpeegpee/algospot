#include <stdio.h>

/*
[description]
C(1≤C≤50)
정사각형의 수 n (1≤n≤100)
가로에 블럭이 하나의 그룹으로 되어야 한다
print result % 10,000,000
*/

#define FOR(i,j) for(i=0; i<(j); ++i)
#define MAX_BLOCKS (100)

int polyomino_count[MAX_BLOCKS+1];

int polyomino_start_pos[MAX_BLOCKS+1];
int polyomino_finish_pos[MAX_BLOCKS+1];

void init_board(int size_of_block)
{
	int i;
	FOR(i, size_of_block)
	{
		polyomino_count[i+1] = 0;
		polyomino_start_pos[i+1] = 0;
		polyomino_finish_pos[i+1] = 0;
	}
}

int promising(int queen_index, int col)
{
	int i = 0;
	for(i = 1; i < queen_index; ++i)
	{
		if (queen_col_position[i] == col
			|| (queen_index - i) == col - queen_col_position[i]
			|| (queen_index - i) == queen_col_position[i] - col)
		{
			return -1;
		}
	}
	return col;
}

int get_answer(const int size_of_block)
{
	int j;
	for(j = 1; j <= size_of_block; ++j)
	{
		if (promising(index, j) > 0)
		{
			queen_col_position[index] = j;

			if (index == size_of_queen)
			{
				num_of_solution++;
			}
			else
			{

				get_answer(index + 1, size_of_queen);
			}
		}
		else
		{
			// cut branch
			continue;
		}
	}
	return num_of_solution;
}

int main()
{
	int test_case = 0;
	int i = 0;
	int size_of_queen = 0;

	scanf("%d", &test_case);

	FOR(i, test_case)
	{
		scanf("%d", &size_of_block);
		init_board(size_of_block);
		printf("%d\n", get_answer(size_of_block));
	}
}
