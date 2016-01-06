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

int get_answer(int height, int width)
{
	int i;
	int j;

	FORP(i, height)
	{
		FORP(j, width)
		{
			if (board[i][j] == BLOCK)
			{
				continue;
			}
			else
			{
				
			}
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
		printf("%d\n", get_answer(H, W));
	}

	return 0;
}
