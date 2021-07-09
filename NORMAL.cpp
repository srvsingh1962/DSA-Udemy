#include<bits/stdc++.h>
using namespace std;

string normalize(const string &sentence) {
    string copy = sentence;
    if(copy.length() == 1){
        if(copy[0]>96 && copy[0]<123){
            copy[0] = copy[0]- 32;
        }
        return copy;
    }
    vector<int > v;
    v.push_back(-1);
    for(int i = 0; i < copy.length(); i++){
        if(copy[i]>64 && copy[i]<91){
            copy[i] = copy[i] + 32;
            cout<<copy[i]<<endl;
        }
        if(copy[i]==' '){
            v.push_back(i);
        }
    }
    for(auto i : v){
        if(copy[i+1] >= 'a' && copy[i+1] <= 'z'){
            copy[i+1] = copy[i+1]-32;
        }
    }
    return copy;
}

int main()
{
    string str;
    getline(cin, str);
    string output = normalize(str);
    cout<<output;
    cout<<endl;
    return 0;
}