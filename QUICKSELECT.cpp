// Coded by Sourav Singh
#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &v, int start, int end){
    int pivot = v[end];
    int i = start-1;
    int j = start;
    while(j < end){
        if(v[j] < pivot){
            swap(v[i+1], v[j]);
            i++;
        }
        j++;
    }
    swap(v[i+1], v[end]);
    return i+1;
}

int quick_select(vector<int> &v, int s, int e, int k){
    int p = partition(v, s, e);
    if(p == k){
        return v[p];
    }
    else if(p < k){
        return quick_select(v, p+1, e, k);
    }
    else{
        return quick_select(v, s, p-1, k);
    }
}

int main()
{
    int n,k; cin>>n>>k;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    cout<<quick_select(v,0,n-1,k-1)<<endl;
    return 0;
}