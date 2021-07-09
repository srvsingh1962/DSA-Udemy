// Coded by Sourav Singh
#include<bits/stdc++.h>
using namespace std;

string string_window(string s, string p){
    int FP[256] = {0};
    int FS[256] = {0};

    for(int i = 0; i < p.length(); i++){
        FP[p[i]]++;
    }

    int cnt = 0;
    int start = 0;
    int min_window = INT_MAX;
    int start_win = -1;

    for(int i = 0; i < s.length(); i++){
        FS[s[i]]++;
        if(FP[s[i]]!=0 && FS[s[i]]<=FP[s[i]]){
            cnt++;
        }
        if(cnt == p.length()){
            while(FP[s[start]]==0 || FS[s[start]]>FP[s[start]]){
                FS[s[start]]--;
                start++;
            }
            if(min_window>(i - start + 1)){
                min_window = i-start+1;
                start_win = start; 
            }
        }
    }
    if(start_win==-1){
        return "";
    }
    return s.substr(start_win,min_window);
}

int main()
{
    string s,p;
    getline(cin,s);
    getline(cin,p);
    auto ans = string_window(s,p);
    cout<<ans<<endl;
    return 0;
}