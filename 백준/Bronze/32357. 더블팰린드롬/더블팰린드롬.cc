#include <iostream>

using namespace std;

int n,res = 0;

void solve(){
    cin>>n;
    for(int i = 0; i < n; i++){
        string s; cin>>s;
        int start = 0, end = s.length()-1;
        bool check = true;

        while(start < end){
            if(s[start] != s[end]) check = false;
            start++; end--;
        }
        if(check) res++;
    }
    cout<<res*(res-1);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}
