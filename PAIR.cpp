// Coded by Sourav Singh
#include<bits/stdc++.h>
using namespace std;

//Time complexity = O(N)
// To find all the pair whose sum is equal to input sum.

vector< int > pairSum(vector< int > v, int Sum){
    unordered_set<int> element;
    vector<int> result{};
    for(int i = 0; i < v.size(); i++){
        if(element.find(Sum-v[i])!=element.end()){
            result.push_back(Sum-v[i]);
            result.push_back(v[i]);
            return result;
        }
        element.insert(v[i]);
    }
    return {};
}

int main()
{
    vector<int> v = {2,7,11,15};

    int Sum; cin>>Sum;

    vector< int > p = pairSum(v, Sum);

    if(p.size() == 0){
        cout<<"No Such Pair"<<endl;
    }
    else{
        for(int i = 0; i < p.size(); i += 2){
            cout<<p[i]<<" "<<p[i+1]<<endl;
        }
    }
    return 0;
}