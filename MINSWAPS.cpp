// Coded by Sourav Singh
#include<bits/stdc++.h>
using namespace std;

int min_swaps(vector<int > &v){
    int n = v.size();
    int ans = 0;
    pair<int, int> b[n];
    for(int i = 0; i < n; i++){
        b[i].first = v[i];
        b[i].second = i;
        cout<<b[i].first<<" "<<b[i].second<<"\n";
    }
    cout<<endl;
    sort(b, b+n);
    for(int i = 0; i < n; i++){
        cout<<b[i].first<<" "<<b[i].second<<"\n";
    }
    cout<<endl;
    vector<bool> visited(n,false);
    for(int i = 0; i < n; i++){
        if(visited[i] == true or i == b[i].second){
            continue;
        }
        int j = i;
        int cycle = 0;
        while(!visited[j]){
            visited[j] = true;
            int p = b[j].second;
            j = p;
            cycle++;
        }
        ans+=(cycle-1);
    }
    return ans;
}

int main()
{
    vector<int> v = {7,4,1,1,1};
    auto answer = min_swaps(v);
    cout<<answer<<endl;
    return 0;
}