
#include <stdio.h>
#include <string.h>

#define MAX_LEN (10000)
char pi[MAX_LEN + 1] = { 0, };

#define THREE_WORDS (0)
#define FOUR_WORDS (1)
#define FIVE_WORDS (2)

#define MIN(a, b) ((a) > (b) ? (b):(a))

int level[MAX_LEN][3] = { 0, };

int get_level(int index, int words)
{
	if (strlen(pi) < (index + words + 2)) {
		return 1000;
	}

	if (level[index][words] != 0) {
		return level[index][words];
	}
	
	if (words == THREE_WORDS) {
		if (pi[index] == pi[index + 1] && pi[index] == pi[index + 2]) {
			level[index][words] = 1;
			return 1;
		}
		else if (pi[index] + 1 == pi[index+1] && pi[index] +2 == pi[index+2]) {
			level[index][words] = 2;
			return 2;
		}
		else if (pi[index] - 1 == pi[index + 1] && pi[index] - 2 == pi[index + 2]) {
			level[index][words] = 2;
			return 2;
		}
		else if (pi[index] == pi[index + 2]) { // zigzag
			level[index][words] = 4;
			return 4;
		}
		else if ((pi[index] - pi[index+1]) == (pi[index+1] - pi[index+2])) {
			level[index][words] = 5;
			return 5;
		}
		else {
			level[index][words] = 10;
			return 10;
		}
	}
	else if (words == FOUR_WORDS) {
		if (pi[index] == pi[index + 1] && pi[index] == pi[index + 2] && pi[index] == pi[index+3]) {
			level[index][words] = 1;
			return 1;
		}
		else if (pi[index] + 1 == pi[index + 1] && pi[index] + 2 == pi[index + 2] && pi[index]+3 == pi[index+3]) {
			level[index][words] = 2;
			return 2;
		}
		else if (pi[index] - 1 == pi[index + 1] && pi[index] - 2 == pi[index + 2] && pi[index] - 3 == pi[index + 3]) {
			level[index][words] = 2;
			return 2;
		}
		else if (pi[index] == pi[index + 2] && pi[index+1] == pi[index+3]) { // zigzag
			level[index][words] = 4;
			return 4;
		}
		else if ((pi[index] - pi[index + 1]) == (pi[index + 1] - pi[index + 2]) &&
			(pi[index+1] - pi[index + 2]) == (pi[index + 2] - pi[index + 3])) {
			level[index][words] = 5;
			return 5;
		}
		else {
			level[index][words] = 10;
			return 10;
		}
	}
	else {
		if (pi[index] == pi[index + 1] && pi[index] == pi[index + 2] && pi[index] == pi[index + 3] && pi[index] == pi[index + 4]) {
			level[index][words] = 1;
			return 1;
		}
		else if (pi[index] + 1 == pi[index + 1] && pi[index] + 2 == pi[index + 2] && pi[index] + 3 == pi[index + 3] && pi[index] +4 == pi[index+4]) {
			level[index][words] = 2;
			return 2;
		}
		else if (pi[index] - 1 == pi[index + 1] && pi[index] - 2 == pi[index + 2] && pi[index] - 3 == pi[index + 3] && pi[index] - 4 == pi[index + 4]) {
			level[index][words] = 2;
			return 2;
		}
		else if (pi[index+1] == pi[index + 3] && pi[index] == pi[index + 2] && pi[index] == pi[index+4]) { // zigzag
			level[index][words] = 4;
			return 4;
		}
		else if ((pi[index] - pi[index + 1]) == (pi[index + 1] - pi[index + 2]) &&
			(pi[index + 1] - pi[index + 2]) == (pi[index + 2] - pi[index + 3]) &&
			(pi[index + 2] - pi[index + 3]) == (pi[index + 3] - pi[index + 4])) {
			level[index][words] = 5;
			return 5;
		}
		else {
			level[index][words] = 10;
			return 10;
		}
	}
}

int get_min_level(int index)
{
	int min_level1 = get_level(index, THREE_WORDS) + get_min_level(index + 3);
	int min_level2 = get_level(index, FOUR_WORDS) + get_min_level(index + 4);
	int min_level3 = get_level(index, FIVE_WORDS) + get_min_level(index + 5);

	int min_temp = MIN(min_level1, min_level2);
	int min = MIN(min_temp, min_level3);
	return min;
}

int get_result()
{
	int i = 0;
	for (i = 0; i < strlen(pi); i++) {
		get_level(i, THREE_WORDS);
		get_level(i, FOUR_WORDS);
		get_level(i, FIVE_WORDS);
	}
	return get_min_level(0);
}

int main()
{
	int test_case = 0;
	int i = 0;
	int length = 0;
	int answer = 0;

	scanf("%d", &test_case);

	for (i = 0; i < test_case; i++) {
		scanf("%s", &pi[0]);
		answer = get_result();
		printf("%d\n", answer);
		memset(&pi[0], 0x00, sizeof(pi));
		memset(&level[0][0], 0x00, sizeof(level));
	}
}
