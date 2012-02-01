/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : carnival.c

* Purpose : 3rd exercise in Algorithms

* Creation Date : 18-01-2012

* Last Modified : Wed Feb  1 23:50:09 2012

* Created By : Vasilis Gerakaris <vgerak@gmail.com>

_._._._._._._._._._._._._._._._._._._._._.*/


#include<stdio.h>
#include<stdlib.h>

static int k, v, e, s, t;
int **M;

int main()
{
    int i, j, a, b;
    long long int res;

    /* Read graph info and data from input, allocate memory */
    scanf("%d %d %d %d %d", &k, &v, &e, &s, &t);
    M = (int **) calloc(v, sizeof(int *));      //1 extra row/column to have exact numbers.
    for (i = 0; i <= v; ++i)
        M[i]= (int *) calloc(v, sizeof(int));
    for (i = 0; i < e; ++i)
    {
        scanf("%d %d", &a, &b);
        M[a - 1][b - 1] = 1;
    }
    ///* Input reading check
    for (i = 0; i < v; ++i)
    {
        printf("Node %d leads to:\n", i + 1);
        for (j = 0; j < v; ++j)
        {
            if (M[i][j] == 1)
                printf("%d, ", j + 1);
        }
        printf("\n");
    }
    //*/


    //printf("%lld\n", res);
    return 0;
}
