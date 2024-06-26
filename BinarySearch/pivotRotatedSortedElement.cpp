#include <bits/stdc++.h>
using namespace std;
int pivotIndex(int arr[], int n)
{
    int start = 0, end = n - 1;
    int mid = start + (end - start) / 2;
    while (start < end)
    {
        if (arr[mid] >= arr[0])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
        
        mid = start + (end - start) / 2;
    }

    return start;
}

int binarySearch(int arr[] ,int start,int end ,int key){
    int left=start, right=end-1;
    int mid = left+ (right - left)/2;
    while(left <= right){
        if(arr[mid] == key){
            return mid;
        }
        if( key > arr[mid]){
            left= mid+1;
        }
        else{
            right = mid-1;
        }
        mid = left+ (right - left)/2;
    }
    return -1;
}

int main()
{
    int arr[] = {4,5,6,7,0,1,2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int pivot= pivotIndex(arr, n );
    int target=3;
    if(target>=arr[pivot && target <= arr[n-1]]){
        return binarySearch(arr , pivot ,n-1,target );
    }
    else{
        return binarySearch(arr , 0,pivot-1,target );
    }
    // cout << "Pivot Index is: " << pivotIndex(arr, n);
}
