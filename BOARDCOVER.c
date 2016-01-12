#include <stdio.h>
#include <assert.h>

#define FOR(i,j) for(i=0; i<(j); ++i)
#define FORP(i,j) for(i=1; i<=(j); ++i)
#define MAX(a,b) (a)>(b)? (a):(b)
#define MIN(a,b) (a)>(b)? (b):(a)

#define MAX_SIZE (20)
#define debugf printf

#define NO (-1)
#define YES (1)

#define BLOCK ('#')
#define EMPTY ('.')

char board[MAX_SIZE+1][MAX_SIZE+2];
int visited[MAX_SIZE+1][MAX_SIZE+1];
int total_count;

typedef struct
{
	int x_pos;
	int y_pos;
} Pattern;

Pattern data[3][3] =
{
	{{0,0},{0,1},{-1,1}},
	{{0,0},{1,0},{ 1,1}},
	{{0,0},{0,1},{ 1,1}}
};

void init(int height, int width)
{
	int i,j;
	FORP(i, height)
	{
		FORP(j, width)
		{
			visited[i][j] = 0;
		}
	}
	total_count = 0;
}

void debug_array(int height, int width)
{
	int i,j;
	FORP(i, height)
	{
		FORP(j, width)
		{
			debugf("%c", board[i][j]);
		}
		debugf("\n");
	}
}

int promising(int x, int y, int pattern)
{
	int x_pos;
	int y_pos;
	int i;

	FOR(i, 3)
	{
		x_pos = x + data[pattern][i].x_pos;
		x_pos = y + data[pattern][i].y_pos;

		if (board[x][y] != EMPTY || visited[x][y] != 0)
		{
			return 0;
		}
	}

	return pattern;
}

int get_next_x(int height, int width, int x, int y)
{
	if (x == width && y < height)
	{
		x = 0;
		y++;
		return 0;
	}
	else if (x < width && y <= height)
	{
		x++;
		return x+1;
	}
}

int get_next_y(int height, int width, int x, int y)
{
	if (x == width && y < height)
	{
		x = 0;
		y++;
		return y+1;
	}
	else if (x < width && y <= height)
	{
		x++;
		return y;
	}
}

int get_answer(int height, int width, int x, int y)
{
	int i;
	int j;
	int k;
	int next_x;
	int next_y;

	while(x <= width && y <= height)
	{
		if (x == width && y == height)
		{
			if (board[x][y] == BLOCK || visited[x][y] != 0)
			{
				total_count++;
				return;
			}
			else
			{
				return;
			}
		}


		if (board[x][y] == BLOCK || visited[x][y] != 0)
		{
			x = get_next_x(height, width, x, y);
			y = get_next_y(height, width, x, y);
		}
		else
		{

		}

	}



	return 0;
}

int main()
{
	int test_case = 0;
	int H,W;
	int i,j,k;

	scanf("%d", &test_case);

	FOR(i, test_case)
	{
		scanf("%d %d", &H, &W);
		init(H,W);
		FORP(j, H)
		{
			scanf("%s", &board[j][1]);
		}
		printf("%d\n", get_answer(H, W, 1, 1));
	}

	return 0;
}
