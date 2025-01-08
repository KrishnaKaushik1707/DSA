#include<iostream>
using namespace std;


int Partition(int a[], int lb, int ub){
    int pivot = a[lb];
    int start = lb;
    int end = ub;
    
    while(start<end){
        
        while(a[start]<=pivot){
            start ++;
        }
        while(a[end]>pivot){
            end--;
        }
        if(start<end){
            swap(a[start], a[end]);
        }
        
    }
    
    
    swap(a[lb], a[end]);
    return end;
        
    
}

void QuickSort(int a[], int lb, int ub){
    if(lb<ub){
        int loc = Partition(a,lb,ub);
        QuickSort(a,lb,loc-1);
        QuickSort(a,loc+1,ub);
    }
}

int main(){
    int n;
    cout<<"enter the no.of elements in the array: ";
    cin>>n;
    
    int a[n];
    cout<<"enter the elements in the array: ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    QuickSort(a,0,n-1);
    cout<<"sorted array is: ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}


