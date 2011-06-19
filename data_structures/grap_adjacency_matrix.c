#include <stdio.h>

#define GRAPH_SIZE 10

int graph[GRAPH_SIZE][GRAPH_SIZE];
int processed[GRAPH_SIZE];
int discovered[GRAPH_SIZE];
int parent[GRAPH_SIZE];

#define NONE -1
#define DISCOVERED 1
#define UNDISCOVERED 0
#define PROCESSED 1
#define UNPROCESSED 0

void connect(int, int);
void disconnect(int, int);
int connected(int, int);
int reachable(int, int);
void bfs(int);
void init_graph(void);
int exists_path(int, int);
int do_exists_path(int, int);
void print_adjacency_matrix(void);

int main(void)
{
	connect(1, 4);
	connect(4, 2);
	connect(4, 5);
	connect(2, 5);
	connect(3, 5);
	connect(8, 6);
	connect(8, 7);

	printf("Exists path between %d and %d? %s\n", 1, 3, exists_path(1, 3) ? "yes" : "no");
	printf("Exists path between %d and %d? %s\n", 7, 6, exists_path(7, 6) ? "yes" : "no");
	printf("Exists path between %d and %d? %s\n", 1, 8, exists_path(1, 8) ? "yes" : "no");             

	print_adjacency_matrix();
}

void connect(int i, int j)
{
	graph[i][j] = 1;
	graph[j][i] = 1;
}

void disconnect(int i, int j)
{
	graph[i][j] = 0;
	graph[j][i] = 0;
}

int connected(int i, int j)
{
	return graph[i][j];
}

void bfs(int start)
{
	
}

void init_graph(void)
{
	int i;

	for (i = 0; i < GRAPH_SIZE; i++) {
		processed[i] = UNPROCESSED;
		discovered[i] = UNDISCOVERED;
		parent[i] = NONE;
	}
}

int exists_path(int src, int dest)
{
	init_graph();
	return do_exists_path(src, dest);
}

int do_exists_path(int src, int dest)
{
	int i;

	processed[src] = PROCESSED;

	if (src == dest)
		return 1;

	for (i = 0; i < GRAPH_SIZE; i++) {
		if (graph[src][i] && !processed[i])
			if (do_exists_path(i, dest))
				return 1;
	}

	return 0;
}

void print_adjacency_matrix(void)
{
	int i,j;

	for (i = 0; i < GRAPH_SIZE; i++) {
		for (j = 0; j < GRAPH_SIZE; j++) 
			printf("%d ", graph[i][j]);
		printf("\n");
	}
}
