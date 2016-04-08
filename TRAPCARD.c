#include <stdio.h>

#define FOR(i,j) for(i=0; i<(j); ++i)
#define MAX_SIZE (500)
#define MAX(a,b) (a)>(b)? (a):(b)
#define MIN(a,b) (a)>(b)? (b):(a)
#define debugf printf

#define MAX_ROW (20)
#define MAX_COL (20)

char board[MAX_ROW][MAX_COL+1];

void init(int size_of_number)
{

}

void debug(int row, int col)
{
	int i,j;
	FOR(i, row)
	{
		FOR(j, col)
		{
			debugf("%c", board[i][j] == '#'? 'O' : '.');
		}
		debugf("\n");
	}
}

int get_answer(int row, int col)
{
	debug(row,col);
	return 0;
}

int main()
{
	int test_case = 0;
	int H, W;
	int i,j,k;

	scanf("%d", &test_case);

	FOR(i, test_case)
	{
		scanf("%d %d", &H, &W);
		FOR(j, H)
		{
			scanf("%s", &board[j][0]);
		}
		printf("%d\n", get_answer(H, W));
	}

	return 0;
}

/*
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

#define MAX_N (10)
#define MAX_M (10)

// A와 B의 정점의 개수
int n, m;
// adj[i][j] = Ai와 Bj가 연결되어 있는가?
bool adj[MAX_N][MAX_M];
// 각 정점에 매칭된 상대 정점의 번호를 저장한다
vector<int> aMatch, bMatch;
// dfs()의 방문 여부
vector<bool> visited;

// A의 정점인 a에서 B의 매칭되지 않은 정점으로 가는 경로를 찾는다
bool dfs(int a) {
	printf("dfs(%d)\n", a);

    if (visited[a]) {
    	printf("\talready visited(%d)\n", a);
    	return false;
    }
    visited[a] = true;

    for (int b=0; b<m; ++b) {
        if (adj[a][b] && bMatch[b] != a) {
            // b가 매칭되어 있지 않다면 bMatch[b]에서부터 시작해 증가 경로를 찾는다
            if (bMatch[b] == -1 || dfs(bMatch[b])) {
                // 증가 경로 발견, a와 b를 매칭시킨다
                aMatch[a] = b;
                bMatch[b] = a;
                printf("\tmatched(%d %d)\n", a, b);
                return true;
            }
        }
    }

    printf("\tno matched with %d\n", a);
    return false;
}

// aMatch, bMatch 배열을 계산하고 최대 매칭의 크기를 반환한다
int bipartiteMatch() {
    // 처음에는 어떤 정점도 연결되어 있지 않다
    aMatch = vector<int>(n, -1);
    bMatch = vector<int>(m, -1);

    int size = 0;
    for (int start=0; start<n; ++start) {
        visited = vector<bool>(n, false);
        // 깊이 우선 탐색을 이용해 start에서 시작하는 증가 경로를 찾는다
        if (dfs(start))
            ++size;
    }

    return size;
}

int main()
{
	n = 10;
	m = 10;

	int i,j;
	for(i=0; i < 10; ++i)
	{
		for(j=0; j <10; ++j)
		{
			if (i == j)
			{
				adj[i][j] = true;
			}
			else
			{
				adj[i][j] = false;
			}
		}
	}
	int size = bipartiteMatch();

	for(i=0; i< 10; ++i)
	{
		printf("[%d]aMatch %d\n", i, aMatch[i]);
	}

	printf("%d\n", size);
}

*/