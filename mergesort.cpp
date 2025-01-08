#include<iostream>
using namespace std; 


void merge(int a[],int low,int mid,int high){
	
	int i = low;
	int j = mid+1;
	int k=0;
	int b[high-low+1];
	
	while(i<=mid && j<=high){
		if(a[i]<=a[j]){
			b[k]= a[i];
			i++;
			k++;
		}
		
		else{
			b[k]= a[j];
			j++;
			k++;
		}
	}
	if(i>mid){
		while(j<=high){
			b[k] = a[j];
			j++;
			k++;
		}
	}
	else if (j>high){
		while(i<=mid){
			b[k]=a[i];
			i++;
			k++;
		}
	}
	
	for(i=low,k=0;i<=high;i++,k++){
		a[i] = b[k]; 
	}
}



void mergesort(int a[],int low,int high){
	if(low<high){
		int mid = (low+high)/2;
		mergesort(a,low,mid);
		mergesort(a,mid+1,high);
		merge(a,low,mid,high);
		}
	}
	
	
	
int main(){
	int n;
	cout<<"eneter the no.of elements in the array: ";
	cin>>n;
	
	int a[n];
	cout<<"enter the elements in the array: ";
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	mergesort(a,0,n-1);
	cout<<"sorted array: ";
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
}

