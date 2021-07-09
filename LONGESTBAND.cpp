// Coded by Sourav Singh
#include<bits/stdc++.h>
using namespace std;

// Time Conplexity - O(N)
vector<int> longest_band(vector<int> &v){
    unordered_set<int> ele;
    vector<int> result;
    vector<int> ans;
    for(auto i : v){
        ele.insert(i);
    }
    int n = v.size();
    for(int i = 0; i < n; i++){
        int j = v[i]; 
        if(ele.find(j-1) == ele.end()){
            while(ele.find(j+1)!=ele.end()){
                result.push_back(j);
                j++;
            }
            result.push_back(j);
            if(result.size()>ans.size()){
                ans = result;
                result.clear();
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> v = {1,9,3,0,18,5,2,4,10,7,12,6};
    auto answer = longest_band(v);
    for(auto i : answer){
        cout<<i<<" ";
    }
    cout<<endl;

    // Time Conplexity - O(N*log(N) + N)
    sort(v.begin(),v.end());
    vector<int > result;
    vector<int> ans;
    int n = v.size();
    for(int i = 0; i < n-1; i++){
        ans.push_back(v[i]);
        if(v[i+1] != v[i] + 1){
            if(result.size()<ans.size()){
                result = ans;
                ans.clear();
            }
        }
    }
    for(auto i : result){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}