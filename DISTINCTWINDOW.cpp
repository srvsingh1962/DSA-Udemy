// Coded by Sourav Singh
#include<bits/stdc++.h>
using namespace std;

string smallestWindow(string str){
    unordered_set<char> ele;
    int n = str.length();
    for(int i = 0; i < n; i++){
        ele.insert(str[i]);
    }
    int total_element = ele.size();
    int cnt = 0;
    int FP[256] = {0};
    int FS[256] = {0};
    int start = 0;
    int min_window = INT_MAX;
    int start_win = -1;

    for(auto it = ele.begin(); it != ele.end(); it++){
        FP[*it]++;
    }
    for(int i = 0; i < n; i++){
        FS[str[i]]++;
        
        if(FS[str[i]]==1 && FP[str[i]]==1){
            cnt++;
        }
        if(cnt == total_element){
            while(i-start+1!=total_element){
                FS[str[start]]--;
                if(FP[str[start]]==1 && FS[str[start]]==0){
                    cnt--;
                }
                start++;
            }
            if(min_window > i-start+1 && cnt == total_element){
                min_window = i-start+1;
                start_win = start;
            }
        }
    }
    if(start_win==-1){
        return "";
    }
    return str.substr(start_win, min_window);
}

int main()
{
    string s;
    getline(cin,s);
    auto ans = smallestWindow(s);
    cout<<ans<<endl;
    return 0;
}