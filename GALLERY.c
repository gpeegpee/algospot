#include <stdio.h>

#define FOR(i,j) for(i=0; i<(j); ++i)
#define MAX_SIZE (500)
#define MAX(a,b) (a)>(b)? (a):(b)
#define MIN(a,b) (a)>(b)? (b):(a)
#define debugf printf

#define MAX_GALLERY (1000)

#define UNWATCHED (0)
#define WATCHED (1)
#define INSTALLED (2)

int graph[MAX_GALLERY][MAX_GALLERY];
int visited[MAX_GALLERY];
int installed_camera;

void init(int num_of_gallery)
{
	int i, j;
	FOR(i, num_of_gallery)
	{
		FOR(j, num_of_gallery)
		{
			graph[i][j] = 0;
		}
		visited[i] = 0;
	}
	installed_camera = 0;
}

// return vertex status(UNWATCHED, WATCHED, INSTALLED)
int dfs(int vertex_index, int num_of_gallery)
{
	visited[vertex_index] = 1;

	int i;
	int children[3] = {0, 0, 0};

	FOR(i, num_of_gallery)
	{
		if (i != vertex_index && graph[vertex_index][i] == 1) // child
		{
			if(visited[i] == 0)
			{
				++children[dfs(i, num_of_gallery)];
			}
		}
	}

	if (children[UNWATCHED])
	{
		++installed_camera;
		return INSTALLED;
	}

	if (children[INSTALLED])
	{
		return WATCHED;
	}

	return UNWATCHED;
}

int get_answer(int num_of_gallery)
{

	int i;

	FOR(i, num_of_gallery)
	{
		if (visited[i] == 0)
		{
			if (dfs(i, num_of_gallery) == UNWATCHED)
			{
				++installed_camera;
			}
			else
			{

			}
		}
		else
		{

		}
	}

	return installed_camera;
}

int main()
{
	int test_case = 0;
	int G, H;
	int i,j;

	int a,b;

	scanf("%d", &test_case);

	FOR(i, test_case)
	{
		scanf("%d %d", &G, &H);
		init(G);
		FOR(j, H)
		{
			scanf("%d %d", &a, &b);
			graph[a][b] = 1;
			graph[b][a] = 1;
		}
		printf("%d\n", get_answer(G));
	}

	return 0;
}
