#include <stdio.h>
#include <string.h>

#define GRAPH_SIZE 10

int graph[GRAPH_SIZE][GRAPH_SIZE];
int processed[GRAPH_SIZE];
int discovered[GRAPH_SIZE];
int parent[GRAPH_SIZE];

#define NONE -1
#define DISCOVERED 1
#define UNDISCOVERED 0
#define FULLY_EXPLORED 2
#define PROCESSED 1
#define UNPROCESSED 0

void connect(int, int);
void disconnect(int, int);
int connected(int, int);
int reachable(int, int);
void bfs(int);
void do_bfs(int);
void dfs(int);
void do_dfs(int);
void init_graph(void);
int exists_path(int, int);
int do_exists_path(int, int);
void print_adjacency_matrix(void);
int is_tree(void);
int vertex_count(void);
int edge_count(void);

int main(void)
{
	connect(1, 2);
	connect(1, 3);
	connect(1, 4);
	connect(2, 5);
	connect(2, 6);
	connect(3, 7);
	connect(4, 8);
	connect(4, 9);

	printf("Graph characteristics\n");
	printf("Adjacency matrix\n");
	print_adjacency_matrix();
	printf("Number of vertexs %d\n", vertex_count());
	printf("Number of egdes %d\n", edge_count());

	printf("Exists path between %d and %d? %s\n", 1, 5, exists_path(1, 5) ? "yes" : "no");

	printf("The graph is a tree? %s\n", is_tree() ? "yes" : "no");
             
	printf("Bread First Search\n");
	bfs(1);
	printf("Deep First Search\n");
	dfs(1);
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
	init_graph();
	do_bfs(start);
}

void do_bfs(int start)
{
	int i;

	if (!discovered[start]) {
		printf("%d\n", start);
		discovered[start] = DISCOVERED;
		processed[start] = PROCESSED;
	}
		     
	for (i = 0; i < GRAPH_SIZE; i++) {
		if (graph[start][i] && !processed[i]) {
			processed[i] = PROCESSED;
			printf("%d\n", i);
		}
	}

	for (i = 0; i < GRAPH_SIZE; i++) {
		if (graph[start][i] && !discovered[i]) {
			discovered[i] = DISCOVERED;
			do_bfs(i);
		}
	}
}

void dfs(int start)
{
	init_graph();
	do_dfs(start);	
}

void do_dfs(int start)
{
		int i;

	if (!discovered[start]) {
		printf("%d\n", start);
		discovered[start] = DISCOVERED;
		processed[start] = PROCESSED;
	}
		     
	for (i = 0; i < GRAPH_SIZE; i++) {
		if (graph[start][i] && !discovered[i]) {
			do_bfs(i);
		}
	}
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

int is_tree(void)
{
	int i,j;
	int found = 0;
	int processed_count = 0;
	
	for (i = 0; i < GRAPH_SIZE && !found; i++)
		for (j = i; j < GRAPH_SIZE && !found; j++)
			if (graph[i][j]) {
				found = 1;
				dfs(i);
			}

	for (i = 0; i < GRAPH_SIZE; i++)
		if(processed[i])
			processed_count++;

	return processed_count == vertex_count() && edge_count() == processed_count - 1;
}

int vertex_count(void)
{
	int i, j;
	int vertex_found[GRAPH_SIZE];
	int vertex_count = 0;

	memset(vertex_found, 0, sizeof(int)*GRAPH_SIZE);

	for (i = 0; i < GRAPH_SIZE; i++)
		for (j = i; j < GRAPH_SIZE; j++)
			if (graph[i][j]) {
				vertex_found[i] = 1;
				vertex_found[j] = 1;				
			}
				
	for (i = 0; i < GRAPH_SIZE; i++)
		if(vertex_found[i])
			vertex_count++;

	return vertex_count;
}

int edge_count(void)
{
	int i,j;
	int edge_count = 0;

	for (i = 0; i < GRAPH_SIZE; i++)
		for (j = i; j < GRAPH_SIZE; j++)
			if (graph[i][j])
				edge_count++;

	return edge_count;
}
