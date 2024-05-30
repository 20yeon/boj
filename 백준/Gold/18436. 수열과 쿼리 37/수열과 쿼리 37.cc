#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int n,m;
int height, start_index;
vector<pair<int, int>> seg_tree;

void input(){
    cin>>n;
    height = (int)ceil(log2(n));
    start_index = 1<<height;

    seg_tree.resize(1<<(height+1), {0,0});
    for(int i = 0; i < n; i++){
        int num; cin>>num;
        if(num%2 == 0) seg_tree[start_index+i].second++;
        else seg_tree[start_index+i].first++;
    }
}

pair<int, int> set_tree(int node_num){
    if(node_num*2 >= seg_tree.size()) return seg_tree[node_num];
    else{
        const auto [left_oddnum, left_evennum] = set_tree(node_num*2);
        const auto [right_oddnum, right_evennum] = set_tree(node_num*2+1);
        return seg_tree[node_num] = {left_oddnum+right_oddnum,left_evennum+right_evennum};
    }
}

void change_value(int node_num, int value){
    if(value%2 == 0) seg_tree[node_num] = {0,1};
    else seg_tree[node_num] = {1,0};

    while(node_num > 1){
        node_num /= 2;
        const auto [left_oddnum, left_evennum] = seg_tree[node_num*2];
        const auto [right_oddnum, right_evennum] = seg_tree[node_num*2+1];
        seg_tree[node_num] = {left_oddnum+right_oddnum, left_evennum+right_evennum};
    }
}

pair<int,int> get_partsum(int start, int end){
    pair<int, int> partsum = {0,0};

    while(start <= end){
        if(start%2 != 0){
            partsum.first += seg_tree[start].first;
            partsum.second += seg_tree[start].second;

            start++;
        }
        if(end%2 == 0){
            partsum.first += seg_tree[end].first;
            partsum.second += seg_tree[end].second;

            end--;
        }
        start/=2;
        end/=2;
    }return partsum;
}

void solve(){
    input();
    set_tree(1);

    cin>>m;
    for(int i = 0; i < m; i++){
        int oper, n1, n2;
        cin>>oper>>n1>>n2;
        if(oper == 1){
            n1+=start_index-1;
            change_value(n1,n2);
        }
        else if(oper == 2){
            n1+=start_index-1;
            n2+=start_index-1;

            cout<<get_partsum(n1,n2).second<<"\n";
        }
        else{
            n1+=start_index-1;
            n2+=start_index-1;

            cout<<get_partsum(n1,n2).first<<"\n";
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}