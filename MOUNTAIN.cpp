// Coded by Sourav Singh
#include<bits/stdc++.h>
using namespace std;

int WidthOfMountain(vector<int> &v){
    int n = v.size();
    int result = 0;
    for(int i = 0; i < n; i++){
        if(v[i] > v[i-1] && v[i] > v[i+1]){
            int a = i;
            int b = i;
            int count = 0;
            while(v[a-1] < v[a] && a >= 1){
                count++;
                a--;
            }
            while(v[b+1] < v[b] && b <= n-2){
                count++;
                b++;
            }
            result = max(result, count + 1);
        }
    }
    return result;
}

int main()
{
    vector<int> v = {5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4};
    cout<<WidthOfMountain(v);
    return 0;
}