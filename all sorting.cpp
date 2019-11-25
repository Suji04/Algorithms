#include<bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int> &arr){
	int n = arr.size();
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if(arr[i]>arr[j])
				swap(arr[i], arr[j]);
		}
	}
}

void selection_sort(vector<int> &arr){
	int n = arr.size();
	for(int i=0; i<n; i++){
		int m=i;
		for(int j=i; j<n; j++){
			if(arr[j]<arr[m])
				m=j;
		}
		swap(arr[m], arr[i]);
	}
}

void insertion_sort(vector<int> &arr){
	int n = arr.size();
	for(int i=1; i<n; i++){
		int j=i-1;
		int k=arr[i];
		while(arr[j]>k && j>=0){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1]=k;
	}
}

void merge(vector<int> &arr, int p, int q, int r){
	int m=q-p+2, n=r-q+1;
	int li[m], re[n];
	for(int i=0; i<m-1; i++)
		li[i]=arr[i+p];
	for(int i=0; i<n-1; i++)
		re[i]=arr[i+q+1];
	li[m-1]=99999999;
	re[n-1]=99999999;

	int i=0, j=0;
	for(int k=p; k<=r; k++){
		if(li[i]<=re[j]){
			arr[k]=li[i];
			i++;
		}
		else{
			arr[k]=re[j];
			j++;
		}
	}
}

void merge_sort(vector<int> &arr, int p, int r){
	if(p<r){
		int q = (p+r)/2;
		merge_sort(arr, p, q);
		merge_sort(arr, q+1, r);
		merge(arr, p, q, r);
	}
}

int partition(vector<int> &arr, int p, int r){
	int pivot = arr[r];
	int i=p-1;
	for(int j=p; j<=r-1; j++){
		if(arr[j]<=pivot){
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i+1], arr[r]);
	return (i+1);   
}

void quick_sort(vector<int> &arr, int p, int r){
	if(p<r){
		int q = partition(arr, p, r);
		quick_sort(arr, p, q-1);
		quick_sort(arr, q+1, r);
	}
}

void max_heapify(vector<int> &arr, int i, int heap_size){
	int l = 2*i, r=2*i+1;
	int largest=i;
	if(l<=heap_size-1 && arr[l]>arr[i])
		largest=l;
	if(r<=heap_size-1 && arr[r]>arr[largest])
		largest=r;
	if(largest!=i){
		swap(arr[i], arr[largest]);
		max_heapify(arr, largest, heap_size);
	}
}

void heap_sort(vector<int> &arr){
	int heap_size = arr.size();
	for(int i=heap_size/2; i>=0; i--){
		max_heapify(arr, i, heap_size);
	}
	for(int i=heap_size-1; i>=1; i--){
		swap(arr[i], arr[0]);
		heap_size--;
		max_heapify(arr, 0, heap_size);
	}
}

int main(){
	vector<int> arr = {9,2,5,10,65,42,30,7};

	bubble_sort(arr);
	selection_sort(arr);
	insertion_sort(arr);
	merge_sort(arr, 0, arr.size()-1);
	quick_sort(arr, 0, arr.size()-1);
	heap_sort(arr);
	for(auto i:arr)
		cout<<i<<" ";

	srand(time(0));
	map<int, vector<int>> data;
	for(int i=1; i<100; i+=2){
		int k=i;
		while(k>0){
			data[i].push_back(rand());
			k--;
		}
	}

	auto start = chrono::steady_clock::now();
	for(auto i:data){
		for(int j=0; j<(i.second).size(); j++){
			cout<<i.second[j]<<" ";
		}
		cout<<endl;
	}
	auto end = chrono::steady_clock::now();
	auto diff = end-start;
	cout<<"time taken "<<chrono::duration <double, milli> (diff).count();

	return 0;
}