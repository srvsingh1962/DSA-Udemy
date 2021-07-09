#include<bits/stdc++.h>
using namespace std;

bool compare(pair<string,int> a, pair<string,int> b){
    return a.second < b.second;
}

int badness(vector<pair<string,int> > teams){
    sort(teams.begin(), teams.end(), compare);
    int bdness = 0;
    int j = 1;
    for(auto i : teams){
        bdness += abs(i.second - j);
        j++;
    }
    return bdness;
}

int main(){
    int n; cin>>n;
    getline(cin, "");
    vector<pair<string,int> > v(n);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            string s; int a;
            getline(cin, S);
            cin>>a;
            v[i] = {s,a};
        }
    }
    auto ans = badness(v);
    cout<<ans<<endl;
}