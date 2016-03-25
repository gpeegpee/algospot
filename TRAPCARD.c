#include <stdio.h>

#define FOR(i,j) for(i=0; i<(j); ++i)
#define MAX_SIZE (500)
#define MAX(a,b) (a)>(b)? (a):(b)
#define MIN(a,b) (a)>(b)? (b):(a)
#define debugf printf

#define MAX_ROW (20)
#define MAX_COL (20)

char board[MAX_ROW+1][MAX_COL];

void init(int size_of_number)
{

}

void debug(int row, int col)
{
	int i,j;
	FOR(i, row)
	{
		FOR(j, col)
		{
			debugf("%c", board[i][j] == '#'? 'X' : ' ');
		}
		debugf("\n");
	}
}

int get_answer(int row, int col)
{
	debug(row,col);
	return 0;
}

int main()
{
	int test_case = 0;
	int H, W;
	int i,j,k;

	scanf("%d", &test_case);

	FOR(i, test_case)
	{
		scanf("%d %d", &H, &W);
		FOR(j, H)
		{
			scanf("%s", &board[j][0]);
		}
		printf("%d\n", get_answer(H, W));
	}

	return 0;
}
