/*
 * =====================================================================================
 *
 *       Filename:  insertion_sort.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  30.05.2015 18:37:12
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
#include <binary_search.h>


void iteration(int tab[], int size);
void recursion(int tab[], int size);
void display(int tab[], int size);
void binary_iteration(int tab[], int size);


int main()
{
        printf("Helo World!\n");
        int tab[10] = {9,8,7,6,5,4,3,2,1,0};
        int size = sizeof(tab)/4;
        display(tab, size);
        //iteration(tab, size);
        recursion(tab, size);
        display(tab, size);
}


void display(int tab[], int size)
{
    for (int i = 0; i < size; i++)
    {
            printf("%d, ", tab[i]);
    }
    printf("\n");
}


void iteration(int tab[], int size)
{
        for (int i = 1; i < size; i++)
        {
                int key = tab[i];
                
                int j = i - 1;

                while ((j >= 0) && (tab[j] > key))
                {
                        tab[j+1] = tab[j];
                        tab[j] = key;

                        j--;
                }

        }
}


void binary_iteration(int tab[], int size)
{
        for (int i = 1; i < size; i++)
        {
                int key = tab[i];
                
                int j = i - 1;

                while ((j >= 0) && (tab[j] > key))
                {
                        tab[j+1] = tab[j];
                        tab[j] = key;

                        j--;
                }

        }
}


void recursion(int tab[], int size)
{
        
        if (size > 2)
        {
                recursion(tab, size-1);
        }
        
        //size is number of elements in array, 
        //i = size - 1 is a number of last index in array
        //j = i - 1 = size -2 is a number of last index of sorted elements in array tab
        int i = size - 1;
        int j = i - 1; 

        int key = tab[i];

        while ((j >= 0) && (tab[j] > key))
        {
                tab[j+1] = tab[j];
                tab[j] = key;

                j--;
        }
}
