// Coded by Sourav Singh
#include<bits/stdc++.h>
using namespace std;

int rain( vector<int> &v ){
    int n = v.size();
    vector<int> Height_L(n);
    vector<int> Height_R(n);
    int sum = 0;
    Height_L[0] = v[0];
    Height_R[n-1] = v[n-1];
    for(int i = 1; i < n; i++){
        Height_L[i] = max(Height_L[i-1],v[i]);
        Height_R[n-i-1] = max(Height_R[n-i],v[n-i-1]);
    }
    for(int i = 0; i < n; i++){
        sum += min(Height_L[i],Height_R[i])-v[i];
    }
    return sum;
}

int main()
{
    vector<int> v = {0,1,0,2,1,0,1,3,2,1,2,1};
    auto answer = rain(v);
    cout<<answer<<endl;
    return 0;
}