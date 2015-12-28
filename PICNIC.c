#include <stdio.h>

#define FOR(i,j) for(i=0; i<(j); ++i)
#define MAX(a,b) (a)>(b)? (a):(b)
#define MIN(a,b) (a)>(b)? (b):(a)

#define MAX_N_SIZE (10)
#define debugf

#define NO (-1)
#define YES (1)

int couple[MAX_N_SIZE][MAX_N_SIZE];
int complete[MAX_N_SIZE];
int count;

void init(int num_of_students)
{
	int i;
	int j;
	FOR(i, num_of_students)
	{
		FOR(j, num_of_students)
		{
			couple[i][j] = NO;
		}
		complete[i] = NO;
	}
	count = 0;
}

int promising(int index_of_student, int couple_index)
{
	if (index_of_student == couple_index)
	{
		return NO;
	}

	if (complete[couple_index] != NO && complete[couple_index] != index_of_student)
	{
		return NO;
	}

	int max = MAX(index_of_student, couple_index);
	int min = MIN(index_of_student, couple_index);

	return couple[min][max];
}

int get_answer(int num_of_students, int num_of_couple, int index)
{
	debugf("Solve %d\n", index);
	int i;
	int j;

	if (complete[index] != NO)
	{
		if (index == num_of_students -1)
		{
			count++;
			debugf("Increase count %d\n", count);
			return count;
		}
		else
		{
			get_answer(num_of_students, num_of_couple, index+1);
			return count;
		}
	}

	for(i = 0; i < num_of_students; ++i)
	{
		if(promising(index, i) == YES)
		{
			debugf("[%d -> %d] couple\n", index, i);
			complete[index] = i;
			complete[i] = index;
			if (index == num_of_students -1)
			{
				count++;
				debugf("Increase count %d\n", count);
			}
			else
			{
				get_answer(num_of_students, num_of_couple, index+1);
			}
			complete[index] = NO;
			complete[i] = NO;
		}
	}

	return count;
}

int main()
{
	int test_case = 0;
	int N,M;
	int i,j,k;

	scanf("%d", &test_case);

	FOR(i, test_case)
	{
		scanf("%d %d", &N, &M);
		init(N);
		FOR(j, M)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			int max = MAX(a,b);
			int min = MIN(a,b);
			couple[min][max] = YES;
			couple[max][min] = YES;
		}
		printf("%d\n", get_answer(N, M, 0));
	}

	return 0;
}
