#include <stdio.h>

#define FOR(i,j) for(i=0; i<(j); ++i)
#define MAX_SCORE_SIZE (50)
#define MAX(a,b) (a)>(b)? (a):(b)
#define MIN(a,b) (a)>(b)? (b):(a)

#define debugf

int score_data[MAX_SCORE_SIZE];

#define HYUNWOO (0)
#define SEOHA (1)
#define INF (50*1000+1)

int score_memo[MAX_SCORE_SIZE][MAX_SCORE_SIZE][2];

void init(int num_of_score)
{
	int i,j,k;

	FOR(i, num_of_score)
	{
		for(j=i; j < num_of_score; ++j)
		{
			for (k = 0; k < 2; ++k)
			{
				score_memo[i][j][k] = INF;
			}
		}
	}
}

void debug_array(int num_of_score)
{
	int i,j;
	FOR(i, num_of_score)
	{
		FOR(j, num_of_score)
		{
			debugf("%5d ", score_memo[i][j][0]);
		}
		debugf("\n");
	}

	debugf("\n");
	FOR(i, num_of_score)
	{
		FOR(j, num_of_score)
		{
			debugf("%5d ", score_memo[i][j][1]);
		}
		debugf("\n");
	}
}

int get_answer(int score[], int front, int rear, int who_score)
{
	debugf(">>> [%d][%d][%d]\n", front, rear, who_score);
	if (score_memo[front][rear][who_score] != INF)
	{
		return score_memo[front][rear][who_score];
	}

	if (front == rear)
	{
		debugf("[%d][%d][%d] %d\n", front, rear, who_score, score[front]);
		score_memo[front][rear][who_score] = score[front];
		return score[front];
	}

	if (rear - front == 1)
	{
		score_memo[front][rear][who_score] = (MAX(score[front],score[rear])) - (MIN(score[front],score[rear]));
		debugf("[%d][%d][%d] %d\n", front, rear, who_score, score_memo[front][rear][who_score]);
		debugf("MAX %d\n", MAX(score[front],score[rear]));
		debugf("MIN %d\n", MIN(score[front],score[rear]));
		return score_memo[front][rear][who_score];
	}

	int score_left_two_remove = -1 * get_answer(score, front + 2, rear, who_score^1);
	int score_right_two_remove = -1 * get_answer(score, front, rear - 2, who_score^1);
	int score_left_one_select = score[front] + (-1 * get_answer(score, front+1, rear, who_score^1));
	int score_right_one_select = score[rear] + (-1 * get_answer(score, front, rear-1, who_score^1));

	int max_score = MAX(score_left_two_remove, score_right_two_remove);
	max_score = MAX(max_score, score_left_one_select);
	max_score = MAX(max_score, score_right_one_select);

	score_memo[front][rear][who_score] = max_score;

	return max_score;
}

int main()
{
	int test_case = 0;
	int N = 0;
	int i,j;

	scanf("%d", &test_case);

	FOR(i, test_case)
	{
		scanf("%d", &N);
		init(N);
		FOR(j, N)
		{
			scanf("%d", &score_data[j]);
		}
		printf("%d\n", get_answer(score_data, 0, N-1, HYUNWOO));

		debug_array(N);
	}

	return 0;
}
