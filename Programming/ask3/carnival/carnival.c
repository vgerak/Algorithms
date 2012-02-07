/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

 * File Name : carnival.c

 * Purpose : 3rd exercise in Algorithms

 * Creation Date : 18-01-2012

 * Last Modified : Fri Feb  3 02:12:36 2012

 * Created By : Vasilis Gerakaris <vgerak@gmail.com>

 _._._._._._._._._._._._._._._._._._._._._.*/

#include <stdio.h>
#include <stdlib.h>

/* Global variable Declaration */
unsigned int V, E;
long long unsigned int res1, res2;
unsigned int **parents;
unsigned int *edge_w;
unsigned int pathmax;

typedef struct edge_t edge_t;
struct edge_t {
    unsigned int n1;
    unsigned int n2;
    unsigned int cost;
    unsigned short int used;
};
edge_t *edges;

/* Union - Find functions */
void unify(unsigned int n1, unsigned int n2)
{
    parents[find(n1)][0] = find(n2);
}

int find(int n, int max)
{

    if (n == parents[n][0])
        return n;
    else
        if (parents[n][1] > max)
            pathmax = parents[n][1];
    return find(parents[n][0], pathmax);
}

int findset(long unsigned int n1, long unsigned int n2)
{
    if (find(n1, 0) == find(n2, 0))
        return 1;
    else
        return 0;
}

/* Compare function for qsort */
int compare(const void *a, const void *b)
{
    return ((*(edge_t *) a).cost - (*(edge_t *) b).cost);
}

/*
 * - Implementation of Kruskal's Algorithm for MST -
 *  Using Union-Find to calculate it and keeping the
 *  cost of the heaviest edge in each tree,
 *  to have the data ready for 2nd-MST.
 */
long long unsigned int mst()
{
    long long unsigned int cost;
    unsigned int i, num;

    qsort(edges, E, sizeof(edge_t), compare);   //Sort edges by ascending weight
    cost = 0;
    num = 0;
    for (i = 0; i < E; ++i)
    {
        if (num < V - 1)
        {
            if (findset(edges[i].n1, edges[i].n2) == 0)
            {
                unify(edges[i].n1, edges[i].n2);
                printf("%u now has %u as father!\n", edges[i].n1 + 1, edges[i].n2 + 1);
                parents[edges[i].n1][1] = edges[i].cost;
                pathmax = edges[i].cost;
                find(edges[i].n1, edges[i].cost);
                edge_w[i] = pathmax;
                edges[i].used = 1;
                cost += edges[i].cost;
                num++ ;
            }
        }
        else break;
    }
    return cost;
}

long long unsigned int sec_mst()
{
    unsigned int min, max, i;
    min = -1;
    for ( i = 0; i < E; ++i)
    {
        //printf("%u\n", i);
        if (edges[i].used == 0)
        {
            if (edges[i].cost - edge_w[i] < min)
                min = edges[i].cost - max;
        }
    }
    return (res1 + min);
}

int main()
{
    unsigned int i, j, k;
    /* Parse input, allocate memory */
    scanf("%u %u\n", &V, &E);
    parents = (unsigned int**) calloc(V, sizeof(unsigned int*));
    for (i = 0; i <= V; ++i)
        parents[i] = (unsigned int*) calloc(2, sizeof(unsigned int));
    edges = (edge_t *) calloc(E, sizeof(edge_t));
    edge_w = (unsigned int*) calloc(E, sizeof(unsigned int));
    for (i = 0; i < E; ++i)
    {
        scanf("%u %u %u\n", &j, &k, &edges[i].cost);
        edges[i].n1 = j - 1;
        edges[i].n2 = k - 1;
    }
    for (i = 0; i < V; ++i)
        parents[i][0] = i;

    res1 = mst();
    //printf("FOUND MST: %lu\n", res1);
    res2 = sec_mst();

    printf("%llu %llu\n", res1, res2);
    return 0;
}
