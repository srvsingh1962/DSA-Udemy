// Coded by Sourav Singh
#include<bits/stdc++.h>
using namespace std;

bool OutofOrder(vector<int> &v,int i){
    int x = v[i];
    if(i == 0){
        return x > v[1];
    }
    if(i == v.size()-1){
        return x < v[i-1];
    }
    return x > v[i+1] or x < v[i-1];
}

pair<int, int> subarray_sort(vector<int> &v){
    int n = v.size();
    int s = INT_MAX;
    int l = INT_MIN;
    if(v[0] > v[1]){ s = min(v[0],s);}
    if(v[n-1] < v[n-2]){ l = max(v[n-1],l);}
    for(int i = 0; i < n; i++){
        if(OutofOrder(v,i)){
            s = min(v[i],s);
            l = max(v[i],l);
        }
    }
    if(s == INT_MAX){ return {-1,-1};}
    int a = 0,b = n-1;
    while(s>=v[a]){a++;}
    while(s<=v[b]){b--;}
    
    return {a,b};
}


int main()
{
    vector<int> v = {1,2,3,4,5,6,7,8,9,10,11};
    auto ans = subarray_sort(v);
    cout<<ans.first<<" "<<ans.second<<endl;
    return 0;
}