#include<bits/stdc++.h>
using namespace std;

vector<int> productArray(vector<int> arr){
    
    //Create an output Array
    int n = arr.size();
    vector<int> output(n,1);
    vector<int> forward(n,1);
    vector<int> backward(n,1);
    
    //update the output array and return
    //complete the code
    
    for(int i=1;i<n;i++){
        forward[i]  = forward[i-1]*arr[i-1];
        backward[n-i-1] = backward[n-i]*arr[n-i]; 
    }
    for(int i=0;i<n;i++){
        output[i] = forward[i]*backward[i];
    }
    return output;
}

int main()
{
    vector<int> v = {7,4,1,1,1};
    auto answer = productArray(v);
    for(auto i : answer){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}