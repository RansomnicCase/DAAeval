#include<bits/stdc++.h>
using namespace std;


int binarysearch(int arr[], int n, int x){
    int s = 0;
    int e = n-1;
    while(s<=e){
        int mid = s+(e-s)/2;
        if(arr[mid]==x){
            return mid;
        }
        else if(arr[mid]<x){
            e=mid-1;
        }
        else{
            s = mid+1;
        }
    }
    return -1;
}


int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int x;
    cin>>x;
    int index = binarysearch(arr,n,x);
    if(index == -1){
        cout<<"Element not found";
    }
    else{
        cout<<"Element found at index "<<index;
    }
}