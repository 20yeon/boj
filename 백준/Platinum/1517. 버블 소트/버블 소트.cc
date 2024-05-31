#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


int n;
int height, start_index;
vector<long long> seg_tree;
vector<pair<int, int>> li;

bool cmp(const pair<int, int>& p1, const pair<int, int>& p2){
    if(p1.second < p2.second)return true;
    else if(p1.second == p2.second){
        return p1.first < p2.first;
    }return false;
}

void press_point(){
    sort(li.begin(), li.end(), cmp);
    for(int i = 0; i < li.size(); i++){
        li[i].second = i+1;
    }
    sort(li.begin(), li.end());
}

void input(){
    cin>>n;

    height = (int)ceil(log2(n));
    start_index = 1 << height;

    seg_tree.resize(1<<(height+1), 0);
    li.resize(n);

    for(int i = 0; i  < n; i++){
        int num; cin>>num;
        li[i] = {i,num};
    }press_point();
}

void change_value(int node_num){
    seg_tree[node_num]++;

    while(node_num > 1){
        node_num /= 2;
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
    }
    return partsum;
}

void solve(){
    input();
    long long res = 0;
    for(auto elem : li){
        elem.second += start_index - 1;
        res += get_partsum(elem.second+1, n+start_index-1);
        change_value(elem.second);
    }
    cout<<res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
