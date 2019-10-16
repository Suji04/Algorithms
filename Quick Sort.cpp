#include <iostream>
using namespace std;

int partition(int arr[], int lo, int hi){
	int piv=arr[hi];
	int i=lo-1;
	for(int j=lo; j<=hi; j++){
		if(arr[j]<=piv){
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i+1],arr[hi]);
	return i+1;
}

void quickSort(int arr[],int lo, int hi){
	if(lo<hi){
		int pi=partition(arr,lo,hi);
		quickSort(arr,lo,pi-1);
		quickSort(arr,pi+1,hi);
	}
}

int main(){
	int n;
	cin>>n;
	int A[n];
	for(int i=0; i<n; i++) cin>>A[i];
	quickSort(A,0,n-1);
	for(int i=0; i<n; i++) cout<<A[i]<<' ';
	return 0;
}
