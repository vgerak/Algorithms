/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : vacation.c

* Purpose : 1st exercise on Algorithms

* Creation Date : 28-11-2011

* Last Modified : Sun Dec  4 10:51:56 2011

* Created By : Vasilis Gerakaris <vgerak@gmail.com>

_._._._._._._._._._._._._._._._._._._._._.*/
#include "vacation.h"


unsigned int n;
int ltemp;
int dayT[500000];

int main()
{
    unsigned int i, pivotL, pivotR, tempresult, days;
    double avg;

    scanf("%d %d", &n, &ltemp);
    for (i=0; i<n; i++)
    {
        //dayT[i] = rand();
        scanf("%d", &dayT[i]);
        printf("Temperature of day %d is %d \n",i,dayT[i]);
    }
    pivotL = pivotR = days = 0;     //initialization
    for (i=0; i<n-1; i++)
    {
        if (dayT[i] > ltemp)
        {
            if (days == 0 )
            {
                days = 1;
            }
            pivotL = pivotR = i;
            tempresult = dayfinder(pivotL, pivotR, avg, days);
            if (tempresult > days)
            {
                days = tempresult;
            }
        }
    }
return 0;
}


unsigned int dayfinder(unsigned int pivotL, unsigned int pivotR, double avg, unsigned int days)
{
    unsigned int maxstepL, maxstepR, tdays;
    double avgtemp;


    maxstepL = maxstepR = 0;    //initialization
    tdays = days;
    avgtemp = avg;

    if (maxstepL == 0)
    {
        return maxstepR;
    }
    else if (maxstepR == 0)
    {
        return maxstepL;
    }
    else
    {
        days++ ;
        if (maxstepR > maxstepL)
        {
            return 1 + dayfinder(pivotL, pivotR + 1, avg, days);
        }
        else
        {
            return 1 + dayfinder(pivotL - 1, pivotR, avg, days);
        }
    }
}
