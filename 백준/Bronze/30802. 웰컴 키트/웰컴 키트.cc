#include<iostream>

using namespace std;

int r1;

int main(){
    int n; cin>>n;
    int size[6] = {0,0,0,0,0,0};
    
    for(int i = 0; i < 6; i++) cin>>size[i];
    int t,p; cin>>t>>p;
    for(int i = 0; i < 6; i++){
        r1 += (size[i]/t) + (((size[i]%t) != 0) ? 1 : 0);
    }
    cout<<r1<<"\n"<<n/p<<" "<<n%p;
    
    
    
    return 0;
}