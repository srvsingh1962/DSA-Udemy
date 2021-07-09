#include<bits/stdc++.h>
using namespace std;

vector<string> tokenization_strtok(char str[]){
    vector<string>answer;
    char *token = strtok(str," ");
    while(token!= NULL){
        answer.push_back(token);
        token = strtok(NULL," ") ;
    }
    return answer;
}

vector<string> tokenization_stream(string str){
    int n = str.length();
    vector<string>ans;
    stringstream ss(str);
    string token;
    while(getline(ss, token, ' ')){
        ans.push_back(token);
    }
    return ans;
}

int main()
{
    string str;
    getline(cin, str);
    char str1[10000];
    cin.getline(str1,10000);
    auto answer = tokenization_stream(str);
    for(auto i : answer){
        cout<<i<<",";
    }
    cout<<endl;
    answer = tokenization_strtok(str1);
    for(auto i : answer){
        cout<<i<<",";
    }
    cout<<endl;
    return 0;
}