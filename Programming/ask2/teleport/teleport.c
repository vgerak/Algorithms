/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

 * File Name : teleport.c

 * Purpose : 2nd exercise in Algorithms

 * Creation Date : 20-12-2011

 * Last Modified : Sat Jan  7 00:47:56 2012

 * Created By : Vasilis Gerakaris <vgerak@gmail.com>

 _._._._._._._._._._._._._._._._._._._._._.*/

#include<stdio.h>
#include<stdlib.h>

int N, ec;

struct tps{
    long int start;
    long int end;
};
typedef struct tps tlist;

long int a,b;
long int *ends, *newends;
int *x;
int * memstart, *temp;
tlist *move;

/* Auxiliary functions for quicksort & bsearch */
int compareA(const tlist *A, const tlist *B)
{
    if(A->start != B->start)
        return( A->start - B->start);
    else
        return( A->end - B->end);
}

int compareB(const void *A, const void *B)
{
    return (*(long int*)A - *(long int*)B);
}

/* ================================= */


int main()
{

    int i,j;
    scanf("%d", &N);
    move = (tlist *) calloc(N,sizeof(tlist));
    ends = (long int*) calloc(N,sizeof(long int));
    newends = (long int*) calloc(N,sizeof(long int));
    x = (int*) calloc(N,sizeof(int));
    if (move == NULL || (ends == NULL || (newends == NULL) || (x == NULL)))
    {
        printf("Out of memory\n");
        return -1;
    }

    for (i = 0; i < N; i++)
    {
        /* Read from input and sort to lefts and rights */
	scanf("%ld %ld", &a, &b);
	move[i].start = a;
	move[i].end = b;
	ends[i] = b;
	//printf("Port # %d starts on %ld and ends on %ld \n", i, move[i].start, move[i].end);
    }
    qsort(move,N,sizeof(tlist),compareA);
    qsort(ends,N,sizeof(long int), compareB);
    /* Create newends array with sorted and unique values */
    newends[0] = ends[0];
    ec = 0;
    for (i = 1; i < N; i++)
    {
	if(ends[i] != newends[ec])
	{
	    ec++;
	    newends[ec] = ends[i];
	}
    }
    ec++;
    /* Sort Testing
    for(i = 0; i < N; i++)
	printf("Move # %d starts on %ld and ends on %ld \n", i, move[i].start, move[i].end);
    for(i = 0; i < ec; i++)
	printf("Ending # %d is %ld \n", i, newends[i]);
    */

    /*
     * x[i] stores the index on newends array from the target of i
     * newends is sorted, so binsearch for the win!
     */
    memstart = (int*) bsearch(&newends[0], newends, ec, sizeof(long int), compareB);
    for (i = 0; i < N; i++)
    {
	temp = (int*) bsearch(&move[i].end, newends, ec, sizeof(long int), compareB);
	x[i] = (int*) temp - (int*) memstart;
	printf("X[%d] = %d\n", i, x[i]);
    }

    return 0;
}
