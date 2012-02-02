/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

 * File Name : carnival.c

 * Purpose : 3rd exercise in Algorithms

 * Creation Date : 18-01-2012

 * Last Modified : Thu Feb  2 11:21:28 2012

 * Created By : Vasilis Gerakaris <vgerak@gmail.com>

 _._._._._._._._._._._._._._._._._._._._._.*/

#include <stdio.h>
#include <stdlib.h>

unsigned int V, E;  //Vertices and Edges are global

typedef struct node_t node_t;
typedef struct edge_t edge_t;

struct edge_t {
    node_t *n1;
    node_t *n2;
    unsigned int cost;
    unsigned int used;
};

struct node_t {
    node_t *parent;
    node_t *root;
    node_t *next;
    node_t *last;
};

node_t *nodes;
edge_t *edges;

unsigned int last_i;

void makenode(node_t *n1)
{
    (*n1).last = (*n1).parent = (*n1).root = n1;
    (*n1).next = NULL;
}

void unify(node_t *n1, node_t *n2)
{
    n1 = (*n1).root;
    n2 = (*n2).root;
    (*n2).root = n1;
    (*n2).parent = (*n1).last;
    (*(*n1).last).next = n2;
    while ((*n2).next != NULL)
    {
        n2 = (*n2).next;
        (*n2).root = n1;
    }
}

int findset(node_t *n1, node_t *n2)
{
    if ((*n1).root == (*n2).root){
        printf("same set");
        return 1;
    }
    else
    {
        printf("Different set");
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

unsigned int mst(unsigned int used_e)
{
    unsigned int i, cost, num;
    cost = 0;
    num = 0;
    for (i = 0; i < E; ++i)
    {
        //printf("i = %u\n", i);
        if (num < V - 1)
        {
            if (findset(edges[i].n1, edges[i].n2) == 0 && (i + 1) != used_e)
            {
                unify(edges[i].n1, edges[i].n2);
                if (used_e == 0)
                {
                    edges[i].used = 1;
                }
                cost += edges[i].cost;
                printf("  i= %u, weight %u\n", i, edges[i].cost);
                num++ ;
                last_i = i;
            }
        }
        else break;
    }
    //printf("cost = %u\n", cost);
    if (num < V - 1)
        return 0;
    return cost;
}

unsigned int sec_mst(unsigned int cost1, unsigned int j)
{
    unsigned int i, min, c, k, num;
    min = cost1;
    for (i = j + 1; i > 0; --i)
    {
        printf("  i' = %u\n", i);
        if (edges[i - 1].used == 1)
        {
            num = 0;
            for (k = 0; k < V ; ++k)
                makenode(&nodes[k]);
            c = mst(i);
            if (min == cost1 || min > c)
                min = c;
        }
    }
    return min;
}

int main()
{
    unsigned int i, j, k, res1, res2;
    scanf("%u %u\n", &V, &E);
    nodes = calloc(V, sizeof(node_t));
    edges = calloc(E, sizeof(edge_t));
    for (i = 0; i < E; ++i)
    {
        scanf("%u %u %u\n", &j, &k, &edges[i].cost);
        printf(" %u - %u : %u\n", j, k, edges[i].cost);
        edges[i].n1 = &nodes[j - 1];
        edges[i].n2 = &nodes[k - 1];
        makenode(edges[i].n1);
        makenode(edges[i].n2);
    }
    /*for (i = 0; i < V; ++i)
      {
      printf("Node %u connects with:\n", i + 1);
      for (j = 0; j < V; ++j)
      if (M[i][j] != 0)
      printf("   %u : weight %u\n", j + 1, M[i][j]);
      }
      */

    qsort(edges, E, sizeof(edge_t), compare);

    res1 = mst(0);
    printf("FOUND MST: %u\n", res1);
    res2 = sec_mst(res1, last_i);

    printf("%u %u\n", res1, res2);

    return 0;
}

