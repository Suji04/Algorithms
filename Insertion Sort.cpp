#include <iostream>
#define ll long long
using namespace std;

void insertionSort(ll A[],ll l,ll r){
	for(int j=1; j<r; j++){
		ll key=A[j];
		for(int i=j-1; i>=l&&A[i]>key; i--){
			A[i+1]=A[i];
			A[i]=key;
		}
	}
}

int main(){
	ll n;
	cin>>n;
	ll A[n];
	for(int i=0; i<n; i++){
		cin>>A[i];
	}
	insertionSort(A,0,n);
	for(int i=0; i<n; i++){
		cout<<A[i]<<' ';
	}
	return 0;
}
