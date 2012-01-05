/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

 * File Name : teleport.c

 * Purpose : 2nd exercise in Algorithms

 * Creation Date : 20-12-2011

 * Last Modified : Thu Jan  5 22:54:27 2012

 * Created By : Vasilis Gerakaris <vgerak@gmail.com>

 _._._._._._._._._._._._._._._._._._._._._.*/

#include<stdio.h>
#include<stdlib.h>

int N, r, l;

struct tps{
    long int start;
    long int end;
    int out;        //Don't know if it's gonna be used yet, rules out scientist if set
};
typedef struct tps tlist;

long int a,b;
tlist *right;
tlist *left;
int i,j;

/* Auxiliary functions for quicksort */
int compareR(const tlist *A, const tlist *B)
{
    if(A->start != B->start)
        return( A->start - B->start);
    else
        return( A->end - B->end);
}
int compareL(const tlist *A, const tlist *B)
{
    if(A->end != B->end)
        return( A->end - B->end);
    else
        return (A->start - B->start);
}



int main()
{

    int i,j;
    r = l = 0;
    scanf("%d", &N);

    left = (tlist *) calloc(N,sizeof(tlist));
    right = (tlist *) calloc(N,sizeof(tlist));
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
            right[r].start = a;
            right[r].end = b;
            //printf("Right # %d starts on %ld and ends on %ld \n", r, right[r].start, right[r].end);
            r++;
        }
        else
        {
            left[l].start = a;
            left[l].end = b;
            //printf("Left # %d starts on %ld and ends on %ld \n", l, left[l].start, left[l].end);
            l++;
        }
    }
    r--;
    l--;

    qsort(right,r,sizeof(tlist),compareR);
    qsort(left,l,sizeof(tlist),compareL);

    /* Sort Testing
    for(i = 0; i < r; i++)
        printf("Right # %d starts on %ld and ends on %ld \n", r, right[i].start, right[i].end);
    for(i = 0; i < l; i++)
        printf("Left # %d starts on %ld and ends on %ld \n", r, left[i].start, left[i].end);
    */

    return 0;
}

