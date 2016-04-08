#include <stdio.h>

#define FOR(i,j) for(i=0; i<(j); ++i)
#define MAX(a,b) (a)>(b)? (a):(b)
#define MIN(a,b) (a)>(b)? (b):(a)
#define debugf printf

#define MAX_ROW (100)
#define MAX_COL (10)
#define MAX_ALPHABET_NUM (26)

typedef struct
{
	char word[MAX_COL+1];
	int first_alphabet;
	int last_alphabet;
} word_s;
word_s data[MAX_ROW];

void init()
{
	int i, j;
}

int get_answer(int num_of_row)
{
	int i;
	return 0;
}

int main()
{
	int test_case = 0;
	int N;
	int i,j,k;

	scanf("%d", &test_case);

	FOR(i, test_case)
	{
		init();
		scanf("%d", &N);
		FOR(j, N)
		{
			scanf("%s", &(data[j].word[0]));
		}
		get_answer(N);
		//printf("%s\n", result);
	}

	return 0;
}
