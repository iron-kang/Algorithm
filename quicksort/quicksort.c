#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quickSort(int *a, int len)
{
    if (len == 0) return;
    int id = rand()%len;
    int pivot = a[id];
    int grp_1[len/2], grp_2[len/2];
    int id_1, id_2, i;

    id_1 = 0;
    id_2 = 0;

    if (len == 1) return;

    for (i = 0; i < len; i++)
    {
        if (i == id) continue;
        if (a[i] < pivot) grp_1[id_1++] = a[i];
        else grp_2[id_2++] = a[i];
    }
#ifdef DEBUG
    printf("pivot: %d(%d)\n", pivot, len);
    for (i = 0; i < id_1; i++)
        printf("%d ", grp_1[i]);
    printf("\n");
    for (i = 0; i < id_2; i++)
        printf("%d ", grp_2[i]);
    printf("\n gp1: %d gp2: %d\n", id_1, id_2);
#endif
    quickSort(grp_1, id_1);
    quickSort(grp_2, id_2);

    id = 0;
    for (i = 0; i < id_1; i++)
        a[id++] = grp_1[i];
    a[id++] = pivot;
    for (i = 0; i < id_2; i++)
        a[id++] = grp_2[i];

    //printf("=========\n");
}

int main(void)
{
    srand(time(NULL));
    const int size = 10;
    int a[] = {3,5, 8, 1, 2, 9, 4, 7, 6, 6};
    int b[4] = {11, 7,6,8};

    quickSort(a, size);
    for (int i = 0; i < size; i++)
        printf("%d ", a[i]);    
    printf("\n");
    return 0;
}

