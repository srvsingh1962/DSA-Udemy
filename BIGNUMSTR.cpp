#include<bits/stdc++.h>
using namespace std;

bool compare(string s1, string s2){
    if(s1.length()!=s2.length()){
        return s1.length() < s2.length();
    }
    return s1 > s2;
}

string concatenate(vector<int> numbers){
    vector<string> result;
    string answer = "";
    for(auto i : numbers){
        string key;
        stringstream ss(key);
        ss << i;
        ss >> key;
        result.push_back(key);
    }
    sort(result.begin(),result.end(),compare);
    for(auto i : result){
        answer += i;
    }
    return answer;
}

int main()
{
    vector<int> numbers = {10,11,20,30,3};
    string ans = concatenate(numbers);
    cout<<ans<<endl;
    return 0;
}