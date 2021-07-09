#include<bits/stdc++.h>
using namespace std;

int maxSubarraySum(vector<int> arr){
    //Complete this function, your function should return the maximum subarray sum
    int n = arr.size();
    int best = 0;
    int sum = 0;
    for(int i = 0; i < n ; i++){
        sum = max(arr[i], sum + arr[i]);
        best = max(sum, best);
    }
    return best;
}

int main()
{
    vector<int> v = {7,4,1,1,1};
    auto answer = maxSubarraySum(v);
    cout<<answer<<endl;
    return 0;
}