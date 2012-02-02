/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

 * File Name : carnival.c

 * Purpose : 3rd exercise in Algorithms

 * Creation Date : 18-01-2012

 * Last Modified : Thu Feb  2 12:10:39 2012

 * Created By : Vasilis Gerakaris <vgerak@gmail.com>

 _._._._._._._._._._._._._._._._._._._._._.*/

#include <stdio.h>
#include <stdlib.h>

unsigned int V, E;  //Vertices and Edges are global
long unsigned int res1, res2;

typedef struct node_t node_t;
typedef struct edge_t edge_t;

struct edge_t {
    unsigned int n1;
    unsigned int n2;
    unsigned int cost;
    unsigned short int used;
};


unsigned int *nodes;
unsigned int *parent;
unsigned int **costs;
edge_t *edges;

unsigned int last_i;

void unify(int n1, int n2)
{
    parent[find(n1)] = n2;
}

int find(int n)
{
    if (n == parent[n])
        return n;
    else
        return parent[n] = find(parent[n]);
}

int findset(long unsigned int n1, long unsigned int n2)
{
    if (find(n1) == find(n2))
    {
        //printf("%lu, %lu -> same set\n", n1, n2);
        return 1;
    }
    else
    {
        //printf("%lu, %lu -> different set\n", n1, n2);
        return 0;
    }
}

int compare(const void *a, const void *b)
{
    if ((*(edge_t *) a).cost > (*(edge_t *) b).cost)
        return 1;
    else
        return -1;
}

long unsigned int mst(long unsigned int used_e)
{
    long unsigned int cost;
    unsigned int i, num;
    cost = 0;
    num = 0;
    for (i = 0; i < E; ++i)
    {
        //printf("i = %lu\n", i);
        if (num < V - 1)
        {
            if (findset(edges[i].n1, edges[i].n2) == 0 && (i + 1) != used_e)
            {
                unify(edges[i].n1, edges[i].n2);
                if (used_e == 0)
                {
                    edges[i].used = 1;
                }
                //printf("%lu %lu weight: +%lu\n", edges[i].n1, edges[i].n2, edges[i].cost);
                cost += edges[i].cost;
                num++ ;
                last_i = i;
            }
        }
        else break;
    }
    //printf("cost = %lu\n", cost);
    return cost;
}

long unsigned int sec_mst(long unsigned int cost1, long unsigned int j)
{
    long unsigned int min, c;
    unsigned int i, k;
    min = cost1;
    for (i = j + 1; i > 0; --i)
    {
        //printf("  i' = %lu\n", i);
        if (edges[i - 1].used == 1)
        {
            for (k = 0; k < V ; ++k)
            {
                //c = mst(i);
                if (min == cost1 || min > c)
                    min = c;
            }
        }
    }
    return min;
}

int main()
{
    unsigned int i, j, k;
    scanf("%u %u\n", &V, &E);
    parent = (unsigned int*) calloc(V + 1, sizeof(unsigned int));
    *costs = (unsigned int**) calloc(V + 1, sizeof(unsigned int *));
    for (i = 0; i <= V; ++i)
        *costs = (unsigned int*) calloc(V + 1, sizeof(unsigned int));
    edges = calloc(E, sizeof(edge_t));
    for (i = 0; i < E; ++i)
    {
        scanf("%u %u %u\n", &j, &k, &edges[i].cost);
        edges[i].n1 = j;
        edges[i].n2 = k;
    }
    for (i = 1; i <= V; ++i)
        parent[i] = i;

    qsort(edges, E, sizeof(edge_t), compare);

    res1 = mst(0);
    printf("FOUND MST: %lu\n", res1);
    res2 = sec_mst(res1, last_i);

    printf("%lu %lu\n", res1, res2);

    return 0;
}

