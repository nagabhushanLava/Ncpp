#include<stdio.h>
#include<stdlib.h>
int * reverse(int arr[],int l,int size)
{
int low=l;
int high=size;
int temp=0;
while(low<high)
{
    temp=arr[low];
    arr[low]=arr[high];
    arr[high]=temp;
    low++;
    high--;
}

return arr;
}

int main()
{
    printf("hi we are reversing array \n");
    int n,k;
    printf("hi enter thve size of array\n");
    scanf("%d",&n);
    printf("enter how many steps it needs to rotate\n");
    scanf("%d",&k);
    int *result=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        result[i]=i+1;
    }
    result=reverse(result,0,n-1);
    result=reverse(result,0,k-1);
    result=reverse(result,k,n-1);
    for(int j=0;j<n;j++)
    {
        printf("%d ",result[j]);
    }
return 0;
}