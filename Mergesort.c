#include<stdio.h>
#include<stdlib.h>
//int e,f,d;
void merge(int *arr,int start,int mid,int end){
  //  printf("merge:%d\n",++e);
    int i=start,j=mid+1,k=end,index=start,temp[10];
    while((i<=mid) && (j<=end)){
        if(arr[i]<arr[j]){
             temp[index++]=arr[i++];
        }
        else{
            temp[index++]=arr[j++];
        }
    } 
        if(i<=mid)
        while(i<=mid){
            temp[index++]=arr[i++];
        }
        else
        while(j<=end){
            temp[index++]=arr[j++];
        }
        for(int p=start;p<index;p++){
            arr[p]=temp[p];
      //      printf("%d\t",arr[p]);
        }
    //    printf("\n");
}
void merge_sort(int *arr,int start,int end){
    if(start<end){
        int mid= (start+end)/2;
        //printf("merge_sort:%d\n",++d);
        merge_sort(arr,start,mid);
        //printf("merge_sortmid:%d\n",++f);
        merge_sort(arr,mid+1,end);
        merge(arr,start,mid,end);
    }
}
void main(){
    int n;
    printf("Enter size of array\n");
    scanf("%d",&n);
    printf("Enter array elements\n");
int *arr=(int*)malloc(n*sizeof(int));
for(int i =0;i<n;i++)
scanf("%d",&arr[i]);
merge_sort(arr,0,n-1);
for(int i=0;i<n;i++)
printf("%d\t",arr[i]);
}

