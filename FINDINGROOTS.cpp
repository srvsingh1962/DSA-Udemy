// Coded by Sourav Singh
#include<bits/stdc++.h>
using namespace std;

float findingRoot(int n, int p){
    int s = 0;
    int e = n;
    float ans = INT_MAX;
    while(s <= e){
        int mid = (s + e)/2;
        if(mid*mid == n){
            return mid;
        }
        else if(mid*mid > n){
            e = mid - 1;
        }
        else if(mid*mid < n){
            s = mid + 1;
            ans = mid;
        }
    }
    float div = 0.1;
    for(int place = 1; place <= p; place++){
        while(ans*ans <= n){
            ans += div;
        }
        ans = ans - div;
        div = div/10.0;
    }
    return ans;
}

int main()
{
    int n; cin>>n;
    int p; cin>>p;
    cout<<findingRoot(n, p)<<endl;
    return 0;
}