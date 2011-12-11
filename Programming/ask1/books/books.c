/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

 * File Name : books.c

 * Purpose : 1st exercise on Algorithms

 * Creation Date : 28-11-2011

 * Last Modified : Sun Dec 11 21:14:20 2011

 * Created By : Vasilis Gerakaris <vgerak@gmail.com>

 _._._._._._._._._._._._._._._._._._._._._.*/
//#include "books.h"
#include <stdio.h>

int A[100000];
int scribes, books;

int main()
{
    int i;
    int sum,min1,min2,result;


    scanf("%d %d", &books, &scribes);
    sum = 0;
    min2 = 0;
    for (i=0; i<books; i++)
    {
        scanf("%d", &A[i]);
        sum = sum + A[i];
        if (A[i] > min2)
        {
            min2 = A[i];
        }
    }
    min1 = sum / books;

    //Upper bound is sum of pages
    //
    //Lower bound is the largest of:
    // -- the sum of pages divided by # of scribes
    // -- the most pages found in a single book
    if (min1 < min2)
    {
        min1 = min2;
    }

    //Perform binary search on possible number of pages
    if (books < scribes)
    {
        printf("%d", min2);
        return 1;
    }
    result = binsearch(min1,sum);

    printf("%d \n",result);

    return 0;
}


int binsearch(int min,int max)
{
    int result, sum, avg, count, i;

    result = max;

    if (max != min)
    {
        avg= ((max + min)/2);
        //printf("max is %d, min is %d\n", max, min);
        //printf("Searching for %d solution\n", avg);
        count = 1;
        sum = 0;
        result = 0;
        for(i=0; i< books; i++)
        {
            sum = sum + A[i];
            if (sum > avg)
            {
                if ((sum-A[i]) > result)
                {
                    result = (sum- A[i]);
                }
                sum = 0;
                i --;
                count ++;
            }
        }
        //printf("count =  %d, result = %d\n", count, result);

        //if (count > scribes), # of pages is
        //between avg and max
        if (count > scribes)
        {
            result = binsearch (avg+1, max);
        }
        //if (count < scribes), # of pages is
        //between min and avg
        else //if (count < scribes)
        {
            result = binsearch(min, avg);
        }
        //if count = scribes, result is the biggest
        //sum of pages for a single scribe
    }


    return result;
}
