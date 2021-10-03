// https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

#include <bits/stdc++.h>
using namespace std;
void merge(int arr[], int low, int high, int &count){
    int mid = (low + high)/2; 
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int left[n1], right[n2];
    // copy data to temp arrays L[] and R[]
    for(int i = 0; i < n1; i++){
        left[i] = arr[low + i];
    }
    for(int i = 0; i < n2; i++){
        right[i] = arr[mid + 1 + i];
    }
    // Merge the temp arrays back into arr[l..r]
    int i = 0, j = 0, k = low;
    while(i < n1 && j < n2){
        // If the current element in Left[] is smaller than
        if(left[i] <= right[j]){
            arr[k] = left[i];
            i++;
        }
        // If the current element in Right[] is smaller than
        else{
            arr[k] = right[j];
            j++;
            // Inversion count is incremented by the number of elements remaining in Left[]
            count += n1 - i;
        }
        k++;
    }
    // Copy the remaining elements of Left[]
    while(i < n1){
        arr[k] = left[i];
        i++;
        k++;
    }
    // Copy the remaining elements of Right[]
    while(j < n2){
        arr[k] = right[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[] ,int low, int high, int &count){

    if(low<high){
        int mid = low + (high - low)/2;
        merge_sort(arr,low,mid, count);
        merge_sort(arr,mid+1,high, count);
        merge(arr,low,high, count);
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int count=0;
    merge_sort(arr,0,n-1,count);
    // for(int i = 0; i < n; i++){
    //     cout << arr[i] << " ";
    // }
    cout<<count<<endl;

    return 0;
}