#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n,q;
int height, start_index;
vector<long long> seg_tree;

void input(){
    cin>>n>>q;

    height = (int)ceil(log2(n));
    start_index = 1 << height;

    seg_tree.resize((1<<(height+1)), 0);
}

void change_value(int node_num, long long value){
    while(node_num > 0){
        seg_tree[node_num] += value;
        node_num /= 2;
    }
}

long long get_partsum(int start, int end){
    long long partsum = 0;
    while(start <= end){
        if(start%2 != 0){
            partsum += seg_tree[start];
            start++;
        }
        if(end%2 == 0){
            partsum += seg_tree[end];
            end--;
        }
        start/=2;
        end/=2;
    }return partsum;
}

void solve(){
    input();
    for(int i = 0; i < q; i++){
        int oper, n2, n3;
        cin>>oper>>n2>>n3;

        if(oper == 1){
            n2 += start_index -1;
            change_value(n2,n3);
        }else{
            n2+=start_index-1;
            n3+=start_index-1;
            cout<<get_partsum(n2,n3)<<"\n";
        }

    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}