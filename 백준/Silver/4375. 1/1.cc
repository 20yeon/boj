#include <iostream>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        int remainder = 1 % n;  // n=1일 때 대비
        int cnt = 1;
        
        while(remainder != 0){
            remainder = (remainder * 10 + 1) % n;
            cnt++;
        }
        
        cout << cnt << endl;
    }
    return 0;
}