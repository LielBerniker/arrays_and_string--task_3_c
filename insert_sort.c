#include "insert_sort.h"
#include <stdio.h>

/*
the function move the values in the array , move all if the values to the right one time
move i number of values
*/
void shift_element(int* arr, int i)
{
    int temp1,temp2 ;
    temp1 = *(arr);
    for (int j = 1; j <=i; j++)
    {
        temp2 = *(arr+j);
        *(arr+j) = temp1;
        temp1 = temp2;
    }  
}

/*
the function is a sorting function to an array , sort by insert sort.
*/
void insertion_sort(int* arr , int len)
{
    int k=0,counter = 0,temp1;
    for (int i = 1 ; i < len; i++)
    {
      k=i-1;
    counter=0;
    temp1 = *(arr+i);
    while ((k>=0)&&(*(arr+i)<*(arr+k)))
    {
           k--;
           counter++;
    }
    k++;
    shift_element(arr+k,counter);
    *(arr+k) = temp1;
    }
    
}