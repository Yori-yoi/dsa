#include<stdio.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int B[],int low,int high){
    int pivot=B[low];
    int i=low+1;
    int j=high;
    do{
        while (i <= high && B[i] <= pivot) { i++; }
        while(B[j]>pivot){
            j--;   
        }
        if(i<j){
            swap(&B[i],&B[j]);
        }
    }while(i<j);
    swap(&B[low],&B[j]);
    return j;
    

}
int quicksort(int low, int high,int B[]){
    if(low<high){
        int partition_index=partition(B,low,high);
        quicksort(low,partition_index-1,B);
        quicksort(partition_index+1,high,B);
    }
}

                
int main(){
    int A[]={5,4,1,8,4,2,8,1,13,15,23,229,3399,6095,8,2,9,2,3,1,9,0,2,10};
    int n=17;
    quicksort(0,16,A);
    for(int i=0;i<17;i++){
        printf("%d ",A[i]);
    }
}