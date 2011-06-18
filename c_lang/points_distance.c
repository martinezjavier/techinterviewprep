#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define POINTS_COUNT 10

struct point {
	int x;
	int y;
	int z;
	double distance;
};

struct point* init_point(void);
void print_points(struct point *points[]);
void calc_distance(struct point*, struct point*);
int compare(const void *a, const void *b);

int main(void)
{
	struct point *points[POINTS_COUNT];

	struct point init;

	int i;

	init.x = 0;
	init.y = 0;
	init.z = 0;

	for (i = 0; i < POINTS_COUNT; i++) {
		points[i] = init_point();
		calc_distance(&init, points[i]);
	}

	qsort(points, POINTS_COUNT, sizeof(*points), &compare);

	print_points(points);
	
}

struct point* init_point(void)
{
	struct point *p = (struct point*)malloc(sizeof(struct point));

	p->x = rand() % 10;
	p->y = rand() % 10;
	p->z = rand() % 10;
	p->distance = 0.0;

	return p;
}

void print_points(struct point *points[])
{
	int i;

	for (i = 0; i < POINTS_COUNT; i++)
		printf("POINT X = %d Y = %d Z = %d distance = %2f\n", points[i]->x, points[i]->y, points[i]->z, points[i]->distance);       
}

void calc_distance(struct point *init, struct point *p)
{
	p->distance = sqrt(pow(p->x - init->x, 2) + pow(p->y - init->y, 2) + pow(p->z - init->z, 2));
}

int compare(const void *a, const void *b)
{
	struct point *point_a = *(struct point **)a;
	struct point *point_b = *(struct point **)b;

	printf("%f %f\n", point_a->distance, point_b->distance);
	printf("Diff = %f\n", point_a->distance - point_b->distance);
	return point_a->distance - point_b->distance;
}
