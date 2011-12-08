/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

 * File Name : vacation.c

 * Purpose : 1st exercise on Algorithms

 * Creation Date : 28-11-2011

 * Last Modified : Thu Dec  8 05:39:15 2011

 * Created By : Vasilis Gerakaris <vgerak@gmail.com>

 _._._._._._._._._._._._._._._._._._._._._.*/
#include "vacation.h"

struct lst{
    int val;
    int steps;
    struct lst *next;
};

typedef struct lst list;

int main()
{
    int i,n, avg, merge,sumL,sumR max;
    list *root;
    list *ptr;
    list *tmp;

    scanf("%d %d",&n, &avg);
    printf("%d Days to calculate \n", n);
    root = malloc(sizeof(list));
    root-> next = 0;
    root-> steps = 1;
    scanf("%d", &root-> val);
    root-> val -= avg;
    ptr = root;
    //printf("Temperature of day 0 is %d \n",ptr->val);

    //Read from stdin, initialize list
    for (i=1; i<n; i++)
    {
        ptr->next = malloc(sizeof(list));
        ptr = ptr-> next;
        if (ptr == 0)
        {
            printf( "Out of memory" );
            return -1;
        }
        ptr-> next = 0;
        ptr-> steps = 1;
        scanf("%d", &ptr-> val);
        //Subtract avg from every element to work around 0
        ptr-> val -= avg;
        //printf("Temperature of day %d is %d \n",i,ptr->val);
    }

    //Step 1: Merge positive elements with small accumulated value of negatives between them
    //in order to decrease the search candidates for Step 2 and the size of the list
    merge = 1;
    while (merge = 1)
    {
        ptr = root;
        merge = 0;
        while (ptr-> next != 0)
        {
            if (ptr-> val <= 0)
            {
                ptr = ptr-> next;
            }
            else
            {
                sumL = 0;
                tmp = ptr;
                ptr = ptr-> next;
                while (ptr->val <=0)
                {
                    sumL = sumL + ptr-> val;
                    ptr = ptr-> next;
                }
                if ((tmp-> val >= sumL) && (ptr-> val >= sumL))
                {
                    //Merge
                    merge = 1;
                    tmp-> val = tmp-> val + ptr-> val + sumL;
                    //remember to free
                    tmp-> next = ptr-> next;
                    ptr = tmp;
                }
            }
        }
    }

    //Step 2: Search around the remaining positives to find maximum number of days
    ptr = root;
    max = 0;
    while (ptr-> next != 0)
    {
        if (ptr-> val >= 0)
        {
            //search
        }
        if (ptr-> val > max)
        {
            max = ptr-> val;
        }
        ptr = ptr-> next;
    }


    printf("%d" , max);
    return 0;
}
