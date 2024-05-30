#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int n,m;
int height,start_index;
vector<int>seg_tree;
vector<pair<int,int>> vertax;

void input(){
    cin>>n>>m;
    for(int i = 0; i < m; i++){
        int n1,n2; cin>>n1>>n2;
        vertax.push_back({n1,n2});
    }
    sort(vertax.begin(),vertax.end());
    

    height = (int)ceil(log2(n)); start_index = 1 << height;
    seg_tree.resize(1<<(height+1), 0);
}

void change_value(int node_num){
    seg_tree[node_num]++;
    while(node_num > 1){
        node_num/=2;
        seg_tree[node_num] = seg_tree[node_num*2]+seg_tree[node_num*2+1];
    }
}

long long get_partsum(int start, int end){
    long long partsum = 0;
    while(start <= end){
        if(start%2 != 0){
            partsum+=seg_tree[start];
            start++;
        }
        if(end%2 == 0){
            partsum+=seg_tree[end];
            end--;
        }
        start/=2;
        end/=2;
    }return partsum;
}

void solve(){
    input();
    
    long long res = 0;
    for(auto elem : vertax){
        elem.second+=start_index-1;
        change_value(elem.second);
        res+=get_partsum(elem.second+1,start_index+n-1);
    }
    cout<<res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}