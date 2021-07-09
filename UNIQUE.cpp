#include<bits/stdc++.h>
using namespace std;

string unique_string(string str){
    int n = str.length();
    unordered_map<char,int> ele;
    int start = -1;
    int win_len = 0;
    int max_win_len = 0;
    int i = 0, j = 0;
    while(j < n){
        char ch = str[j];
        if(ele.count(ch) && ele[str[j]] >= i){
            i = ele[ch] + 1;
            win_len = j - i;
        }
        ele[ch] = j;
        win_len++;
        j++;

        if(win_len > max_win_len){
            max_win_len = win_len;
            start = i;
        }
    }
    return str.substr(start,max_win_len);
}

int main()
{
    string str;
    getline(cin, str);
    auto answer = unique_string(str);
    cout<<answer<<endl;
    return 0;
}