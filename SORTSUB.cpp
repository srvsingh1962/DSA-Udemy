#include<bits/stdc++.h>
using namespace std;

void sort_sub(string str, string sub, vector<string> &v){
    //Base case
    if(str.size()==0){
        v.push_back(sub);
        return;
    }

    //Recursice case
    char ch = str[0];
    sort_sub(str.substr(1),sub+ch,v);
    sort_sub(str.substr(1),sub,v);
}

bool compare(string s1, string s2){
    if(s1.length()==s2.length()){
        return s1 < s2;
    }
    return s1.length() < s2.length();
}

int main()
{
    string str;
    getline(cin, str);
    string output = "";
    vector<string> v;
    sort_sub(str,output,v);
    sort(v.begin(),v.end(),compare);
    for(auto i : v){
        cout<<i<<",";
    }
    cout<<endl;
    return 0;
}