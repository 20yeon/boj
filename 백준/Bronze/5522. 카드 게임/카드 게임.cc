#include <iostream>

using namespace std;

long long res;

int main(){
    for(int i = 0; i < 5; i++){
        long long alpha; cin>>alpha;
         res += alpha;
    }
    cout<<res;
    return 0;
}