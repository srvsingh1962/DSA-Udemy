#include<bits/stdc++.h>
using namespace std;

int binarysearch_modified(string str[], int start, int end, string find){
    while(start<=end){
        int mid = (start+end)/2;
        int mid_left = mid-1;
        int mid_right = mid+1;
        if(str[mid]==""){
            while(1){
                if(mid_left < start && mid_right > end){
                    return -1;
                }
                else if(mid_left>=start && str[mid_left]!=""){
                    mid = mid_left;
                    break;
                }
                else if(mid_right<=end && str[mid_right]!=""){
                    mid = mid_right;
                    break;
                }
                mid_left--;
                mid_right++;
            }
        }
        if(str[mid]==find){
            return mid;
        }
        else if(str[mid] > find){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int n; cin>>n;
    string str[n];
    cout<<"Enter the String in sorted way: "
    for(int i = 0; i < n; i++){
        cin>>str[i];
    }
    string find;
    sort(str, str+n);
    cin>>find;
    auto ans = binarysearch_modified(str, 0, n-1, find);
    if(ans == -1){
        cout<<"NOT FOUND"<<endl;
    }
    else{
        cout<<ans<<endl;
    }
    return 0;
}