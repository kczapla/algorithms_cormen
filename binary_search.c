/*
 * =====================================================================================
 *
 *       Filename:  binary_search.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  30.05.2015 21:32:03
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>


int binary_search(int tab[], int p, int r, int v);
void binary_add(int tab[], int size, int v);

int main()
{
        int tab[16] = {1, 23, 26, 31, 37, 42, 44, 49, 56, 59, 64, 69, 75, 77, 88, 91};
        int size = sizeof(tab)/4;

        int x = binary_search(tab, 5, 10, 49);   

        binary_add(tab, size, 56);
}


int binary_search(int tab[], int p, int r, int v)
{
        if (p < r)
        {
                int q = (r + p)/2;
            
                if (v <= tab[q])
                {
                        binary_search(tab, p, q, v);
                }
                else if (v > tab[q])
                {
                        binary_search(tab, q+1, r, v);
                }
        }
        else if (tab[p] == v)
        {
                printf("Indeks %d\n", p);
                return p;
        }
        else
        {
                printf("W danym przedziale nie ma takiej wartosci... \n");
                return 999999;
        }
}


void binary_add(int tab[], int size, int v)
{
        int index = 0;

        for (int i = 0; i < size; i++)
        {
                int to_find = v - tab[i];
                index = binary_search(tab, 0, 15, to_find);

                if (index == 999999)
                {
                        printf("Not found \n");
                }       
                else 
                {
                        printf("Wartosci to %d i %d \n", tab[i], tab[index]);
                        break;
                }
        }
}
