#include <stdio.h>
#include <assert.h>

#define FOR(i,j) for(i=0; i<(j); ++i)
#define MAX(a,b) (a)>(b)? (a):(b)
#define MIN(a,b) (a)>(b)? (b):(a)

#define MAX_BOOK_SIZE (200)
#define MAX_STORE_SIZE (100)
#define MAX_PRICE (10000)
#define debugf

#define NO (-1)
#define YES (1)

typedef struct {
	int price;
	int point;
} Book;
Book item[MAX_STORE_SIZE][MAX_BOOK_SIZE];

int sum_price;

void init(int num_of_store)
{
	sum_price = 0;
}

void swap(Book data[], int i, int j)
{
	debugf("swap %d %d\n", i, j);
	if (i != j)
	{
		int temp_price;
		int temp_point;
		temp_price = data[i].price;
		temp_point = data[i].point;
		data[i].price = data[j].price;
		data[i].point = data[j].point;
		data[j].price = temp_price;
		data[j].point = temp_point;
	}
}

int partition(Book data[], int front, int rear)
{
	debugf("partition %d %d\n", front, rear);
	int pivot_position = rear;
	int pivot_value = data[rear].point;

	int seek_index = front;
	int smaller_index = front -1;

	for(seek_index = front; seek_index < rear; seek_index++)
	{
		if (data[seek_index].point < pivot_value)
		{
			smaller_index++;
			swap(data, seek_index, smaller_index);
		}
		else if (data[seek_index].point == pivot_value)
		{
			if (data[seek_index].price < data[rear].price)
			{
				smaller_index++;
				swap(data, seek_index, smaller_index);
			}
		}
	}

	smaller_index++;
	swap(data, smaller_index, pivot_position);
	return smaller_index;
}

void quick_sort(Book data[], int front, int rear)
{
	if (front < rear)
	{
		int pivot_position = partition(data, front, rear);
		quick_sort(data, front, pivot_position -1);
		quick_sort(data, pivot_position+1, rear);
	}
}

int get_answer(int num_of_book, int num_of_store)
{
	int i;
	int j;

	int point = 0;
	int price = 0;
	int min_price = MAX_PRICE*MAX_BOOK_SIZE + 1;

	for(i = 0; i < num_of_store; ++i)
	{
		debugf("%d sorting\n", i);
		quick_sort(&item[i][0], 0, num_of_book -1);
	}

	for(i = 0; i < num_of_store; ++i)
	{
		for(j= 0; j < num_of_book -1; ++j)
		{
			assert(item[i][j].point <= item[i][j+1].point);
		}
	}

	for(i = 0; i< num_of_store; ++i)
	{
		price = 0;
		point = 0;
		for(j = num_of_book -1; j >=0; --j)
		{
			debugf("[%d][%d]\n", i, j);
			if (point >= item[i][j].price)
			{
				debugf("point %d >= item price %d\n", point, item[i][j].price);
				point = point - item[i][j].price + item[i][j].point;
			}
			else
			{
				price = price + item[i][j].price - point;
				debugf("point %d < item price %d price %d\n", point, item[i][j].price, price);
				point = item[i][j].point;
			}
		}
		debugf("compare %d %d\n", min_price, price);
		min_price = MIN(min_price, price);
	}

	return min_price;
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
		init(M);
		FOR(j, N)
		{
			FOR(k, M)
			{
				scanf("%d %d", &item[k][j].price, &item[k][j].point);
			}
		}
		printf("%d\n", get_answer(N, M));
	}

	return 0;
}
