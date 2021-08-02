// Coded by Sourav Singh
#include<bits/stdc++.h>
using namespace std;

int Ladder(int n){
    if(n < 0){
        return 0;
    }
    if(n == 0){
        return 1;
    }
    return Ladder(n - 1) + Ladder(n - 2) + Ladder(n - 3);
}

int main()
{
    int n; cin>>n;
    cout<<Ladder(n)<<endl;
    return 0;
}