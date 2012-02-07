/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

 * File Name : carnival.c

 * Purpose : 3rd exercise in Algorithms

 * Creation Date : 18-01-2012

 * Last Modified : Fri Feb  3 04:43:09 2012

 * Created By : Vasilis Gerakaris <vgerak@gmail.com>

 _._._._._._._._._._._._._._._._._._._._._.*/

#include<stdio.h>
#include<stdlib.h>
#define LIMIT 100000007

/* Global variable Declaration */
static unsigned int k, V, E;
unsigned long long int **M;

void M_mult (unsigned long long int **a, unsigned long long int **b, unsigned long long int **c)
{
    unsigned int i, j, k;
    unsigned long long int sum;
    for (i = 0; i < V; ++i)
    {
        for (j = 0; j < V; ++j)
        {
            sum = 0;
            for(k = 0; k < V; ++k)
            {
                sum += a[i][k] * b[k][j];
            }
            c[i][j] = sum % LIMIT;
        }
    }
}

int main()
{
    unsigned int i, j, a, b, u;
    static unsigned int s, t;       //Start and End node
    long long int res;
    unsigned long long int **A;
    unsigned long long int **B;
    unsigned long long int **temp;  //used for swaps
    int flag;        //binary representation of k-1
    /* Read graph info and data from input, allocate memory */
    scanf("%u %u %u %u %u", &k, &V, &E, &s, &t);
    k --;
    M = (unsigned long long int **) calloc(V, sizeof(unsigned long long int *));
    A = (unsigned long long int **) calloc(V, sizeof(unsigned long long int *));
    B = (unsigned long long int **) calloc(V, sizeof(unsigned long long int *));
    for (i = 0; i < V; ++i)
    {
        M[i]= (unsigned long long int *) calloc(V, sizeof(unsigned long long int));
        A[i]= (unsigned long long int *) calloc(V, sizeof(unsigned long long int));
        B[i]= (unsigned long long int *) calloc(V, sizeof(unsigned long long int));
        B[i][i] = 1;
    }
    for (i = 0; i < E; ++i)
    {
        scanf("%u %u", &a, &b);
        M[a - 1][b - 1] = 1;
    }
    for (i = 0, j = 0; i < 32; ++i)
    {
        flag = ( k & ( 1 << i ) ) >> i;
        if (flag == 1)
        {
            for (; j < i; ++j)
            {
                M_mult(M, M, A);
                temp = A;
                A = M;
                M = temp;
            }
            M_mult(B, M, A);
            temp = A;
            A = B;
            B = temp;
        }
    }
    printf("%llu\n", B[s - 1][t - 1]);
    return 0;
}
