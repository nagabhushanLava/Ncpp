#include<stdio.h>
#include<stdlib.h>
int binarySearch(int arr[],int size,int key)
{   int low=0;
    int high=size-1;
    int mid=0;
    while(low<=high){
        mid = low+(high-low)/2;
        if(arr[mid]==key)
        {
            return mid;
        }
        else if(arr[mid]<key)
        {
        low=mid+1;   
        }
        else{
            high=mid-1;
        }

    }

    return -1;
}

int main(void)
{
  printf("hi we are writing binary search alogritham to find the element \n");

    int key ;
    
     int n;

     printf("enter the size of array ");
    scanf("%d",&n);
     int * arr= (int * )malloc(n*sizeof(int));
  
     for(int i=0;i<n;i++)
     {
        arr[i]=i+1;
    }
    printf("enter the value of key to find");
    scanf("%d",&key);

    int v=binarySearch(arr,n,key);
    if(v!=-1)
    {
    printf("the value fount  at the array %d",v);
    }
    else{
        printf("key was not found\n");
    }
return 0;
}
