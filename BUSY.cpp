#include<bits/stdc++.h>
#include<vector>
using namespace std;

int pos(vector<int> &v, int j){
    auto it = find(v.begin(), v.end(), j);
    while(j < 12 && it == v.end()){
        j++;
        it = find(v.begin(), v.end(), j);
    }
    int p = -1;
    if (it != v.end())
    {
        p = it-v.begin();
    }
    return p;
}

int countActivites(vector<pair<int,int> > activities){
    int ans = 0;
    int n = activities.size();
    vector<int> v(n);
    sort(activities.begin(), activities.end());
    for(int i = 0; i < n; i++){
        v[i] = (activities[i].first);
    }
    for(int i = 0; i < n; i++){
        int position = i;
        int count = 0;
        while(position != -1 && position < n){
            count++;
            position = pos(v, activities[position].second);
       }
       ans = max(ans,count);
    }
    return ans;
}
int main()
{
    vector<pair<int,int> > activities = {{7,9},{0,10},{4,5},{8,9},{4,10},{5,7}};
    auto answer = countActivites(activities);
    cout<<answer<<endl;
    return 0;
}