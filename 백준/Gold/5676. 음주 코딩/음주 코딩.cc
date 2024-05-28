#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int n,k;
int height, start_index;
vector<int> seg_tree;

void input(){
    for(int i = 0; i < n; i++) {
        int num; cin>>num;
        if(num > 0) seg_tree[i+start_index] = 1;
        else if(num < 0) seg_tree[i+start_index] = -1;
        else seg_tree[i+start_index] = 0;
    }
}
int set_tree(int node_num){
    if(node_num*2 >= seg_tree.size()) return seg_tree[node_num];
    else return seg_tree[node_num] = set_tree(node_num*2) * set_tree(node_num*2+1);
}

void change_value(int node_num, int value){
    seg_tree[node_num] = value;

    while(node_num > 1){
        node_num /= 2;
        seg_tree[node_num] = seg_tree[node_num*2] * seg_tree[node_num*2+1];
    }
}

int get_partmul(int start, int end){
    int partmul = 1;
    while(start <= end){
        if(start%2 != 0){
            partmul *= seg_tree[start];
            start++; 
        }
        if(end%2 == 0){
            partmul *= seg_tree[end];
            end--;
        }
        start/=2;
        end/=2;
    }return partmul;
}
void solve(){
    while(cin>>n>>k){
        height = (int)ceil(log2(n));
        start_index = 1<<height;

        seg_tree.resize(1<<(height+1), 0);
        input();
        set_tree(1);
        for(int i = 0; i < k; i++){
            char ch; int n1, n2;
            cin>>ch>>n1>>n2;
            if(ch == 'C'){
                n1 += start_index -1;
                if(n2 != 0) n2 = (n2 > 0) ? 1 : -1;
                change_value(n1,n2);
            }
            if(ch == 'P'){
                n1+= start_index-1;
                n2+= start_index-1;
                if(get_partmul(n1,n2) > 0) cout<<"+";
                else if(get_partmul(n1,n2) < 0) cout<<"-";
                else cout<<"0";
            }
        }cout<<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}