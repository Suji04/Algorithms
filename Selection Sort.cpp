#include <iostream>
#define ll long long
using namespace std;

void selectionSort(ll arr[], ll n){
	for(int i=0; i<n-1; i++){
		int minIdx=i;
		for(int j=i+1; j<n; j++){
			if(arr[j]<arr[minIdx]){
				minIdx=j;
			}
		}
		swap(arr[minIdx],arr[i]);
	}
}

int main(){
	ll n;
	cin>>n;
	ll A[n];
	for(int i=0; i<n; i++) cin>>A[i];
	selectionSort(A,n);
	for(int i=0; i<n; i++) cout<<A[i]<<' ';
}
