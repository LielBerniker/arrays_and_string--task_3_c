#include <stdio.h>
#include "insert_sort.h"

/*
the function gets 50 numbers from input and insert them to array
then the function sort them in the array from smallest to the biggest
by the insert sort
*/
int main()
{
int arr[ARR_SIZE];
int num;
for (int i = 0; i < ARR_SIZE ; i++)
{
    scanf(" %d",&num);
    if(num != EOF)
    {*(arr+i)= num;}
    else
    {
        break;
    }
}
insertion_sort(arr,ARR_SIZE);
for (int j = 0; j < ARR_SIZE; j++)
{
    if(j==0)
    printf("%d",*(arr+j));
    else
    printf(",%d",*(arr+j));
}
    return 1;
}