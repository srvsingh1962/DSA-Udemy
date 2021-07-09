#include<bits/stdc++.h>
using namespace std;

int lower_bound(vector<int> &arr, int start, int end, int key){
    int min_pos = INT_MAX;
    while(start <= end){
        int mid = (start+end)/2;
        if(arr[mid] == key){
            min_pos = min(min_pos, mid);
            end = mid - 1;
            continue;
        }
        if(arr[mid] > key){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    if(min_pos == INT_MAX){
        return -1;
    }
    return min_pos;
}

int upper_bound(vector<int> &arr, int start, int end, int key){
    int min_pos = INT_MIN;
    while(start <= end){
        int mid = (start+end)/2;
        if(arr[mid] == key){
            min_pos = max(min_pos, mid);
            start = mid + 1;
            continue;
        }
        else if( arr[mid] > key ){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    if(min_pos == INT_MAX){
        return -1;
    }
    return min_pos;
}

int main(){
    int n;  cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    int key; cin>>key;
    int low = lower_bound(arr, 0, n-1, key);
    int high = upper_bound(arr, 0, n-1, key);
    if(low == -1 || high == -1){
        cout<<"Not Present"<<endl;
    }
    else{
        cout<<high - low + 1<<endl;
    }

    return 0;
}