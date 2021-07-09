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

void quick_sort(vector<int> &v, int s, int e){
    if(s>=e){
        return;
    }
    int p = partition(v, s, e);
    quick_sort(v, s, p-1);
    quick_sort(v, p+1, e);
}

int main()
{
    int n; cin>>n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    quick_sort(v,0,n-1);
    for(auto i : v){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}