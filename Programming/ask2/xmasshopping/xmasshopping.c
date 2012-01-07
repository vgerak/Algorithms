/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

 * File Name : xmasshopping.c

 * Purpose : 2nd exercise in Algorithms

 * Creation Date : 20-12-2011

 * Last Modified : Thu Jan  5 05:01:56 2012

 * Created By : Vasilis Gerakaris <vgerak@gmail.com>

 _._._._._._._._._._._._._._._._._._._._._.*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct shp{
    int x;
    int y;
};
typedef struct shp shops_s;
shops_s *shop, *locA, *locB;

unsigned int N, distA, distB, R, C;

int M_D(shops_s A, shops_s B);     //The Manhattan distance

int main()
{
    int i,j;

    distA = distB = 0;
    scanf("%d", &N);
    shop = (shops_s *) calloc(N,sizeof(shops_s));
    locA = (shops_s *) malloc(sizeof(int));
    locB = (shops_s *) malloc(sizeof(int));
    if ((shop == NULL) || (locA == NULL) || (locB == NULL))
    {
        printf("Out of memory\n");
        return -1;
    }
    /* Read starting and shop locations */
    scanf("%d %d", &locA->x, &locA->y);
    scanf("%d %d", &locB->x, &locB->y);

    for (i = 0; i < N; i++)
    {
        scanf("%d %d",&shop[i].x, &shop[i].y);
        printf("shop # %d has X=%d, Y=%d\n",i, shop[i].x, shop[i].y);
    }
    ///*
    for (i = 1; i < N; i++)
        printf("M_D of %d, %d is --  %d\n",i, i + 1, M_D(shop[i-1], shop[i]));



    return 0;
}

int M_D(shops_s A, shops_s B)
{
    int k;
    k = abs(A.x - B.x) + abs(A.y - B.y);
    return k;
}

