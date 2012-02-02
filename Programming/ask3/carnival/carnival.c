/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

 * File Name : carnival.c

 * Purpose : 3rd exercise in Algorithms

 * Creation Date : 18-01-2012

 * Last Modified : Thu Feb  2 16:09:30 2012

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


//unsigned int *nodes;
unsigned int **parents;
edge_t *edges;

unsigned int last_i;

void unify(unsigned int n1, unsigned int n2, unsigned int c)
{
    unsigned int tempn = n1;
    parents[find(n1)][0] = n2;
    parents[n1][1] += c;
    while (parents[tempn][1] != 0)
    {
        parents[n1][1] += parents[tempn][1];
    }
    parents[n1][1] += c;
}

int find(int n)
{
    if (n == parents[n][0])
        return n;
    else
        return parents[n][0] = find(parents[n][0]);
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

long unsigned int mst()
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
            if (findset(edges[i].n1, edges[i].n2) == 0)
            {
                unify(edges[i].n1, edges[i].n2, edges[i].cost);
                if (parents[edges[i].n1][0] != edges[i].n1)
                    parents[edges[i].n1][2] = edges[i].n2;
                else
                    parents[edges[i].n2][2] = edges[i].n1;
                //printf("%u now has %u as father!\n", edges[i].n1 + 1, edges[i].n2 + 1);
                edges[i].used = 1;
                //printf(">>> ADDED EDGE %u\n", i);
                //printf("%u %u weight: %u\n", edges[i].n1 + 1, edges[i].n2 + 1, edges[i].cost);
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

unsigned int findmax(unsigned int e)
{
    unsigned int i;
    unsigned int max = 0;
    i = edges[e].n1;
    while (parents[i][1] != 0)
    {
        if (parents[i][1] > max)
            max = parents[i][1];
        i = parents[i][2];
    }
    i = edges[e].n2;
    while (parents[i][1] != 0)
    {
        if (parents[i][1] > max)
            max = parents[i][1];
        i = parents[i][2];
    }
    return max;
}

long unsigned int sec_mst()
{
    unsigned int min, test, i;
    min = findmax(0);
    for ( i = 0; i < E; ++i)
    {
        if (edges[i].used == 0)
        {
            test = findmax(i);
            if (test != 0)
                printf("res of edge %u is %u\n", i, test);
        }
        if ((test != 0) && (test < min))
            min = test;
    }
    return (res1 + min);
}

int main()
{
    unsigned int i, j, k;
    scanf("%u %u\n", &V, &E);
    parents = (unsigned int**) calloc(V, sizeof(unsigned int*));
    for (i = 0; i <= V; ++i)
    {
        parents[i] = (unsigned int*) calloc(3, sizeof(unsigned int));
    }
    edges = calloc(E, sizeof(edge_t));
    for (i = 0; i < E; ++i)
    {
        scanf("%u %u %u\n", &j, &k, &edges[i].cost);
        edges[i].n1 = j - 1;
        edges[i].n2 = k - 1;
    }
    for (i = 0; i < V; ++i)
        parents[i][0] = parents[i][2] = i;

    qsort(edges, E, sizeof(edge_t), compare);

    res1 = mst();
    printf("FOUND MST: %lu\n", res1);
    res2 = sec_mst();
    //for (i = 0; i < V; ++i)
        //printf("V %u: Father %u - Weight %u\n", i + 1, parents[i][2] + 1, parents[i][1]);

    printf("%lu %lu\n", res1, res2);

    return 0;
}

