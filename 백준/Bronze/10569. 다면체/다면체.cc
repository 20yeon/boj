#include <iostream>

using namespace std;

int main(){
    int T;
    cin>>T;
    for(int i = 0; i < T; i++){
        int n1, n2; cin>>n1>>n2;
        cout<<(2+n2)-n1<<endl;
    }
    return 0;
}