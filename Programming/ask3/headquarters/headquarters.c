/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : carnival.c

* Purpose : 3rd exercise in Algorithms

* Creation Date : 18-01-2012

* Last Modified : Thu Feb  2 17:16:22 2012

* Created By : Vasilis Gerakaris <vgerak@gmail.com>

_._._._._._._._._._._._._._._._._._._._._.*/


#include<stdio.h>
#include<stdlib.h>

static unsigned int k, V, E, s, t;
unsigned int **Curr;
unsigned int **Prev;
unsigned int **temp;
unsigned int **M;


unsigned int **M_mult (**A)
{


}

int main()
{
    unsigned int i, j, a, b;
    long long int res;

    /* Read graph info and data from input, allocate memory */
    scanf("%u %u %u %u %u", &k, &V, &E, &s, &t);
    M = (unsigned int **) calloc(V, sizeof(unsigned int *));
    for (i = 0; i <= V; ++i)
        M[i]= (unsigned int *) calloc(V, sizeof(unsigned int));
    for (i = 0; i < e; ++i)
    {
        scanf("%u %u", &a, &b);
        M[a - 1][b - 1] = 1;
    }
    ///* Input reading check
    for (i = 0; i < v; ++i)
    {
        printf("Node %u leads to:\n", i + 1);
        for (j = 0; j < v; ++j)
        {
            if (M[i][j] == 1)
                printf("%u, ", j + 1);
        }
        printf("\n");
    }
    //*/

    printf("%lld\n", Curr[s - 1][t - 1]);
    return 0;
}
