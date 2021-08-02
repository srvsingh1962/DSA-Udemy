// Coded by Sourav Singh
#include<bits/stdc++.h>
using namespace std;

int countSubset(vector<int> arr, int n, int i, int X)
{
    if(i == n){
        if( X == 0){
            return 1;
        }
        return 0;
    }

    int include = countSubset(arr, n, i+1, X-arr[i]);
    int exclude = countSubset(arr, n, i+1, X);
    return include + exclude;
}

int main()
{
    int n; cin>>n;
    vector<int> arr{1, 2, 3, 4, 5};
    int X; cin>>X;
    cout<<countSubset(arr, n, 0, X)<<endl;
    return 0;
}