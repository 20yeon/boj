#include <iostream>
#include <string>

using namespace std;
//12:23:21
int main(){
    string t1, t2;
    cin>>t1>>t2;
    
    int t1_hour = (t1[0]-'0')*10+(t1[1]-'0');
    int t1_minute = (t1[3]-'0')*10+(t1[4]-'0');
    int t1_second = (t1[6]-'0')*10+(t1[7]-'0');

    int t2_hour = (t2[0]-'0')*10+(t2[1]-'0');
    int t2_minute = (t2[3]-'0')*10+(t2[4]-'0');
    int t2_second = (t2[6]-'0')*10+(t2[7]-'0');

    if(t2_second < t1_second){
        t2_second = (t2_second+60)-t1_second;
        t2_minute--;
    }else t2_second -= t1_second;

    if(t2_minute < t1_minute){
        t2_minute = (t2_minute+60)-t1_minute;
        t2_hour--;
    }else t2_minute -= t1_minute;

    if(t2_hour < t1_hour){
        t2_hour = (t2_hour+24)-t1_hour;
    }else t2_hour -= t1_hour;

    if(t2_hour < 10) cout<<0<<t2_hour<<":";
    else cout<<t2_hour<<":";
    if(t2_minute < 10) cout<<0<<t2_minute<<":";
    else cout<<t2_minute<<":";
    if(t2_second < 10) cout<<0<<t2_second;
    else cout<<t2_second;
    
    
    return 0;
}