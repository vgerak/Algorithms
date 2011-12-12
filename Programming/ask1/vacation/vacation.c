/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

 * File Name : vacation.c

 * Purpose : 1st exercise on Algorithms

 * Creation Date : 28-11-2011

 * Last Modified : Mon Dec 12 15:13:41 2011

 * Created By : Vasilis Gerakaris <vgerak@gmail.com>

 _._._._._._._._._._._._._._._._._._._._._.*/
#include <stdio.h>
#include <stdlib.h>

int n;
int *T;
int *left;
int *right;


int main()
{
    int i, j, k, piv, cleft, cright, result;
    int ltemp;

    scanf("%d %d", &n, &ltemp);

    T = calloc(n,sizeof(int));


    scanf("%d", &T[0]);
    T[0] -= ltemp;
    piv = T[0];

    left = calloc(n*2,sizeof(int));
    right = calloc(n*2,sizeof(int));
    if ((left == NULL) || (right == NULL))
    {
        printf( "Out of memory" );
        return -1;
    }

    cleft = 1;
    left[0] = T[0];
    left[1] = 0;
    k = 1;
    for (i=1; i<n; i++)
    {
        scanf("%d", &T[i]);
        T[i] -= ltemp;
        T[i] = T[i] + T[i-1];  //Create prefix sums

        //Create LEFT list while reading
        //from input, to save a scan
        if (T[i] < piv)
        {
            cleft++;
            piv = T[i];
            left[2*k] = T[i];
            left[2*k +1] = i;
            k++;
        }
    }

    //Create RIGHT list
    cright = 1;
    piv = T[n-1];
    right[0] = T[n-1];
    right[1] = n-1;
    k = 1;
    for (i=(n-2); i>= 0; i--)
    {
        if (T[i] > piv)
        {
            cright++;
            piv = T[i];
            right[2*k] = T[i];
            right[2*k +1] = i;
            k++;
        }
    }

    /*
    //testing list status
    for(i=0; i<cleft; i++)
    {
        printf("index %d has sum of %d \n", left[2*i+1], left[2*i]);
    }
    printf("\n");
    //testing list status
    for(i=0; i<cright; i++)
    {
        printf("index %d has sum of %d \n", right[2*i+1], right[2*i]);
    }
    */
    result = 0;
    for (i=0; i<cleft; i++)
    {
        for (j=(cright-1); j>=0; j--)
        {
            if (right[2*j] - left[2*i] > 0)
            {
                if (right[2*j+1] - left[2*i+1] > result)
                {

                }
            }
        }
    }


    return 0;
}
