/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

 * File Name : vacation.c

 * Purpose : 1st exercise on Algorithms

 * Creation Date : 28-11-2011

 * Last Modified : Wed Dec 14 00:09:15 2011

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
    int i, j, piv, cleft, cright, result;
    int ltemp;

    scanf("%d %d", &n, &ltemp);

    T = calloc(n,sizeof(int));


    scanf("%d", &T[0]);
    T[0] -= ltemp;
    piv = T[0];

    left = calloc(n,sizeof(int));
    right = calloc(n,sizeof(int));
    if ((left == NULL) || (right == NULL))
    {
        printf( "Out of memory" );
        return -1;
    }

    cleft = 1;
    left[0] = 0;
    j = 1;
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
            left[j] = i;
            j++;
        }
    }

    //Create RIGHT list
    cright = 1;
    piv = T[n-1];
    right[0] = n-1;
    j = 1;
    for (i=(n-2); i>= 0; i--)
    {
        if (T[i] > piv)
        {
            cright++;
            piv = T[i];
            right[j] = i;
            j++;
        }
    }

    /*
    //testing list status
    for(j=0; j<cleft; j++)
    {
        printf("index %d has sum of %d \n", left[j], T[left[j]]);
    }
    printf("\n");
    //testing list status
    for(i=0; i<cright; i++)
    {
        printf("index %d has sum of %d \n", right[i], T[right[i]]);
    }
    */

    result = 0;
    j = (cleft-1);
    for (i=0; i<cright; i++)
    {
        if (T[right[i]]>=0)
        {
            if (right[i]>=result)
            {
                result = right[i] + 1;
            }
        }
        while (j>=0)
        {
            if (T[right[i]] - T[left[j]] >= 0)
            {
                if ((right[i] - left[j]) > result)
                {
                    result = right[i] - left[j];
                }
            }
            else
            {
                break;
            }
            j--;
        }
    }

    printf("%d\n",result);
    return 0;
}
