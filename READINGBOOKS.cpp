// Coded by Sourav Singh
#include<bits/stdc++.h>
using namespace std;

bool canAllotBook(vector<int> &books, int n, int m, int pages){
    int students = 0;
    int readPages = 0;
    for(int i = 0; i < n; i++){
        readPages += books[i];
        if(readPages >= pages){
            students++;
            readPages = 0;
        }
        if(students == m){
            return true;
        }
    }
    return false;
}

int bookAllotment(vector<int> &books, int n, int m){
    int page = 0;
    int s = 0;
    int e;
    for(int i = 0; i < n; i++){
        e += books[i];
    }
    while(s <= e){
        int mid = (s + e)/2;
        bool canAllot = canAllotBook(books, n, m, mid);
        if(canAllot){
            ans = mid;
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    }
}

int main()
{
    int n; cin>>n;
    vector<int> books(n);
    for(int)
    int m; cin>>m;
    cout<<angryBird(Nests, n, b)<<endl;
    return 0;
}