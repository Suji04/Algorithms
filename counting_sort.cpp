#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Complexeity is O(n + max_val) in case of integer sorting
void csort(int* a, int n){
    unordered_map<int, int> hash;
    int max_val = INT_MIN;
    for(int i=0; i<n; i++){
      hash[a[i]]++;
      if(a[i]>max_val)max_val = a[i];
    }
    int j=0;
    for(int i=0; i<=max_val; i++){
        while(hash[i]--){
            a[j]=i;
            j++;
        }
    }
}
int main(){
    int n;
    int* a;
    cin>>n;
    a = new int[n];
    for(int i=0; i<n; i++)
    cin>>a[i];
    csort(a, n);
    for(int i=0; i<n; i++)cout<<a[i]<<' ';
    return 0;
}