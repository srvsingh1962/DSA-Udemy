#include<bits/stdc++.h>
using namespace std;

string breakPalindrome(string palindrome) {
    int N = palindrome.length();
    bool flag = false;
    if(N%2 == 0){
        flag = true;
    }
    for(int i = 0; i < N && N > 1; i++){
        if(flag == false && i == N/2){
            continue;
        }
        if(palindrome[i] > 'a'){
            palindrome[i] = 'a';
            return palindrome;
        }
    }
    int a = 2;
    for(int i = 0; i < N && N > 1; i++){
        if(palindrome[i] == 'a'){
            a--;
            if(a == 0){
                palindrome[i] = 'b';
                return palindrome;
            }
        }
    }
    return "";
}

int main()
{
    string str;
    getline(cin, str);
    string output = breakPalindrome(str);
    cout<<output;
    cout<<endl;
    return 0;
}