// Coded by Sourav Singh
#include<bits/stdc++.h>
using namespace std;

int merge(vector<int> &v, int start, int last){
    int i = start;
    int m = (start + last)/2;
    int j = m + 1;
    int inv_cnt = 0;
    vector<int>temp;
    while(i <= m && j <= last){
        if(v[i] <= v[j]){
            temp.push_back(v[i]);
            i++;
        }
        else{
            inv_cnt += (m-i+1);
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
    return inv_cnt;
}

int inversion_count(vector<int> &v, int start, int last){
    if(start>=last){
        return 0;
    }

    int mid = (start+last)/2;
    int a = inversion_count(v,start,mid);
    int b = inversion_count(v,mid+1,last);
    int c = merge(v,start,last);
    return a+b+c;
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
    cout<<inversion_count(v,0,n-1)<<endl;
    return 0;
}