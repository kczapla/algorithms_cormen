/*
 * =====================================================================================
 *
 *       Filename:  merge_sort.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  27.05.2015 10:50:53
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
   

void display(int tab[], int size);
void merge(int tab[], int p, int q, int r);
void merge_sort(int tab[], int p, int r);

int main() 
{
    int tab[8] = {8, 7, 6, 5, 4, 3, 2, 1};
    display(tab, sizeof(tab)/4);
    //merge(tab, 0, 3, 7);
    merge_sort(tab, 0, 7);
    display(tab, sizeof(tab)/4);
    return 0;

}


void display(int tab[], int size)
{
    for (int i = 0; i < size; i++)
    {
            printf("%d, ", tab[i]);
    }
    printf("\n");
}


void merge(int tab[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1 + 1];
    int R[n2 + 1];

    for (int i = 0; i < n1; i++)
    {
            L[i] = tab[p + i];
    }

    for (int i = 0; i < n2; i++)
    {
            R[i] = tab[q + i + 1];
    }

    L[n1] = 9999999;
    R[n2] = 9999999;

    //display(L, sizeof(L)/4);
    //display(R, sizeof(R)/4);

    int cl = 0;
    int rl = 0;

    for (int i = p; i < r + 1; i++)
    {
            if (L[cl] <= R[rl])
            {
                    tab[i] = L[cl];
                    cl++;
            }
            else
            {
                    tab[i] = R[rl];
                    rl++;
            }
    }

}


void merge_sort(int tab[], int p, int r)
{
        if (p < r)
        {
                int q = (p + r)/2;
                merge_sort(tab, p, q);
                merge_sort(tab, q + 1, r);
                merge(tab, p, q, r);
        }
}
