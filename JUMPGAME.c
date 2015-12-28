#include <stdio.h>

#define FOR(i,j) for(i=0; i<(j); ++i)
#define MAX(a,b) (a)>(b)? (a):(b)
#define MIN(a,b) (a)>(b)? (b):(a)

#define MAX_N_SIZE (100)
#define debugf printf

int data[MAX_N_SIZE][MAX_N_SIZE];
int possible[MAX_N_SIZE][MAX_N_SIZE];

void init(int size_of_array)
{
	int i;
	int j;
	FOR(i, size_of_array)
	{
		FOR(j, size_of_array)
		{
			possible[i][j] = -1;
		}
	}
}

int get_answer(int front_x, int front_y, int rear_x, int rear_y)
{
	if (front_x > rear_x || front_y > rear_y)
	{
		return 0;
	}

	if (possible[front_x][front_y] != -1)
	{
		return possible[front_x][front_y];
	}

	if (front_x + data[front_x][front_y] == rear_x && front_y == rear_y)
	{
		possible[front_x][front_y] = 1;
		return 1;
	}
	if (front_x == rear_x && front_y + data[front_x][front_y] == rear_y)
	{
		possible[front_x][front_y] = 1;
		return 1;
	}

	if (get_answer(front_x+data[front_x][front_y], front_y, rear_x, rear_y) == 1)
	{
		possible[front_x][front_y] = 1;
		return 1;
	}

	if (get_answer(front_x, front_y+data[front_x][front_y], rear_x, rear_y) == 1)
	{
		possible[front_x][front_y] = 1;
		return 1;
	}

	possible[front_x][front_y] = 0;
	return 0;
}

int main()
{
	int test_case = 0;
	int N;
	int i,j,k;
	int result = 0;

	scanf("%d", &test_case);

	FOR(i, test_case)
	{
		scanf("%d", &N);
		init(N);
		FOR(j, N)
		{
			FOR(k, N)
			{
				scanf("%d", &data[j][k]);
			}
		}
		result = get_answer(0, 0, N-1, N-1);
		printf("%s\n", result == 1? "YES" : "NO");
	}

	return 0;
}
