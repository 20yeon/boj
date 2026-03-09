#include <iostream>
#include <set>
#include <vector>

using namespace std;

set<int> A;
set<int> B;

void input(int n, set<int>& set_n){
    for(int i = 0; i < n; i++){
        int x; cin>>x;
        set_n.insert(x);
    }
}

void solve(){
    int res = 0;
    vector<int> nums;
    for (int elem : A){
        if(B.find(elem) == B.end()){
            res++;
            nums.push_back(elem);
        }
    }
    cout<<res;
    if(res != 0){
        cout<<"\n";
        for(auto elem : nums) cout<<elem<<" ";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n_a, n_b;
    cin>>n_a>>n_b;
    
    input(n_a, A);
    input(n_b, B);
    
    solve();
    return 0;
}