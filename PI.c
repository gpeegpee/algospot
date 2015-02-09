#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define debug

#define MAX_LEN (10000)
#define THREE_WORDS (3)
#define FOUR_WORDS (4)
#define FIVE_WORDS (5)
#define MIN(a, b) ((a) > (b) ? (b):(a))
#define INF (1000)

char pi[MAX_LEN + 1] = { 0, };
//int level[MAX_LEN][3] = { 0, };

int cache[MAX_LEN] = { 0, };
int length = 0;

int get_level(int index, int words)
{
	debug("index %d word %d\n", index, words);
	if (length < (index + words)) {
		return 0;
	}

	if (words == THREE_WORDS) {
		if (pi[index] == pi[index + 1] && pi[index] == pi[index + 2]) {
			//level[index][words] = 1;
			return 1;
		}
		else if ((pi[index] + 1) == pi[index + 1] && (pi[index] + 2) == pi[index + 2]) {
			//level[index][words] = 2;
			return 2;
		}
		else if ((pi[index] - 1) == pi[index + 1] && (pi[index] - 2) == pi[index + 2]) {
			//level[index][words] = 2;
			return 2;
		}
		else if (pi[index] == pi[index + 2]) { // zigzag
			//level[index][words] = 4;
			return 4;
		}
		else if ((pi[index] - pi[index + 1]) == (pi[index + 1] - pi[index + 2])) {
			//level[index][words] = 5;
			return 5;
		}
		else {
			//level[index][words] = 10;
			return 10;
		}
	}
	else if (words == FOUR_WORDS) {
		if (pi[index] == pi[index + 1] && pi[index] == pi[index + 2] && pi[index] == pi[index + 3]) {
			//level[index][words] = 1;
			return 1;
		}
		else if ((pi[index] + 1) == pi[index + 1] && (pi[index] + 2) == pi[index + 2] && (pi[index] + 3) == pi[index + 3]) {
			//level[index][words] = 2;
			return 2;
		}
		else if ((pi[index] - 1) == pi[index + 1] && (pi[index] - 2) == pi[index + 2] && (pi[index] - 3) == pi[index + 3]) {
			//level[index][words] = 2;
			return 2;
		}
		else if (pi[index] == pi[index + 2] && pi[index + 1] == pi[index + 3]) { // zigzag
			//level[index][words] = 4;
			return 4;
		}
		else if ((pi[index] - pi[index + 1]) == (pi[index + 1] - pi[index + 2]) &&
			(pi[index + 1] - pi[index + 2]) == (pi[index + 2] - pi[index + 3])) {
			//level[index][words] = 5;
			return 5;
		}
		else {
			//level[index][words] = 10;
			return 10;
		}
	}
	else {
		if (pi[index] == pi[index + 1] && pi[index] == pi[index + 2] && pi[index] == pi[index + 3] && pi[index] == pi[index + 4]) {
			//level[index][words] = 1;
			return 1;
		}
		else if ((pi[index] + 1) == pi[index + 1] && (pi[index] + 2) == pi[index + 2] && (pi[index] + 3) == pi[index + 3] && (pi[index] + 4) == pi[index + 4]) {
			//level[index][words] = 2;
			return 2;
		}
		else if ((pi[index] - 1) == pi[index + 1] && (pi[index] - 2) == pi[index + 2] && (pi[index] - 3) == pi[index + 3] && (pi[index] - 4) == pi[index + 4]) {
			//level[index][words] = 2;
			return 2;
		}
		else if (pi[index + 1] == pi[index + 3] && pi[index] == pi[index + 2] && pi[index] == pi[index + 4]) { // zigzag
			//level[index][words] = 4;
			return 4;
		}
		else if ((pi[index] - pi[index + 1]) == (pi[index + 1] - pi[index + 2]) &&
			(pi[index + 1] - pi[index + 2]) == (pi[index + 2] - pi[index + 3]) &&
			(pi[index + 2] - pi[index + 3]) == (pi[index + 3] - pi[index + 4])) {
			//level[index][words] = 5;
			return 5;
		}
		else {
			//level[index][words] = 10;
			return 10;
		}
	}
}

int get_min_level(int index)
{
	if (cache[index] != 0) {
		debug("return cache[%d] %d\n", index, cache[index]);
		return cache[index];
	}

	if (index >= length) {
		debug("EOF\n", index);
		return 0;
	}

	int ret = INF;
	int L = 0;
	for(L = 3; L <= 5; L++) {
		if (index + L > length) {
			debug("L(%d) index(%d) ret(%d)\n", L, index, ret);
			break;
		}
		ret = MIN(ret, get_level(index, L) + get_min_level(index + L));
		debug("min %d\n", ret);
	}
	cache[index] = ret;
	return ret;
}

void init()
{
	memset(&pi[0], 0x00, sizeof(pi));
	memset(&cache[0], 0x00, sizeof(cache));
	length = 0;
}

int main()
{
	int test_case = 0;
	int i = 0;
	int answer = 0;

	scanf("%d", &test_case);

	for (i = 0; i < test_case; i++) {
		scanf("%s", &pi[0]);
		length = strlen(pi);
		answer = get_min_level(0);
		printf("%d\n", answer);
		init();
	}
}
