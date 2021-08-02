// Coded by Sourav Singh
#include<bits/stdc++.h>
using namespace std;

void generateBracket(string s, int n, int opening, int closing, int i){
    //base case
    if(i == 2*n){
        cout<<s<<endl;
    }
    if(opening < n){
        generateBracket(s+'(', n, opening + 1, closing, i+1);
    }
    if(closing < opening){
        generateBracket(s+')', n, opening, closing + 1, i+1);
    }
}

int main()
{
    int n; cin>>n;
    generateBracket("", n, 0, 0, 0);
    return 0;
}