#include <iostream>

using namespace std;

int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin>>n;
    for(int i = 0; i < n; i++){
        string str; cin>>str;
        int res = 0;
        if(str.length() < 3) {
            cout<<res<<endl; continue;
        }
        for(int j = 0; j < str.length()-2; j++){
            if(str[j] == 'O') continue;
            else if(str[j] == 'W' && str[j+1] == 'O' && str[j+2] == 'W') res++;
        }
        cout<<res<<endl;
    }
    
    return 0;
}