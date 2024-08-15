#include<bits/stdc++.h>
using namespace std;

int maximumFrequency(vector<int> &arr, int n) {
    unordered_map<int, int> freq;
    int maxCount = 0;
    int maxAns =0; // Initialize ret with the first element

    for (int i = 0; i < n; ++i) {
        freq[arr[i]]++;
        maxCount =max(maxCount, freq[arr[i]]);
        // If we find a new maximum frequency, or it's the first time
    }

    for(int i=0; i<n ;i++){
        if (freq[arr[i]] == maxCount) {
            maxAns = arr[i];
            break;
        }
    }

    return maxAns;
}