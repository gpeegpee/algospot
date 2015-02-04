
#include <stdio.h>
#include <string.h>

#define FALSE !(TRUE)
#define TRUE	(1)
#define MAX_LEN (1000000)

int palindrome1[MAX_LEN + 1] = { 0, };
int palindrome2[MAX_LEN + 1] = { 0, };

char msg[MAX_LEN + 1] = { 0, };
int result = 0;
int length = 0;

int get_result(int length)
{
	if (length <= 1) {
		return result;
	}
	if (length == 2) {
		if (msg[0] == msg[1]) {
			result++;
			return result;
		}
		else {
			return result;
		}
	}

	int num_char = 0;
	int j = 0;

	// 2
	for (j = 0; j < length - 1; j++) {
		if (msg[j] == msg[j + 1]) {
			palindrome1[j] = 1;
			result++;
		}
		else {
			palindrome1[j] = 0;
		}
	}

	// 3
	for (j = 0; j < length - 2; j++) {
		if (msg[j] == msg[j + 2]) {
			palindrome2[j] = 1;
			result++;
		}
		else {
			palindrome2[j] = 0;
		}
	}

	// from 4

	for (num_char = 4; num_char < length; num_char++) {
		for (j = 0; j < length - num_char + 1; j++) {
			if (num_char % 2 == 0) {
				if (palindrome1[j + 1] == 0) {
					palindrome1[j] = 0;
				}
				else if (msg[j] == msg[j + num_char - 1]) {
					palindrome1[j] = 1;
					result++;
				}
				else {
					palindrome1[j] = 0;
				}
			}
			else {
				if (palindrome2[j + 1] == 0) {
					palindrome2[j] = 0;
				}
				else if (msg[j] == msg[j + num_char - 1]) {
					palindrome2[j] = 1;
					result++;
				}
				else {
					palindrome2[j] = 0;
				}
			}
		}
	}

	return 0;
}

int main()
{
	int test_case = 0;
	int i = 0;
	int length = 0;
	int answer = 0;
	
	scanf("%d", &test_case);

	for (i = 0; i < test_case; i++) {
		scanf("%d %s", &length, &msg);
		answer = get_result(length);
		printf("%d\n", answer);
		memset(&msg[0], 0x00, MAX_LEN);
		memset(palindrome1, 0x00, MAX_LEN);
		memset(palindrome2, 0x00, MAX_LEN);
		result = 0;
		length = 0;
	}
}
