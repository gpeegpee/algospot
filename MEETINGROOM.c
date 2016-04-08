#include <stdio.h>

#define FOR(i,j) for(i=0; i<(j); ++i)
#define MAX_SIZE (500)
#define MAX(a,b) (a)>(b)? (a):(b)
#define MIN(a,b) (a)>(b)? (b):(a)
#define debugf printf

#define MAX_TIME (43200)
#define MAX_TEAM (100)

typedef struct
{
	int start_time;
	int end_time;
	int team_number;
	int occupied;
} meeting_s;

meeting_s team_data[2*MAX_TEAM];

void init(int num_of_team)
{
	int i, j;
	FOR(i, 2*num_of_team)
	{
		team_number = i/2;
		occupied = 0;
	}
}


int get_answer(int num_of_team)
{
	int i;
	return 0;
}

int main()
{
	int test_case = 0;
	int N;
	int i,j;

	int a,b,c,d;

	scanf("%d", &test_case);

	FOR(i, test_case)
	{
		scanf("%d", &N);
		init(N);
		FOR(j, N)
		{
			scanf("%d %d %d %d", &a, &b, &c, &d);
			team_data[j].start_time = a;
			team_data[j].end_time = b;
			team_data[j+1].start_time = c;
			team_data[j+1].end_time = d;
		}
		get_answer(N);
	}

	return 0;
}
