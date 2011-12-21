/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

 * File Name : books.c

 * Purpose : 1st exercise on Algorithms

 * Creation Date : 28-11-2011

 * Last Modified : Tue Dec 20 14:31:46 2011

 * Created By : Vasilis Gerakaris <vgerak@gmail.com>

 _._._._._._._._._._._._._._._._._._._._._.*/

#include <stdio.h>
#include <stdlib.h>

int scribes, books;
int *A;
int binsearch(long long int, long long int);

int main()
{
    int i;
    int min2;
    long long int sum, result, min1;

    scanf("%d %d", &books, &scribes);
    A = calloc(books,sizeof(int));
    if (A == NULL)
    {
        printf("Not enough memory...\n");
        return -1;
    }
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
        printf("%d\n", min2);
        return 1;
    }
    result = binsearch(min1,sum);
    printf("%lld\n",result);
    return 0;
}

int binsearch(long long int min, long long int max)
{
    long long int result, sum, avg;
    int count, i;

    result = max;

    if (max != min)
    {
        avg= ((max + min)/2);
        count = 1;
        sum = 0;
        result = 0;
        for(i=0; i< books; i++)
        {
            sum = sum + A[i];
            if (sum > avg)
            {
                sum = 0;
                i --;
                count ++;
            }
        }
        //if (count > scribes), # of pages is
        //between avg and max
        if (count > scribes)
        {
            result = binsearch (avg+1, max);
        }
        //if (count < scribes), # of pages is
        //between min and avg
        else    //if (count <= scribes)
        {
            result = binsearch(min, avg);
        }
    }

    return result;
}
