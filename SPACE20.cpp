#include<bits/stdc++.h>
using namespace std;

vector<char> replace20(string str){
    int n = str.length();
    vector<char>ans;
    for(int i = 0; i < n; i++){
        if(str[i]==' '){
            ans.push_back('%');
            ans.push_back('2');
            ans.push_back('0');
        }
        else
            ans.push_back(str[i]);
    }
    return ans;
}

int main()
{
    char str[10000];
    cin.getline(str,10000);
    auto answer = replace20(str);
    for(auto i : answer){
        cout<<i;
    }
    cout<<endl;
    return 0;
}