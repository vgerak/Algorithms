/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

 * File Name : vacation.c

 * Purpose : 1st exercise on Algorithms

 * Creation Date : 28-11-2011

 * Last Modified : Tue Dec  6 17:52:24 2011

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
    int i,n, avg, merge,sum;
    list *root;
    list *ptr;
    list *tmp;

    scanf("%d %d",&n, &avg);
    printf("%d Days to calculate \n", n);
    root = malloc(sizeof(list));
    root-> next = 0;
    root-> steps = 1;
    scanf("%d", &root->val);
    ptr = root;
    //printf("Temperature of day 0 is %d \n",ptr->val);


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
        ptr-> val -= avg;
        //printf("Temperature of day %d is %d \n",i,ptr->val);
    }

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
                sum = 0;
                tmp = ptr;
                ptr = ptr-> next;
                while (ptr->val <=0)
                {
                    sum = sum + ptr-> val;
                    ptr = ptr-> next;
                }
                if ((tmp-> val >= sum) && (ptr-> val >= sum))
                {
                    //MERGE
                    merge = 1;
                    tmp-> val = tmp-> val + ptr-> val + sum;
                    //remember to free
                    tmp-> next = ptr-> next;
                    ptr = tmp;
                }
            }
        }
    }


    return 0;
}
