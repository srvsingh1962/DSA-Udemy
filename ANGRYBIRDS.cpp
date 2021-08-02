// Coded by Sourav Singh
#include<bits/stdc++.h>
using namespace std;

canPlaceBirds(int b, int n, vector<int> &Nests, int mid){
    int birds = 1;
    int location = Nests[0];
    for(int i = 1; i < n-1; i++){
        int curr_location = Nests[i];
        if(curr_location - location >= mid){
            birds++;
            location = curr_location;
        }
        if(birds == b){
            return true;
        }
    }
    return false;
}

int angryBird(vector<int> &Nests, int n, int b){
    int s = 0;
    int e = Nests[n-1] - Nests[0];
    int ans = INT_MAX;
    while(s <= e){
        int mid = (s + e)/2;
        bool canPlace = canPlaceBirds(b, n, Nests, mid);
        if(canPlace){
            ans = mid;
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int n; cin>>n;
    int b; cin>>b;
    vector<int> Nests(n);
    for(int i = 0; i < n; i++){
        cin>>Nests[i];
    }
    cout<<angryBird(Nests, n, b)<<endl;
    return 0;
}