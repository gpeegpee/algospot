#include <stdio.h>

#define FOR(i,j) for(i=0; i<(j); ++i)
#define MAX_SIZE (100)
#define MAX(a,b) (a)>(b)? (a):(b)
#define MIN(a,b) (a)>(b)? (b):(a)

#define debugf

//int data[MAX_SIZE*(MAX_SIZE+1)/2+1];
//int max_score[MAX_SIZE*(MAX_SIZE+1)/2+1];
//int max_count[MAX_SIZE*(MAX_SIZE+1)/2+1];

int data[MAX_SIZE+1][MAX_SIZE+1];
int max_score[MAX_SIZE+1][MAX_SIZE+1];
int max_count[MAX_SIZE+1][MAX_SIZE+1];

int max_count_result;
int max_score_result;

void init()
{
	max_count_result = -1;
	max_score_result = -1;

	int i,j;

	FOR(i, MAX_SIZE+1)
	{
		FOR(j, MAX_SIZE+1)
		{
			max_count[i][j] = -1;
			max_score[i][j] = -1;
		}
	}
}

int get_max_count(int data[MAX_SIZE+1][MAX_SIZE+1], int num_of_line, int index_in_line)
{
	debugf("[%d][%d]\n", num_of_line, index_in_line);
	if (max_count[num_of_line][index_in_line] != -1)
	{
		return max_count[num_of_line][index_in_line];
	}

	if (num_of_line == 1)
	{
		max_score[num_of_line][index_in_line] = data[num_of_line][1];
		max_count[num_of_line][index_in_line] = 1;
		return max_count[num_of_line][index_in_line];
	}

	if (index_in_line == 1)
	{
		max_count[num_of_line][index_in_line] = get_max_count(data, num_of_line -1, index_in_line);
		max_score[num_of_line][index_in_line] = data[num_of_line][index_in_line] + max_score[num_of_line-1][index_in_line];
		//return max_count[num_of_line][index_in_line];
	}
	else if (index_in_line == num_of_line)
	{
		max_count[num_of_line][index_in_line] = get_max_count(data, num_of_line -1, index_in_line -1 );
		max_score[num_of_line][index_in_line] = data[num_of_line][index_in_line] + max_score[num_of_line-1][index_in_line-1];
		//return max_count[num_of_line][index_in_line];
	}
	else
	{
		int count1 = get_max_count(data, num_of_line -1, index_in_line -1 );
		int count2 = get_max_count(data, num_of_line -1, index_in_line);

		int score1 = max_score[num_of_line-1][index_in_line-1];
		int score2 = max_score[num_of_line-1][index_in_line];
		if (score1 == score2)
		{
			max_count[num_of_line][index_in_line] = count1 + count2;
			max_score[num_of_line][index_in_line] = data[num_of_line][index_in_line] + score1;
		}
		else if (score1 > score2)
		{
			max_count[num_of_line][index_in_line] = count1;
			max_score[num_of_line][index_in_line] = data[num_of_line][index_in_line] + score1;
		}
		else
		{
			max_count[num_of_line][index_in_line] = count2;
			max_score[num_of_line][index_in_line] = data[num_of_line][index_in_line] + score2;
		}
	}

	debugf("[%d][%d]MAX COUNT %d MAX SCORE %d\n", num_of_line, index_in_line
												, max_count[num_of_line][index_in_line]
												, max_score[num_of_line][index_in_line]);
	return max_count[num_of_line][index_in_line];
}


int get_answer(int data[MAX_SIZE+1][MAX_SIZE+1], int num_of_line)
{
	int i;
	int result = -1;

	for(i = 1; i <= num_of_line; ++i)
	{
		result = get_max_count(data, num_of_line, i);
		if (max_count_result == -1)
		{
			max_count_result = result;
			max_score_result = max_score[num_of_line][i];
		}
		else if (max_score_result == max_score[num_of_line][i])
		{
			max_count_result += result;
		}
		else if (max_score_result < max_score[num_of_line][i])
		{
			max_count_result = result;
			max_score_result = max_score[num_of_line][i];
		}
		else
		{
			continue;
		}
	}

	return max_count_result;
}

int main()
{
	int test_case = 0;
	int N = 0;
	int i,j,k;

	scanf("%d", &test_case);

	FOR(i, test_case)
	{
		scanf("%d", &N);
		for(j = 1; j <= N; ++j)
		{
			for(k = 1; k <= j; ++k)
			{
				//scanf("%d", &data[j*(j-1)/2 + k ]);
				scanf("%d", &data[j][k]);
			}
		}
		init();
		printf("%d\n", get_answer(data, N));
	}

	return 0;
}
