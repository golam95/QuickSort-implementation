#include <stdio.h>
#include <stdlib.h>

/*Declare Display Function */

void display(int*,int);

/*Declare swap Function swap between two number */

void swap(int *a, int *b)
{
    *a = *a - *b;
    *b = *b + *a;
    *a = *b - *a;
}

/*Declare the partition Function that is Integer type and return value */


int partition(int *arr, int start, int end)
{
    int pivot = start;
    int left = start , right = end;
    int i , pivotVal = arr[pivot];

    while(left < right)
    {
        while(arr[left] <= pivotVal && left <=end )
            left++;
        while(arr[right] > pivotVal && right >= 0)
            right--;
        if(left < right)
            swap(&arr[left], &arr[right]);
    }

    arr[start] = arr[right];
    arr[right] = pivotVal;

    return right;
}
/* Call the display_previous() function and passing parameter Array and length of Array  */
void quick(int *arr, int start, int end)
{
    int m;

    /*Here start define where we start and end defines pivot
      start compare small or big if condition is true than call
      the partition function and return value then pass into quick function
      pass the value m.

    */

    if(start < end)
    {
        m = partition(arr,start,end); //Pivot
        quick(arr,start,m-1);
        quick(arr,m+1,end);
    }
}
/*  Display the Sorted Array Element */

void display(int *arr,int getlength)
{
    int i;
    printf("After Sorting = ");
    for(i = 0; i < getlength; i++)
        printf("%d ",arr[i]);
    printf("\n");
}

/*  At first Display the unsorted Array Element */

void display_previous(int *arr,int getlength)
{
    int i;
    printf("\nBefore Sorting = ");
    for(i = 0; i < getlength; i++)
        printf("%d ",arr[i]);
    printf("\n\n");
}

int main()
{
    /* Here I am declare unsorted the Array Element */

    int arr[]= {5,10,8,7,6,4,3,12,14,2};

    /* Here I got out the length of Array suing sizeOf() function*/

    int getlength = sizeof(arr)/sizeof(int);

    /* Call the display_previous() function and passing parameter Array and length of Array  */

    display_previous(arr,getlength);

    /* Call the quick() function and passing parameter Array ,value(0) and the length of Array  */

    quick(arr, 0, getlength - 1);

    /* Call the display() function and passing parameter Array and length of Array  */

    display(arr,getlength);

}
