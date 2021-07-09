#include<bits/stdc++.h>
using namespace std;

bool numeric(pair<string,string> s1, pair<string,string> s2){
    string str1 = s1.second;
    string str2 = s2.second;
    stringstream a(str1);
    stringstream b(str2);
    int i = 0, j = 0;
    a >> i;b >> j;
    return i < j;
}

bool lexico(pair<string,string> s1, pair<string,string> s2){
    string str1 = s1.second;
    string str2 = s2.second;
    return str1 < str2;
}

string token_strtok(string str, int key){
    char *token = strtok( (char *)str.c_str()," ");
    while(key > 1){
        token = strtok(NULL," ");
        key--;
    }
    return (string)token;
}

int main()
{
    int n;
    cin>>n;
    cin.get();
    vector<string> v;
    string str;
    for(int i = 0; i < n; i++){
        getline(cin, str);
        v.push_back(str);
    }
    int key;
    string reversal,logic;
    cin>>key>>reversal>>logic;
    vector<pair<string,string> > ex;
    for(int i = 0 ; i < n; i++){
        ex.push_back({v[i], token_strtok(v[i],key)});
    }
    if(logic == "numeric"){
        sort(ex.begin(),ex.end(),numeric);
    }
    else{
        sort(ex.begin(),ex.end(),lexico);
    }
    if(reversal=="true"){
        for(int i = n-1; i >= 0; i--){
            cout<<ex[i].first<<"\n";
        }
    }
    else{
        for(int i = 0; i < n; i++){
            cout<<ex[i].first<<"\n";
        }
    }
    return 0;
}