#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int * insertionSort(int arr[],int n)
{
    for(int i=1;i<n;i++)
{
    int key=arr[i];
    int j=i-1;
    while(j>=0&&arr[j]>key)
    {
        arr[j+1]=arr[j];
        j--;

    }
    arr[j+1]=key;
}


    return arr;
}
int * twoSum(int arr[],int n,int target)
{
    int * res=(int * )malloc(2*sizeof(int));
    int i=0;
    int j=n-1;
    int z=0;
 
    
    while(i < j)
    {
        int sum = arr[i] + arr[j];

        if(sum == target)
        {
            res[0] = i;
            res[1] = j;
            return res;
        }
        else if(sum < target)
            i++;
        else
            j--;
    }

    return res;
}
int main(void)
{

    printf("checking the arrey is in sorted order\n");
    printf("hi enter the size of an  array\n ");
    int n;
    scanf("%d",&n);
    int * arr=(int *)malloc(n*sizeof(int));
    srand(time(NULL));
    for(int i=0;i<n;i++)
    {
        arr[i]=rand()%100;
    }

    int * result= insertionSort(arr,n);
    printf("Below is  array of sorted order\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",result[i]);
    }
    int target;
    printf("enter the target value\n");
    scanf("%d",&target);
    int * res=twoSum(result,n,target);

    if(res)
    {
        for(int i=0;i<2;i++)
        {
            printf("%d ",res[i]);
        }

    }
    else{
        printf("target not found in array\n");
    }

 

return 0;
}
