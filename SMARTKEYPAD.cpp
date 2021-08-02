// Coded by Sourav Singh
#include<bits/stdc++.h>
using namespace std;

string keypad[] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void printKeypadOutput(string input, string output, int i = 0){
    if(input[i] == '\0'){
        cout<<output<<endl;
        return;
    }
    int dig = input[i] - '0';
    if(dig == 0 || dig == 1){
        printKeypadOutput(input, output, i+1);
    }
    for(int k = 0; k < keypad[dig].size(); k++){
        printKeypadOutput(input, output+keypad[dig][k], i+1);
    }
    return;
}

int main(){
    string s; cin>>s;
    string output;
    printKeypadOutput(s, output);
    return 0;
}