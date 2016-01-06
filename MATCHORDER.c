#include <stdio.h>

#define FOR(i,j) for(i=0; i<(j); ++i)
#define MAX(a,b) (a)>(b)? (a):(b)
#define MIN(a,b) (a)>(b)? (b):(a)

#define MAX_N_SIZE (100)
#define MAX_RATING (4000)
#define debugf

#define NO (-1)
#define YES (1)

int RussiaRating[MAX_N_SIZE];
int KoreaRating[MAX_N_SIZE];
int KoreaPlayed[MAX_N_SIZE];
int WinCount;

void init(int num_of_player)
{
	int i;
	FOR(i, num_of_player)
	{
		KoreaPlayed[i] = 0;
	}
	WinCount = 0;
}

int get_answer(int num_of_player)
{
	int i;
	int j;
	int min = 0;
	int min_index = 0;

	FOR(i, num_of_player)
	{
		min_index = -1;
		min = MAX_RATING + 1;
		FOR(j, num_of_player)
		{
			if (KoreaPlayed[j] == 0 && KoreaRating[j] >= RussiaRating[i])
			{
				if (min > KoreaRating[j])
				{
					debugf("min(%d) > KoreaRating(%d)\n", min, KoreaRating[j]);
					min = KoreaRating[j];
					min_index = j;
				}
			}
		}
		if (min_index != -1)
		{
			debugf("Korea[%d] %d win Russia[%d] %d\n", min_index, KoreaRating[min_index], i, RussiaRating[i]);
			WinCount++;
			KoreaPlayed[min_index] = 1;
		}
	}

	return WinCount;
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
		init(N);
		FOR(j, N)
		{
			scanf("%d", &RussiaRating[j]);
		}
		FOR(j, N)
		{
			scanf("%d", &KoreaRating[j]);
		}
		printf("%d\n", get_answer(N));
	}

	return 0;
}
