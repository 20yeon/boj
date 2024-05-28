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

    seg_tree.resize(1<<(height+1),{0,0});

    for(int i = 0; i < n; i++){
        int num; cin>>num;
        seg_tree[i+start_index] = {num,i};
    }
}

pair<int, int> set_tree(int node_num){
    if(node_num*2 >= seg_tree.size()) return seg_tree[node_num];
    else{
        const auto[left_value, left_value_index] = set_tree(node_num*2);
        const auto[right_value, right_value_index] = set_tree(node_num*2+1);

        if(left_value < right_value || left_value == right_value) return seg_tree[node_num] = {left_value, left_value_index};
        if(left_value > right_value) return seg_tree[node_num] = {right_value, right_value_index};
    }
}

void change_value(int node_num, int value){
    seg_tree[node_num].first = value;

    while(node_num > 0){
        node_num/=2;
        const auto[left_value, left_value_index] = seg_tree[node_num*2];
        const auto[right_value, right_value_index] = seg_tree[node_num*2+1];

        if(left_value < right_value || left_value == right_value) seg_tree[node_num] = seg_tree[node_num*2];
        if(left_value > right_value) seg_tree[node_num] = seg_tree[node_num*2+1];
    }
}
int get_min_index(int start, int end){
    int min_index = 0, min_value = 1000000001;
    
    while(start <= end){
        if(start%2 != 0){
            if(min_value > seg_tree[start].first){
                min_value = seg_tree[start].first;
                min_index = seg_tree[start].second;
            }
            if(min_value == seg_tree[start].first){
                min_index = (seg_tree[start].second < min_index) ? seg_tree[start].second : min_index;
            }
            start++;
        }
        if(end%2 == 0){
            if(min_value > seg_tree[end].first){
                min_value = seg_tree[end].first;
                min_index = seg_tree[end].second;
            }
            if(min_value == seg_tree[end].first){
                min_index = (seg_tree[end].second < min_index) ? seg_tree[end].second : min_index;
            }
            end--;
        }
        start/=2;
        end/=2;
    }
    return min_index;
}

void solve(){
    set_tree(1);
    cin>>m;
    for(int i = 0; i < m; i++){
        int oper,n1,n2;
        cin>>oper>>n1>>n2;

        if(oper == 1){
            n1+=start_index-1;
            change_value(n1,n2);
        }
        if(oper == 2){
            n1+=start_index-1;
            n2+=start_index-1;
            cout<<get_min_index(n1,n2)+1<<"\n";
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    input();
    solve();
    return 0;
}