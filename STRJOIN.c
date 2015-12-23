#include <stdio.h>

#define FOR(i,j) for(i=0; i<(j); ++i)
#define MAX_SIZE (100)
#define MAX(a,b) (a)>(b)? (a):(b)
#define MIN(a,b) (a)>(b)? (b):(a)

#define debugf

int str_length[MAX_SIZE];
int min_cost;

void init()
{
	min_cost = 0;
}

void debug_array()
{
	int i;
	FOR(i, MAX_SIZE)
	{
		debugf("%d ", str_length[i]);
	}
	debugf("\n");
}

void swap(int data[], int i, int j)
{
	if (i != j)
	{
		int temp = data[i];
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

	for(seek_index = front; seek_index < rear; seek_index++)
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

int quick_select(int data[], int front, int rear, int kth)
{
	if (front < rear)
	{
		int position = partition(data, front, rear);
		if (kth == position)
		{
			return data[kth];
		}
		else if (kth > position)
		{
			quick_select(data, position+1, rear, kth - position);
		}
		else
		{
			quick_select(data, front, position -1, kth);
		}
	}
	return data[kth];
}

int get_answer(int str_length[], int front, int rear)
{
	int i;
	int end = rear;
	int min_value;

	for (i = front; i < rear; ++i, --end)
	{
		min_value = quick_select(&str_length[i], 0, end, 0);
		min_cost += min_value;
		debugf("min %d\n", min_value);
		min_value = quick_select(&str_length[i+1], 0, end - i - 1, 0);
		min_cost += min_value;
		debugf("min %d\n", min_value);
		str_length[i+1] += str_length[i];
		debugf("MIN %d end %d\n", min_cost, end);
		debug_array();
	}
	return min_cost;
}

int main()
{
	int test_case = 0;
	int N = 0;
	int i,j;

	scanf("%d", &test_case);

	FOR(i, test_case)
	{
		scanf("%d", &N);
		init();
		FOR(j, N)
		{
			scanf("%d", &str_length[j]);
		}
		printf("%d\n", get_answer(str_length, 0, N-1));
	}

	return 0;
}
