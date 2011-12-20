#include <stdio.h>
#include <stdlib.h>

/********DHLWSEIS************/

int binsearch(int, int);
int is_solution(int);
int *pages;
int n,k;

int main()
{
	int i, result, lower_bound, upper_bound;

	//DIABASMA
	scanf("%d %d\n", &n, &k); //n biblia, k antigrafeis
	pages = calloc(n, sizeof(int));
	for(i=0; i<n ; i++)
	{
		scanf("%d\n", &pages[i]);
	}


	//upologizw lower kai upper bound

	int maxi = 0; //maxi 8a einai o megistos ari8mos selidwn bibliou
	int sum_pages = 0;
	int avg= 0 ; //what einai to a8roisma sunolikwn selidwn dia tous k grafeis.


	for(i=0; i<n ; i++)
	{
		sum_pages = sum_pages + pages[i];
		if ( pages[i] > maxi )
		{
			maxi = pages[i];
		};
	}

	avg = sum_pages / k;

	if ( maxi > avg)
	{
		lower_bound = maxi ;
	}
	else
	{
		lower_bound = avg ;
	}
	upper_bound = sum_pages;

        if (n < k)
        {
            printf("%d\n",lower_bound);
            return 0;
        }
        else
        {
            //anadromika, binary search sto diasthma [lower_bound , upper_bound]
            {
                result = binsearch(lower_bound, upper_bound);
            }
            printf("%d\n",result);
        }
        return 0;
}

int binsearch(int lbound, int hbound)
{
    int mid, s;
    if (lbound == hbound)
        return hbound;
    else
    {
        mid = ((lbound + hbound)/2);
        s = is_solution(mid);
        if (s == 0)
        {
            return binsearch(lbound,mid);
        }
        else
        {
            return binsearch(mid+1, hbound);
        }
    }
}

int is_solution (int given_num)
{
	int assigned, counter;
	int j;

        assigned = 0;
        counter = 1;
	j=0;
        while (j < n)
        {
            assigned = assigned + pages[j];
            if (assigned > given_num)
            {
                assigned = 0;
                j --;
                counter ++;
            }
            j ++;
        }
        if (counter <= k)
            return 0;
        else
            return 1;
}
