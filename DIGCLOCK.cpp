#include<bits/stdc++.h>
using namespace std;

string convert_to_digital_time(int minutes){
    //complete this function
    int hour = minutes/60;
    minutes = minutes - hour*60;
    string hour_string;
    string min_string;
    string answer = "";
    stringstream ss1;
    ss1 << hour;
    ss1 >> hour_string;
    answer= hour_string+":";
    if(minutes < 10){
        answer += "0";
    }
    stringstream ss2;
    ss2 << minutes;
    ss2 >> min_string;
    answer += min_string;
    return answer;
}

int main()
{
    int minutes;
    cin>>minutes;
    string Time = convert_to_digital_time(minutes);
    cout<<Time<<endl;
    return 0;
}