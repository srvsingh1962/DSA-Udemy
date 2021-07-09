#include<bits/stdc++.h>
using namespace std;

int Occurence(string &s, long unsigned int pos){
    while(pos < s.length() && s[pos] == s[pos+1]){
        pos++;
    }
    return pos;
}

string compressString(const string &str){ 
    string s = str;
    string answer = "";
    for(long unsigned int i = 0; i < s.length(); ){
        answer += s[i];
        long unsigned int count = Occurence(s,i) -i +1;
        answer += to_string(count);
        i += count;
    }
    if(answer.length() < s.length())
        return answer;
    return s;
}

int main()
{
    string str;
    getline(cin, str);
    string output = compressString(str);
    cout<<output;
    cout<<endl;
    return 0;
}