/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

 * File Name : teleport.c

 * Purpose : 2nd exercise in Algorithms

 * Creation Date : 20-12-2011

 * Last Modified : Sat Jan  7 04:08:29 2012

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

long int *ends, *newends;
int *x;
int *temp;
tlist *move;

/* Auxiliary functions for quicksort & bsearch */
int compareA(const void *AA, const void *BB)
{
    tlist *A = (tlist *) AA;
    tlist *B = (tlist *) BB;
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

/*
 * == Longest Non-Decreasing Subsequence v1==
 * Running, but O(n^2), will try for nlogk
 *

int lis(int* a, int N)
{
    int *best, *prev, i, j, max = 0;
    best = (int*) malloc ( sizeof( int ) * N );
    prev = (int*) malloc ( sizeof( int ) * N );

    for (i = 0; i < N; i++)
    {
	best[i] = 1;
	prev[i] = i;
    }

    for (i = 1; i < N; i++)
    {
	for (j = 0; j < i; j++)
	{
	    if (a[i] >= a[j] && best[i] < best[j] + 1)
	    {
		best[i] = best[j] + 1;
		prev[i] = j;
	    }
	}
    }
    for (i = 0; i < N; i++)
	if (max < best[i])
	    max = best[i];

    free( best );
    free( prev );

    return max;
}
*/

/* Custom binary search */
int binary_search(int *A, int val, int len)
{
    int min, max, mid;
    min = 0;
    max = len-1;
    mid = (min+max)/2;
    while (min < max-1)
    {
	if (val >= A[mid])
	    min = mid;
	else
	    max = mid;
	mid = (min+max)/2;
    }

    if (A[min] > val)
	return min;
    else if (A[max] > val)
	return max;
    else
	return -1;
}

/*
 * == Longest Non-Decreasing Subsequence v2==
 * Returns the length of the longest increasing subsequence.
 */
int lis(int*a, int len)
{
    int k,l,max, *M,res;
    M = (int*) calloc(len, sizeof(int));
    l = 0;
    for (k = 0; k < len; k++)
    {
	res = binary_search(M, a[k], l);
	//printf("res = %d, a[k] = %d\n",res, a[k]);
	if (res != -1)
	    M[res] = a[k];
	else
	{
	    M[l] = a[k];
	    l++;
	}
    }
    return l;
}



int main()
{
    long int a,b;
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
    for (i = 0; i < N; i++)
    {
	temp = (int*) bsearch(&move[i].end, newends, ec, sizeof(long int), compareB);
	x[i] = ((int*) temp - (int*) newends)/2 +1; //div 2 to make it look pretty!
	//printf("X[%d] = %d\n", i, x[i]);
    }
    /*
     * Now the problem is reduced in finding the longest NON-REDUCING
     * subsequence of X[].
     * We use a modified version of a well-known algorithm and we're done.
     */
    printf("%d\n",lis(x,N));

    return 0;
}
