#include <stdio.h>

#define FOR(i,j) for(i=0; i<(j); ++i)
#define MAX_BOARD_SIZE (12)

#define NONE (0)
#define EXIST (1)

int queen_col_position[MAX_BOARD_SIZE+1];
int num_of_solution;

void init_board()
{
	queen_col_position[1] = 1;
	num_of_solution = 0;
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

int get_answer(const int index, const int size_of_queen)
{
	int j;

	for(j = 1; j <= size_of_queen; ++j)
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
		scanf("%d", &size_of_queen);
		init_board();
		printf("%d\n", get_answer(1, size_of_queen));
	}
}
