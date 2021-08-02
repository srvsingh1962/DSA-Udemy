// Coded by Sourav Singh
#include<bits/stdc++.h>
using namespace std;

void min_pair(vector<int> &A, vector<int> &B){
    sort(B.begin(), B.end());
    int a,b;
    int diff = INT_MAX;
    for(auto x : A){
        auto lb = lower_bound(B.begin(), B.end(), x) - B.begin();
        if(lb >= 1 && x - B[lb-1] < diff){
            diff = x-B[lb-1];
            a = x;
            b = B[lb-1];
        }
        if(lb != B.size() && B[lb] - x < diff){
            diff = B[lb] - x;
            a = x;
            b = B[lb];
        }
    }
    cout<<a<<" "<<b<<endl;
}

int main()
{
    int n; cin>>n;
    int m; cin>>m;
    vector<int> A(n);
    vector<int> B(m);
    for(int i = 0; i < n; i++){
        cin>>A[i];
    }
    for(int i = 0; i < m; i++){
        cin>>B[i];
    }
    min_pair(A,B);
    return 0;
}