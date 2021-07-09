#include<bits/stdc++.h>
using namespace std;

//Time complexity - O(N)
vector<pair<int, int> > sliding_window(vector<int> &v, int k){
    vector<pair<int, int> > result;
    pair<int, int> sw = {0, v.size()};
    vector<int> pre_sum;
    int n = v.size();
    pre_sum.push_back(v[0]);
    for(int i = 1; i < n; i++){
        pre_sum.push_back(v[i]+pre_sum[i-1]);
    }
    int i = 0,j = 0;
    while(i < n && j < n){
        int target;
        if(v[i] < 0){
            if(i == j){
                j++;
            }
            i++;
        }
        if(v[j] < 0){
            i = j + 1;
            j++;
        }
        if(i == j){
            target = pre_sum[i];
        }
        else{
            target = pre_sum[j] - pre_sum[i] + v[i];
        }
        if(target > k){
            i++;
        }
        if(target < k){
            j++;
        }
        if(target == k){
            result.push_back({i,j});
            if((j - i) < (sw.second - sw.first)){
                sw.first = i;
                sw.second = j; 
            }
            j++;
        }
    }
    cout<<"Smallest : "<<sw.first<<" - "<<sw.second<<endl;
    return result;
}


// Time Complexity - O(N*N)
vector<pair<int, int> > housing(vector<int> &v, int k){
    vector<pair<int, int> > result;
    unordered_set<int> ele;
    vector<int> pre_sum;
    int n = v.size();
    pre_sum.push_back(v[0]);
    ele.insert(v[0]);
    for(int i = 1; i < n; i++){
        pre_sum.push_back(v[i]+pre_sum[i-1]);
    }
    for(int i = 0; i < n; i++){
        ele.insert(pre_sum[i]);
    }
    for(int i = 0; i < n; i++){
        int target = k + pre_sum[i];
        if(ele.find(target)!=ele.end()){
            for(int j = i+1; j < n; j++){
                if(target == pre_sum[j]){
                    result.push_back({i+1,j});
                }
            }
        }
    }
    return result;
}


int main()
{
    vector<int> v = {1,3,2,-1,4,1,-3,2,1,1,2};
    int k = 8;
    auto ans1 = housing(v,k);
    auto ans2 = sliding_window(v,k);
    for(auto i : ans1){
        cout<<i.first<<" "<<i.second<<endl;
    }
    cout<<endl;
    for(auto i : ans2){
        cout<<i.first<<" "<<i.second<<endl;
    }
    return 0;
}