#include <stdio.h>

/*
[Description]
 run in 1 sec for 50 test case
 limited in 64MB

(1 <= N <= 100, 1 <= M <= N)
N, M, K input
total of korea, china, japan respectively <= 1,000,000

N : vote from korea
M : number of inviting persons
K : total vote from japan

X1 * A + X2 * B +  X3 * (100 - A - B)
minimize A

player having most N should be selected

A B
1 1
1 2
1 3
1 99
2 1
2 2
2 98
*/

#define MAX (100)

typedef struct
{
	int korea_vote;
	int china_vote;
	int japan_vote;
} Member;
Member data[MAX];

/* This function is same in both iterative and recursive*/
int partition (int front, int rear)
{
	int pivot_position = rear;
    long long pivot_value = data[rear].hash;
    assert(pivot_value != 0);

    int smaller_index = (front - 1);
    for (int seek_index = front; seek_index < rear; seek_index++)
    {
        if (data[seek_index].hash <= pivot_value)
        {
            ++smaller_index;
            swap_hash(smaller_index, seek_index);
        }
    }
    swap_hash(smaller_index+1, pivot_position);
    return (smaller_index + 1);
}

void quick_sort(int front, int rear)
{
	if (front < rear)
	{
		int pivot_position = partition(front, rear);
		quick_sort(front, pivot_position - 1);
		quick_sort(pivot_position+1, rear);
	}
}


int main(void)
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%s",a);
		for(i=0;a[i];++i)if(!(i&1))putchar(a[i]);
		for(i=0;a[i];++i)if( (i&1))putchar(a[i]);
		putchar('\n');
	}
	return 0;
}