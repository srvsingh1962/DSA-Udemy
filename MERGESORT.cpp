// Coded by Sourav Singh
#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &v, int start, int last){
    int i = start;
    int m = (start + last)/2;
    int j = m + 1;
    vector<int>temp;
    while(i<=m && j<=last){
        if(v[i]<v[j]){
            temp.push_back(v[i]);
            i++;
        }
        else{
            temp.push_back(v[j]);
            j++;
        }
    }
    while(i<=m){
        temp.push_back(v[i++]);
    }
    while(j<=last){
        temp.push_back(v[j++]);
    }
    int k = 0;
    for(int idx = start; idx <= last; idx++){
        v[idx] = temp[k++];
    }
    return;
}

void mergesort(vector<int> &v, int start, int last){
    if(start>=last){
        return;
    }

    int mid = (start+last)/2;
    mergesort(v,start,mid);
    mergesort(v,mid+1,last);
    return merge(v,start,last);
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
    mergesort(v,0,n-1);
    for(int i = 0; i < n; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}