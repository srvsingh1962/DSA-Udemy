#include<bits/stdc++.h>
using namespace std;

bool compare(string str1, string str2){
    return str1 + str2 < str2 + str1;
}

int main()
{
    int n; cin>>n;
    vector<string> str(n);
    for(int i = 0; i < n; i++){
        cin>.str[i];
    }
    sort(str.begin(), str.end(), compare);
    for(auto i : str){
        cout<<i;
    }
    cout<<endl;
    return 0;
}