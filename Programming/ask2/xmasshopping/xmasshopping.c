/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

 * File Name : xmasshopping.c

 * Purpose : 2nd exercise in Algorithms

 * Creation Date : 20-12-2011

 * Last Modified : Mon Jan  9 13:34:06 2012

 * Created By : Vasilis Gerakaris <vgerak@gmail.com>

 _._._._._._._._._._._._._._._._._._._._._.*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/* Manhattan Distance */
inline
int M_D(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}

int main()
{
    int i, j, k;
    int cA, cB;
    static int N, R, C;
    int *x;	    // - arrays to keep coords
    int *y;	    //of shops (startB = x,y[0])
    int xA, yA;     // - startA
    int **Curr;	    // - 2D arrray with values to be modified (write)
    int **Prev;	    // - 2D with values to be used in calculations (read)
    int **temp;	    // - used for swap Curr <-> Prev

    /* Read 2 lines from input and allocate memory */
    scanf("%d %d %d", &N, &R, &C);
    scanf("%d %d", &xA, &yA);
    x = (int *) calloc(N + 1, sizeof(int));
    y = (int *) calloc(N + 1, sizeof(int));
    Curr = (int **) calloc(R + 1, sizeof(int *));
    Prev = (int **) calloc(R + 1, sizeof(int *));

    /* Read shop list */
    for (i = 0; i <= N; i++)	// '<=' since we read B initial position aswell
    {
        scanf("%d %d",&x[i],&y[i]);
    }
    for (j = 0; j <= R; j++)
    {
        Curr[j] = (int *) malloc((C + 1)*sizeof(int));
        Prev[j] = (int *) calloc(C + 1, sizeof(int));
    }

    /* Recursion begins */
    for (i = N - 1; i >= 0; i--)
    {
        for (j = R; j >= 1; j--)
        {
            for (k = 1; k <= C; k++)
            {
                cA = M_D(x[i], y[i], x[i+1], y[i+1]) + Prev[j][k];
                cB = M_D(j, k, x[i+1], y[i+1]) + Prev[x[i]][y[i]];
		/* Curr [j][k] = min (cA, cB) */
                if (cA < cB)
                    Curr[j][k] = cA;
                else
                    Curr[j][k] = cB;
            }
        }
        /* Swap the two arrays */
        temp=Prev;
        Prev=Curr;
        Curr=temp;
    }
    printf("%d\n",Prev[xA][yA]);    //Prev because of the last swap
    return 0;
}
