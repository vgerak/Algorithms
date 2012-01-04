/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

 * File Name : teleport.c

 * Purpose : 2nd exercise in Algorithms

 * Creation Date : 20-12-2011

 * Last Modified : Wed Jan  4 18:42:58 2012

 * Created By : Vasilis Gerakaris <vgerak@gmail.com>

 _._._._._._._._._._._._._._._._._._._._._.*/

#include<stdio.h>
#include<stdlib.h>

int N, r, l;

long int a,b;
long int **left;
long int **right;
int i,j;

int main()
{
    r = l = 0;
    scanf("%d", &N);

    /*
     * Create the 2-D arrays:
     * [0] marks startpoint
     * [1] marks endpoint
     */
    left = (long int **) calloc(2, sizeof(long));
    right = (long int **) calloc(2, sizeof(long));
    for (i = 0; i < 2; i++)
    {
        right[i] = (long *) calloc(N, sizeof(long));
        left[i] = (long *) calloc(N, sizeof(long));
    }
    if ((left == NULL) || (right == NULL))
    {
        printf("Out of memory\n");
        return -1;
    }

    for (i = 1; i < N; i++)
    {
        /* Read from input and sort to lefts and rights */
        scanf("%ld %ld", &a, &b);
        if (a < b)
        {
            right[0][r] = a;
            right[1][r] = b;
            //printf("Right # %d starts on %ld and ends on %ld \n", r, right[0][r], right[1][r]);
            r++;
        }
        else
        {
            left[0][l] = a;
            left[1][l] = b;
            //printf("Left # %d starts on %ld and ends on %ld \n", l, left[0][l], left[1][l]);
            l++;
        }
    }


    return 0;
}

