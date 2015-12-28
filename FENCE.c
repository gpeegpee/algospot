#include <stdio.h>

#define FOR(i,j) for(i=0; i<(j); ++i)
#define MAX(a,b) (a)>(b)? (a):(b)
#define MIN(a,b) (a)>(b)? (b):(a)

#define MAX_N_SIZE (20000)
#define debugf

int stick_height[MAX_N_SIZE];

int get_minimum_height_index(int front, int rear)
{
	int min_index = front;
	int min_value = stick_height[front];

	int i;
	for(i=front; i <= rear; ++i)
	{
		if (min_value > stick_height[i])
		{
			min_index = i;
			min_value = stick_height[i];
		}
	}
	debugf("MIN H[%d] %d in [%d][%d]\n", min_index, stick_height[min_index], front, rear);
	return min_index;
}


int get_answer(int front, int rear)
{
	debugf("Get [%d][%d]\n", front, rear);

	if (front > rear)
	{
		return 0;
	}

	if (front == rear)
	{
		return stick_height[front];
	}

	int min_index = get_minimum_height_index(front, rear);
	int max_rect_area = (rear - front + 1)* stick_height[min_index];

	int left_area = get_answer(front, min_index -1);
	int right_area = get_answer(min_index+1, rear);

	int result = MAX(max_rect_area, left_area);
	result = MAX(result, right_area);
	return result;
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
			scanf("%d", &stick_height[j]);
		}
		printf("%d\n", get_answer(0, N-1));
	}

	return 0;
}
