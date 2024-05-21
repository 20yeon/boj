#include <iostream>

using namespace std;

long long s;

int main(){
    cin>>s;

    long long n = 1;
    
    for(;!(n > s);){
        s-=n;
        n++;
    }
    cout<<n-1;
    return 0;
}
