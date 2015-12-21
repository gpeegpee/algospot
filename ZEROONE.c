#include <stdio.h>

#define FOR(i,j) for(i=0; i<(j); ++i)
#define MAX_PERMUTATION (1000000)
#define NUM_OF_PROBLEM (100000)

#define debugf 

char permutation_str[MAX_PERMUTATION+1];

typedef struct
{
	int front;
	int rear;
} Section;

Section data[MAX_PERMUTATION];
int count;
int length;

int result[MAX_PERMUTATION];
Section problem[MAX_PERMUTATION];

void setup()
{
	int i = 0;
	count = 0;
	length = 0;

	FOR(i, MAX_PERMUTATION / 2)
	{
		data[i].front = -1;
		data[i].rear = -1;
	}

	i = 0;
	while(permutation_str[i] != '\0')
	{
		debugf("%d loop\n", i);
		if (permutation_str[i] == '1')
		{
			if (data[count].front == -1)
			{
				debugf("[%d] 1 found\n", i);
				data[count].front = i;
			}
			else
			{
				// continue
			}
		}
		else // 0
		{
			if (data[count].front == -1)
			{
				// continue
			}
			else
			{
				debugf("[%d] 0 found\n", i);
				data[count].rear =  i - 1;
				++count;
			}
		}
		length = i;
		++i;
	}

	if (data[count].front != -1 && data[count].rear == -1)
	{
		data[count].rear = i - 1;
	}
}

int search(Section data[], int front, int rear, int value)
{
	debugf("%d-%d search %d\n", front, rear, value);
	if (front == rear)
	{
		return front;
	}

	int mid = front + (rear - front) / 2;

	if (data[mid].front == value)
	{
		return mid;
	}
	else if (data[mid].front < value)
	{
		return search(data, mid +1, rear, value);
	}
	else
	{
		return search(data, front, mid-1, value);
	}
}

/*******************************
  !            !               !          !
		       ************
  **************
                  **********
                  ******************
*/

int get_answer(int front, int rear)
{
	if (front > rear)
	{
		int temp = front;
		front = rear;
		rear = temp;
	}

	int result = 0;

	int index = search(data, 0, count, front);

	debugf("index %d front %d rear %d data.front %d data.rear %d\n"
		, index, front, rear, data[index].front, data[index].rear);

	if (front <= data[index].rear && rear > data[index].rear)
	{
		return 0;
	}
	else if (front >= data[index].front && rear <= data[index].rear)
	{
		return 1;
	}
	else if (front > data[index].rear && count >= index+1 && rear < data[index+1].front)
	{
		return 1;
	}
	else if (front > data[index].rear && count >= index+1 && rear >= data[index+1].front)
	{
		return 0;
	}
	else if (front < data[index].front && rear < data[index].front)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	int i = 0;
	int N;

	int front;
	int rear;

	scanf("%s", permutation_str);
	scanf("%d", &N);
	FOR(i, N)
	{
		scanf("%d %d", &problem[i].front, &problem[i].rear);
	}
	setup();
	FOR(i, N)
	{
		result[i] = get_answer(problem[i].front, problem[i].rear);
	}
	FOR(i, N)
	{
		printf("%s\n", result[i] == 1 ? "Yes" : "No");
	}
	return 0;
}
