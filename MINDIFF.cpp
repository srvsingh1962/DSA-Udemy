#include<bits/stdc++.h>
using namespace std;

pair<int,int> minDifference(vector<int> a,vector<int> b){
    //Complete this method
    int n = a.size();
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int j = 0;
    int least = INT_MAX;
    pair<int,int> ans;
    for(int i = 0; i < n; i++){
        while(a[i] > b[j]){
            j++;
        }
        if(a[i]<=b[j]){
            int prev_least = least;
            least = min(least,abs(a[i]-b[j]));
            if(prev_least != least){
                ans.first = a[i];
                ans.second = b[j];
            }
        }
    }
    return ans;
    
}

int main()
{
    vector<int> a = {7,4,1,1,1};
    vector<int> b = {1,1,1,6,5};
    auto answer = minDifference(a,b);
    cout<<answer.first<<" "<<answer.second<<endl;
    return 0;
}