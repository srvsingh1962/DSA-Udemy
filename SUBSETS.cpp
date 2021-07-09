#include<bits/stdc++.h>
using namespace std;

bool is_subset(string str1, string str2){
    int i = 0, j = 0;
    if(str2.length() == 0){
        return false;
    }
    while(i < str1.length() && j < str2.length()){
        if(str1[i] == str2[j]){
            j++;
        }
        i++;
    }
    if(j == str2.length()){
        return true;
    }
    return false;
}

int main()
{
    string str1;
    string str2;
    getline(cin, str1);
    getline(cin, str2);
    if(is_subset(str1, str2)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}