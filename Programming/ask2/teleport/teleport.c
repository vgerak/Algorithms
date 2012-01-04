/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

 * File Name : teleport.c

 * Purpose : 2nd exercise in Algorithms

 * Creation Date : 20-12-2011

 * Last Modified : Wed Jan  4 19:30:00 2012

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

int main()
{
    r = l = 0;
    scanf("%d", &N);

    /*
     * Create the 2-D arrays:
     * [0] marks startpoint
     * [1] marks endpoint
     */
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
            right-> start = a;
            right-> end = b;
            printf("Right # %d starts on %ld and ends on %ld \n", r, right->start, right->end);
            r++;
        }
        else
        {
            left-> start = a;
            left-> end = b;
            printf("Left # %d starts on %ld and ends on %ld \n", l, left->start, left->end);
            l++;
        }
    }


    return 0;
}

