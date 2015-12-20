#include <stdio.h>

#define FOR(i,j) for(i=0; i<(j); ++i)
#define MAX_SIZE (10000)

int man[MAX_SIZE];
int woman[MAX_SIZE];

void swap(int data[], int i, int j)
{
	if (i != j)
	{
		int temp;
		temp = data[i];
		data[i] = data[j];
		data[j] = temp;
	}
}

int partition(int data[], int front, int rear)
{
	int pivot_value = data[rear];
	int pivot_position = rear;

	int seek_index = front;
	int smaller_index = front -1;

	for (seek_index = front; seek_index < rear; ++seek_index)
	{
		if (data[seek_index] < pivot_value)
		{
			++smaller_index;
			swap(data, smaller_index, seek_index);
		}
	}

	++smaller_index;
	swap(data, smaller_index, pivot_position);
	return smaller_index;
}

void quick_sort(int data[], int front, int rear)
{
	if (front < rear)
	{
		int pivot_position = partition(data, front, rear);
		quick_sort(data, front, pivot_position -1);
		quick_sort(data, pivot_position +1, rear);
	}
}

int get_answer(const int num_of_member)
{
	quick_sort(man, 0, num_of_member-1);
	quick_sort(woman, 0, num_of_member-1);

	int i;
	int result = 0;
	int temp = 0;
	FOR(i, num_of_member)
	{
		temp = man[i] - woman[i];
		result += (temp > 0 ? temp: -temp);
	}
	return result;
}

int main()
{
	int test_case = 0;
	int i = 0;
	int j;
	int N;

	scanf("%d", &test_case);

	FOR(i, test_case)
	{
		scanf("%d", &N);
		FOR(j, N)
		{
			scanf("%d", &man[j]);
		}
		FOR(j, N)
		{
			scanf("%d", &woman[j]);
		}
		printf("%d\n", get_answer(N));
	}
}
