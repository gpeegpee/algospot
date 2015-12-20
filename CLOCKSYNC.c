#include <stdio.h>

#define FOR(i,j) for(i=0; i<(j); ++i)
#define MAX_CLOCK_SIZE (16)
#define MAX_SWITCH_SIZE (10)

#define MIN(a,b) (a)>(b)?(b):(a)

#define debugf 
/*
[description]
pass 50 test case in 10s

clock show 12, 3, 6, 9
there are 16 clocks
there are 10 switches
*/

int org_clock[MAX_CLOCK_SIZE];
int clock[MAX_CLOCK_SIZE];
int switches[MAX_SWITCH_SIZE][MAX_CLOCK_SIZE] 
	= { {1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,0},
		{0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,1},
		{1,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,1,1,0,1,0,1,0,0,0},
		{1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1},
		{0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1},
		{0,0,0,0,1,1,0,1,0,0,0,0,0,0,1,1},
		{0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,1,1,1,0,0,0,1,0,0,0,1,0,0}};

int finish_index_of_clock[MAX_CLOCK_SIZE]
	= {5,8,8,9,9,9,4,7,4,9,4,1,4,9,7,7};

int num_of_switch_for_clock[MAX_CLOCK_SIZE]
	= {3,2,3,4,5,4,2,4,1,2,2,1,1,1,4,4};

int min_switch_count;
int switch_count;

void init()
{
	int i;
	FOR(i, MAX_CLOCK_SIZE)
	{
		clock[i] = org_clock[i];
	}
	switch_count = 0;
}

int promising(int switch_index, int count)
{
	int i;

	FOR(i, MAX_CLOCK_SIZE)
	{
		if (switches[switch_index][i] == 0)
		{
			continue;
		}
		else
		{
			if (finish_index_of_clock[i] == switch_index)
			{
				if (((clock[i] + count) + 4 ) % 4 != 0)
				{
					//debugf("[%d]impossible clock[%d] %d\n", switch_index, i, clock[i]);
					return -1;
				}
			}
			else
			{
				// remaining switch is enough?
			}
		}
	}
	return 0;
}

void decrease_clock(int switch_index, int count)
{
	int i;
	FOR(i, MAX_CLOCK_SIZE)
	{
		if (switches[switch_index][i] == 1)
		{
			clock[i] = ((clock[i] - count) + 4 ) % 4;
		}
	}
}

void increase_clock(int switch_index, int count)
{
	int i;
	FOR(i, MAX_CLOCK_SIZE)
	{
		if (switches[switch_index][i] == 1)
		{
			clock[i] = ((clock[i] + count) + 4 ) % 4;
		}
	}
}

int get_answer(int switch_index)
{
	int i;

	for (i = 0; i < 4; ++i)
	{
		//debugf("S%d[%d]\n", switch_index, i);
		if (switch_index == 0)
		{
			init();
		}

		if(promising(switch_index, i) >= 0)
		{
			debugf("S%dC%d [%d]\n",switch_index, i, switch_count);
			switch_count += i;
			increase_clock(switch_index, i);
			if (switch_index == MAX_SWITCH_SIZE -1)
			{
				debugf("[FINAL] switch_count %d M(%d)\n", switch_count, min_switch_count);
				if (min_switch_count == -1 )
				{
					min_switch_count = switch_count;
					//return min_switch_count;
				}
				else
				{
					min_switch_count = MIN(min_switch_count, switch_count);
					debugf("[MIN] %2d\n", min_switch_count);
					//return min_switch_count;
				}
			}
			else
			{
				get_answer(switch_index+1);
			}
			decrease_clock(switch_index, i);
			switch_count -= i;
		}
		else
		{
			debugf("Skip S%dC%d [%d]\n", switch_index, i, switch_count);
		}
	}

	return min_switch_count;
}

int main()
{
	int test_case = 0;
	int i = 0;
	int j = 0;
	int num_of_clocks = 16;
	int clock_value = 0;

	scanf("%d", &test_case);

	FOR(i, test_case)
	{
		FOR(j, num_of_clocks)
		{
			scanf("%d", &clock_value);
			org_clock[j] = (clock_value / 3) % 4;
		}
		min_switch_count = -1;
		switch_count = 0;
		printf("%d\n", get_answer(0));
	}
}
