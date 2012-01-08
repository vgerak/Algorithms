/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

 * File Name : xmasshopping.c

 * Purpose : 2nd exercise in Algorithms

 * Creation Date : 20-12-2011

 * Last Modified : Sun Jan  8 18:56:42 2012

 * Created By : Vasilis Gerakaris <vgerak@gmail.com>

 _._._._._._._._._._._._._._._._._._._._._.*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int M_D(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}

int main()
{
    int i, j, k;
    int cA, cB;
    static int N, R, C;
    int *x;	    // -arrays to keep
    int *y;	    //coords of shops (startB = x,y[0])
    int xA, yA;    // -coords of A
    int **DA_1,**DA_2;
    int **buf;

    /* Read 2 lines from input and allocate memory */
    scanf("%d %d %d", &N, &R, &C);
    scanf("%d %d", &xA, &yA);
    x = (int *) calloc(N + 1, sizeof(int));
    y = (int *) calloc(N + 1, sizeof(int));
    DA_1 = (int **) calloc(R + 1, sizeof(int *));
    DA_2 = (int **) calloc(R + 1, sizeof(int *));

    /* Read shop list */
    for (i = 0; i <= N; i++)	// '<=' since we read B initial position aswell
    {
        scanf("%d %d",&x[i],&y[i]);
        //printf("shop # %d has X=%u, Y=%u\n",i, x[i], y[i]);
    }
    for (j = 0; j <= R; j++)
    {
        DA_1[j] = (int *) calloc(C + 1, sizeof(int));
        DA_2[j] = (int *) calloc(C + 1, sizeof(int));
    }

    /* Recursion begins */
    for (i = N - 1; i >= 0; i--)
    {
        for (j = R; j > 0; j--)
        {
            for (k = 1; k <= C; k++)
            {
                cA = M_D(x[i], y[i], x[i+1], y[i+1]) + DA_2[j][k];
                cB = M_D(j, k, x[i+1], y[i+1]) + DA_2[x[i]][y[i]];
                if (cA < cB)
                    DA_1[j][k] = cA;
                else
                    DA_1[j][k] = cB;
                //printf("DA[%d][%d][%d] = %d\n", i, j, k, DA[i][j][k]);
            }
        }
        //this swaps the two layers
        buf=DA_2;
        DA_2=DA_1;
        DA_1=buf;
    }
    printf("%d\n",DA_2[xA][yA]);
    return 0;
}
