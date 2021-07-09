// Coded by Sourav Singh
#include<bits/stdc++.h>
using namespace std;

pair<int,int> search(int m, int n, vector<vector<int> > v, int k){
    int j = 0;
    int i = 0;
    for(int a = 0; a < m*n; a++){
        if(j == n){j = 0; i++;}
        if(v[i][j] == k){
            return {i, j};
        }
        j++;
    }
    return {-1, -1};
}

int main()
{
    int m,n; cin>>m>>n;
    vector<vector<int> > v(m);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            int a;
            cin>>a;
            v[i].push_back(a);
        }
    }
    int k; cin>>k;
    auto ans = search(m, n, v, k);
    cout<<ans.first<<" "<<ans.second<<endl;
    return 0;
}