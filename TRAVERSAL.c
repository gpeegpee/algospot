#include <stdio.h>
#include <assert.h>

#define FOR(i,j) for(i=0; i<(j); ++i)
#define MAX(a,b) (a)>(b)? (a):(b)
#define MIN(a,b) (a)>(b)? (b):(a)

#defnie MAX_NODE_SIZE (1000)
#define debugf printf

#define NO (-1)
#define YES (1)

int preorder_node[MAX_NODE_SIZE];
int inorder_node[MAX_NODE_SIZE];
int postorder_node[MAX_NODE_SIZE];

void init(int node_size)
{

}

int get_answer(int node_size)
{
	int i;
	int j;
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
			scanf("%d", &preorder_node[j]);
		}
		FOR(j, N)
		{
			scanf("%d", &inorder_node[j]);
		}
		get_answer(N);
		FOR(j, N)
		{
			printf("%d ", postorder_node[j]);
		}
		printf("\n");
	}

	return 0;
}
