#include <stdio.h>

#define FOR(i,j) for(i=0; i<(j); ++i)
#define MAX(a,b) (a)>(b)? (a):(b)
#define MIN(a,b) (a)>(b)? (b):(a)
#define debugf

#define MAX_ROW (1000)
#define MAX_COL (20)
#define MAX_ALPHABET_NUM (26)

char board[MAX_ROW][MAX_COL+1];
char result[MAX_ALPHABET_NUM+1];
char temp_result[MAX_ALPHABET_NUM+1];
int alphabet_order[MAX_ALPHABET_NUM][MAX_ALPHABET_NUM];
int alphabet_visit[MAX_ALPHABET_NUM];
int current_index;

void init()
{
	int i, j;
	FOR(i, MAX_ALPHABET_NUM)
	{
		FOR(j, MAX_ALPHABET_NUM)
		{
			alphabet_order[i][j] = 0;
		}
		alphabet_visit[i] = 0;
		current_index = 0;
		result[i] = '\0';
	}
}

void debugPrint()
{
	int i, j;
	FOR(i, MAX_ALPHABET_NUM)
	{
		FOR(j, MAX_ALPHABET_NUM)
		{
			if (alphabet_order[i][j] == 0)
				debugf(". ");
			else
				debugf("%d ", alphabet_order[i][j]);
		}
		debugf("\n");
	}
}

int compare_alphabet_order(int row1, int row2)
{
	int i = 0;
	int j = 0;

	while(board[row1][i] != '\0' && board[row2][j] != '\0')
	{
		if (board[row1][i] == board[row2][j])
		{
			debugf("same\n");
			++i;
			++j;
		}
		else
		{
			int row1_alphabet = board[row1][i] - 'a';
			int row2_alphabet = board[row2][j] - 'a';
			if (alphabet_order[row2_alphabet][row1_alphabet] != 0)
			{
				debugf("not impossible\n");
				snprintf(result, 19, "INVALID HYPOTHESIS");
				return -1;
			}
			else
			{
				debugf("update\n");
				alphabet_order[row1_alphabet][row2_alphabet] = 1;
			}
			return 0;
		}
	}

	return 0;
}

void dfs(int here)
{
	alphabet_visit[here] = 1;
	int i;
	FOR(i, MAX_ALPHABET_NUM)
	{
		if (alphabet_order[here][i] != 0 && alphabet_visit[i] == 0)
		{
			dfs(i);
		}
	}
	temp_result[current_index++] = here + 'a';
}

int topological_sort()
{
	int i;
	FOR(i, MAX_ALPHABET_NUM)
	{
		if (alphabet_visit[i] == 0)
		{
			dfs(i);
		}
	}
}

int get_answer(int num_of_row)
{
	int i;
	int ret;
	FOR(i, num_of_row - 1)
	{
		ret = compare_alphabet_order(i, i+1);
		if (ret < 0)
		{
			return -1;
		}
	}
	topological_sort();

	FOR(i, MAX_ALPHABET_NUM)
	{
		result[i] = temp_result[MAX_ALPHABET_NUM - i - 1];
	}

	debugPrint();
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
		init();
		scanf("%d", &N);
		FOR(j, N)
		{
			scanf("%s", &board[j][0]);
		}
		get_answer(N);
		printf("%s\n", result);
	}

	return 0;
}
