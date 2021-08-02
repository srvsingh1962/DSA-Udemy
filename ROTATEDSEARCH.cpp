// Coded by Sourav Singh
#include<bits/stdc++.h>
using namespace std;

int rotatedSearch(vector<int> &arr, int n, int k){
    int s = 0;
    int e = n-1;    
    while(s <= e){
        int mid = (s + e)/2;
        if(arr[mid] == k){
            return mid;
        }
        if(arr[s] <= arr[mid]){
            if(k >= arr[s] && k <= arr[mid]){
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        else{
            if(k >= arr[mid] && k <= arr[e]){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    int n; cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    int k; cin>>k;
    auto ans = rotatedSearch(arr, n, k);
    cout<<ans + 1<<endl;
    return 0;
}