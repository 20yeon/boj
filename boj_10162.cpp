#include <iostream>

using namespace std;

int a = 300,cnt_a = 0, b = 60,cnt_b = 0, c = 10,cnt_c = 0, t;

int main(){
    cin>>t;

    cnt_a += t/a;
    t %= a;
    cnt_b += t/b;
    t %= b;
    cnt_c += t/c;
    t %= c;

    if(t != 0){
        cout<<-1;
    }else{
        cout<<cnt_a<<" "<<cnt_b<<" "<<cnt_c;
    }


    return 0;
}