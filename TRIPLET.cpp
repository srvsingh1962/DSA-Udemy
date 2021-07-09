// Coded by Sourav Singh
#include<bits/stdc++.h>
using namespace std;

//Time complexity - O(NlogN + N^2) = O(N^2)

void triplets(vector<int> v, int Sum){
    
    for( int i = 0; i < v.size()-2; i++){
        
        int a = i + 1, b = v.size()-1;
        
        while(a < b){
            
            if( v[i]+v[a]+v[b] == Sum ){
                cout<<v[i]<<" "<<v[a]<<" "<<v[b]<<endl;
                break;
            }
            else if( v[i]+v[a]+v[b] < Sum ){
                a++;
            }
            else if( v[i]+v[a]+v[b] > Sum ){
                b--;
            }
        }
    }
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};

    sort( v.begin(), v.end());

    int Sum; cin>>Sum;

    triplets(v,Sum);

    return 0;
}